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
#include "Exceptions/configuration/ConfigurationException.hpp"
#include "Exceptions/configuration/MissingAttribute.hpp"

Polymorph::Engine::Engine(const std::string &filepath, const std::string &projectName)
{
    _projectPath = filepath;
    _projectName = projectName;

    Logger::SetLogDir(filepath + "/Logs");
    
    _openProject();
    _initDebugSettings();
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

    while (!_exit)
        SceneManager::Current->updateComponents();
    return _exitCode;
}

void Polymorph::Engine::Exit(ExitCode code = 0)
{
    _exitCode = code;
    _exit = true;
}



void Polymorph::Engine::_openProject()
{
    try
    {
        _projectConfig = std::make_unique<myxmlpp::Doc>(_projectPath + "/" + _projectName + ".pcf");
        std::shared_ptr<myxmlpp::Node> n = _projectConfig->getRoot();
        std::shared_ptr<myxmlpp::Node> settings = n->findChild("EngineSettings");
        std::shared_ptr<myxmlpp::Node> scenes = n->findChild("Scenes");
    }
    catch (myxmlpp::NodeNotFoundException &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
    catch (myxmlpp::AttributeNotFoundException &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
    catch (myxmlpp::ParsingException &e) {
        throw ConfigurationException(std::string(e.what()), Logger::MAJOR);
    }
}

void Polymorph::Engine::_initExectutionOrder()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try
    {
        bool foundDefault = false;
        auto execOrder =settings->findChild("ComponentExecutionOrder");

        for (auto &type : *execOrder)
        {
            auto t = type->findAttribute("value")->getValue();
            if (t == "Default")
                foundDefault = true;
            _execOrder.push_back(t);
        }
        if (!foundDefault)
            throw MissingAttribute("Default", "ComponentExecLayer", Logger::MAJOR);
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initLayers()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try
    {
        auto execOrder = settings->findChild("Layers");

        for (auto &type : *execOrder)
        {
            auto t = type->findAttribute("value")->getValue();
            _layers.push_back(t);
        }
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initDebugSettings()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try
    {
        auto debug = settings->findChild("Debug");
        
        if (debug->findAttribute("enabled")->getValueBool("True", "False"))
            Logger::InitLogInstance(Logger::DEBUG_MODE);
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MINOR);
    }
}

void Polymorph::Engine::_initGameData()
{

    try
    {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Prefabs");
        
        for (auto &prefab: *prefabs)
        {
            try
            {
                _prefabs.emplace_back(Config::XmlEntity(prefab, *this, _projectPath));
            }
            catch (...)
            {
                Logger::Log("Error loading prefab", Logger::MINOR);
            }
        }
    }
    catch (myxmlpp::Exception &e)
    {
        Logger::Log("Error loading prefabs data in main config file", Logger::MINOR);
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

void Polymorph::Engine::addScene(const std::shared_ptr<Scene>& scene) {
    _scenes.push_back(scene);
}

std::vector<Polymorph::Config::XmlEntity> Polymorph::Engine::getPrefabs()
{
    return _prefabs;
}

std::vector<Polymorph::Config::XmlComponent> Polymorph::Engine::getDefaultConfigs()
{
    return _defaultConfigs;
}
