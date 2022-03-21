/*
** EPITECH PROJECT, 2020
** Polymorph.cpp.cc
** File description:
** header for Polymorph.c
*/

#include "XmlEntity.hpp"
#include "SceneManager.hpp"
#include "Engine.hpp"
#include "Scene.hpp"
#include "Log/Logger.hpp"
#include <myxmlpp.hpp>
#include "ConfigurationException.hpp"
#include "GraphicalAPI/Display.hpp"
#include "GraphicalException.hpp"

Polymorph::Engine::Engine(const std::string &filepath, const std::string &projectName, const std::string &libPath)
{
    _projectPath = filepath;
    _projectName = projectName;

    
    try
    {
        _graphicalLoader = std::make_unique<DynamicLibLoader>();
        _graphicalLoader->loadHandler(libPath);
    } catch (std::exception &e) {
        e.what();
    }
    Logger::setLogDir(filepath + "/Logs");
    _openProject();
    _initDebugSettings();
    _initVideoSettings();
    try {
        _display = std::make_unique<Display>(_videoSettings, projectName);
    } catch (GraphicalException &e) {
        e.what();
    }

    _initExectutionOrder();
    _initLayers();
    _initGameData();


    if (_scenes.empty())
        throw std::runtime_error("No scenes built");
    SceneManager::Current = *_scenes.begin();
    //SceneManager::Game = game;
    //Application::Game = game;
}

int Polymorph::Engine::run()
{
    SceneManager::Current->loadScene();

    while (!_exit && (_display && _display->isOpen())
    || !_display && !_exit)
    {
        if (_display) {
            _display->fetchEvents();
            _display->clearWindow();
        }
        SceneManager::Current->updateComponents();
        if (_display) {
            _display->displayWindow();
        }
    }
    return _exitCode;
}

void Polymorph::Engine::exit(ExitCode code = 0)
{
    _exitCode = code;
    _exit = true;
}



void Polymorph::Engine::_openProject()
{
    try {
        _projectConfig = std::make_unique<myxmlpp::Doc>(_projectPath + "/" + _projectName + ".pcf");
        std::shared_ptr<myxmlpp::Node> n = _projectConfig->getRoot();
        std::shared_ptr<myxmlpp::Node> settings = n->findChild("EngineSettings");
        std::shared_ptr<myxmlpp::Node> scenes = n->findChild("Scenes");
    } catch (myxmlpp::NodeNotFoundException &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    } catch (myxmlpp::ParsingException &e) {
        throw ConfigurationException(std::string(e.what()), Logger::MAJOR);
    }
}

void Polymorph::Engine::_initExectutionOrder()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try {
        bool foundDefault = false;
        auto execOrder =settings->findChild("ComponentExecutionOrder");

        for (auto &type : *execOrder) {
            auto t = type->findAttribute("value")->getValue();
            if (t == "Default")
                foundDefault = true;
            _execOrder.push_back(t);
        }
        if (!foundDefault)
            throw ConfigurationException("Default layer order missing !", Logger::MAJOR);
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initLayers()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try {
        auto execOrder = settings->findChild("Layers");

        for (auto &type : *execOrder) {
            auto t = type->findAttribute("value")->getValue();
            _layers.push_back(t);
        }
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initDebugSettings()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try {
        auto debug = settings->findChild("Debug");

        if (debug->findAttribute("enabled")->getValueBool("True", "False"))
            Logger::initLogInstance(Logger::DEBUG_MODE);
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MINOR);
    }
}

void Polymorph::Engine::_initGameData()
{

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Prefabs");

        for (auto &prefab: *prefabs) {
            try {
                _prefabs.emplace_back(Config::XmlEntity(prefab, *this, _projectPath));
            } catch (...) {
                Logger::log("Error loading prefab", Logger::MINOR);
            }
        }
    } catch (myxmlpp::Exception &e) {
        Logger::log("Error loading prefabs data in main config file",
                    Logger::MINOR);
    }

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Templates");

        for (auto &prefab: *prefabs) {
            try {
                auto path = _projectPath + "/" + prefab->findAttribute("path")->getValue();
                auto templateDoc = myxmlpp::Doc(path);
                _defaultConfigs.emplace_back(Config::XmlComponent(templateDoc.getRoot()));
            } catch (...) {
                Logger::log("Error loading component template", Logger::MINOR);
            }
        }
    } catch (myxmlpp::Exception &e) {
        Logger::log("Error loading templates data in main config file",
                    Logger::MINOR);
    }

    std::shared_ptr<myxmlpp::Node> scenes = _projectConfig->getRoot()->findChild("Scenes");

    if (scenes->empty())
        throw ConfigurationException("No scenes found to build", Logger::MAJOR);

    for (auto &scene : *scenes)
        _scenes.push_back(std::make_shared<Polymorph::Scene>(scene, *this));

}

std::string Polymorph::Engine::getProjectPath()
{
    return _projectPath;
}

Polymorph::Engine::~Engine()
{
    std::cout << "Its a temporary leak ..." << std::endl;
}

std::shared_ptr<Polymorph::Scene>
Polymorph::Engine::findSceneByName(const std::string& name)
{
    for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
        if ((*it)->name == name)
            return *it;
    }
    return nullptr;
}

std::shared_ptr<Polymorph::Scene>
Polymorph::Engine::findSceneById(std::string id)
{
    for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
        if ((*it)->id == id)
            return *it;
    }
    return nullptr;
}

void Polymorph::Engine::addScene(const std::shared_ptr<Scene>& scene)
{
    _scenes.push_back(scene);
}

void Polymorph::Engine::_initPhysicSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/PhysicsSettings");

    _physicsSettings = std::make_unique<Settings::PhysicsSettings>(node);
}

void Polymorph::Engine::_initAudioSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/AudioSettings");

    _audioSettings = std::make_unique<Settings::AudioSettings>(node);
}

void Polymorph::Engine::_initVideoSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/VideoSettings");

    _videoSettings = std::make_shared<Settings::VideoSettings>(node);
}


std::vector<Polymorph::Config::XmlEntity> Polymorph::Engine::getPrefabs()
{
    return _prefabs;
}

std::vector<Polymorph::Config::XmlComponent> Polymorph::Engine::getDefaultConfigs()
{
    return _defaultConfigs;
}

Polymorph::Config::XmlComponent &Polymorph::Engine::getDefaultConfig(std::string type)
{
    for (auto &c: _defaultConfigs) {
        if (c.getType() == type)
            return c;
    }
    throw ExceptionLogger("Tried to get a default config of an unknown component type", Logger::MAJOR);
}
