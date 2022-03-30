/*
** EPITECH PROJECT, 2020
** Polymorph.cpp.cc
** File description:
** header for Polymorph.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Settings.hpp>
#include <Polymorph/Types.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Debug.hpp>
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Engine.hpp"


Polymorph::Engine::Engine(const std::string &projectPath, std::string projectName): _projectPath(projectPath), _projectName(std::move(projectName))
{
    Logger::setLogDir(projectPath + "/Logs");
    _openProject();
    _initDebugSettings();

    _initVideoSettings();
    _initAudioSettings();
    _initPhysicSettings();

    _initExectutionOrder();
    _initLayers();
    _initTemplates();
    _initPrefabs();
}

int Polymorph::Engine::run()
{
    if (!!_display)
        GraphicalAPI::CurrentDisplay = (*_display).get();

    SceneManager::Current->loadScene();

    _time = Time();
    while ((!_exit && (!!_display && _display->isOpen()))
    || (!_display && !_exit))
    {
        if (!!_display)
            GraphicalAPI::CurrentDisplay = (*_display).get();

        _time.computeDeltaTime();

        if (!!_display) {
            _display->fetchEvents();
            _display->clearWindow();
        }

        SceneManager::Current->updateComponents();

        if (!!_display) {
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
}

std::shared_ptr<Polymorph::Scene>
Polymorph::Engine::findSceneByName(const std::string& name)
{
    for (auto & _scene : _scenes) {
        if (_scene->name == name)
            return _scene;
    }
    return nullptr;
}

std::shared_ptr<Polymorph::Scene>
Polymorph::Engine::findSceneById(const std::string& id)
{
    for (auto & _scene : _scenes) {
        if (_scene->id == id)
            return _scene;
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


std::vector<std::shared_ptr<Polymorph::Entity>> Polymorph::Engine::getPrefabs()
{
    return _prefabs;
}

std::vector<Polymorph::Config::XmlComponent> Polymorph::Engine::getDefaultConfigs()
{
    return _defaultConfigs;
}

Polymorph::Config::XmlComponent &Polymorph::Engine::getDefaultConfig(const std::string& type)
{
    for (auto &c: _defaultConfigs) {
        if (c.getType() == type)
            return c;
    }
    Logger::log("No default config available for type '"+type+"'.", Logger::DEBUG);
    return *Config::XmlComponent::Empty;
}

void Polymorph::Engine::loadGraphicalAPI(const std::string& graphicalLibPath)
{
    try
    {
        _graphicalApi = std::make_unique<GraphicalAPI>(graphicalLibPath);
        _graphicalApi->reloadAPI(graphicalLibPath);
        _display = _graphicalApi->createDisplay(_videoSettings, _projectName);
    } catch (GraphicalException &e) {
        e.what();
    } catch (std::exception &e) {
        Logger::log("[Graphical API] " + std::string(e.what()), Logger::MAJOR);
    }

}

void Polymorph::Engine::loadScriptingAPI(
        std::unique_ptr<IScriptFactory> scriptFactory)
{
    try {
        _scriptingApi = std::make_unique<ScriptingApi>(std::move(scriptFactory));
    } catch (ExceptionLogger &e) {
        e.what();
    } catch (std::exception &e) {
        Logger::log("[Scripting API]: " + std::string(e.what()), Logger::MAJOR);
    }
}

void Polymorph::Engine::loadEngine()
{
    _initGameData();

    if (_scenes.empty())
        throw std::runtime_error("No scenes built");
    SceneManager::Current = *_scenes.begin();
}

void Polymorph::Engine::_initPrefabs()
{

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Prefabs");

        for (auto &prefab: *prefabs) {
            try {
                _prefabsConfigs.push_back(std::make_shared<Config::XmlEntity>(prefab, *this, _projectPath));
                _prefabs.push_back(_prefabsConfigs.back()->makeInstance());
            } catch (myxmlpp::Exception &e) {
                Logger::log("[Configuration] Error loading prefab." + e.baseWhat(), Logger::MINOR);
            } catch (ExceptionLogger &e) {
                e.what();
            } catch (std::exception &e) {
                Logger::log("[Unknown] Error loading prefab\n" + std::string(e.what()), Logger::MINOR);
            }
        }
    } catch (myxmlpp::NodeNotFoundException &e) {
        Logger::log("[Configuration] Error loading prefabs: no prefabs to load." + e.baseWhat(),
                    Logger::MINOR);
    }catch (myxmlpp::Exception &e) {
        Logger::log("[Configuration] Error loading prefabs: " + e.baseWhat(),
                    Logger::MINOR);
    } catch (ExceptionLogger &e) {
        e.what();
    } catch (std::exception &e) {
        Logger::log("[Unknown] Error loading prefabs data in main config file.\n" + std::string(e.what()),
                    Logger::MINOR);
    }

}

void Polymorph::Engine::_initTemplates()
{

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Templates");

        for (auto &prefab: *prefabs) {
            try
            {
                auto path = _projectPath + "/" +
                            prefab->findAttribute("path")->getValue();
                auto templateDoc = myxmlpp::Doc(path);
                _defaultConfigs.emplace_back(
                        Config::XmlComponent(templateDoc.getRoot()));
                } catch (myxmlpp::Exception &e) {
                    Logger::log("[Configuration] Error template: " + e.baseWhat(),
                                Logger::MINOR);
                } catch (ExceptionLogger &e) {
                    e.what();
                } catch (std::exception &e) {
                    Logger::log("[Unknown] Error loading template: \n" + std::string(e.what()),
                                Logger::MINOR);
                }
        }
    } catch (myxmlpp::NodeNotFoundException &e) {
        Logger::log("[Configuration] Error loading components templates: no templates to load." + e.baseWhat(),
                    Logger::MINOR);
    } catch (myxmlpp::Exception &e) {
        Logger::log("[Configuration] Error loading components templates: " + e.baseWhat(),
                    Logger::MINOR);
    } catch (ExceptionLogger &e) {
        e.what();
    } catch (std::exception &e) {
        Logger::log("[Unknown] Error loading components templates: \n" + std::string(e.what()),
                    Logger::MINOR);
    }


}
