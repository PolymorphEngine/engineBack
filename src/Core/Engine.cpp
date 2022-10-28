/*
** EPITECH PROJECT, 2020
** polymorph.cpp.cc
** File description:
** header for polymorph.c
*/

#include <polymorph/Core.hpp>
#include <polymorph/Settings.hpp>
#include <polymorph/Config.hpp>
#include <polymorph/Debug.hpp>
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Core/Engine.hpp"


polymorph::engine::Engine::Engine(std::string projectName, const std::string &projectPath, std::string pluginPath)
: _projectPath(projectPath), _projectName(std::move(projectName)), _pluginsPath(pluginPath),
  _pluginManager(*this), _sceneManager(*this)
{
    _assetManager = AssetManager();
    _assetManager.addPath(_projectPath);
    _logger = Logger();
    
#ifdef _WIN32
    _logger.setLogDir(projectPath + "\\Logs");
#else
    _logger.setLogDir(projectPath + "/Logs");
#endif
    _openProject();

    _initDebugSettings();
    _initVideoSettings();
    _initAudioSettings();
    _initPhysicSettings();

    _initExectutionOrder();
    _initPluginsExectutionOrder();
    _initLayers();
}

int polymorph::engine::Engine::run()
{
    _time = Time();
    _pluginManager.startingScripts();
    if (isExiting())
        return _exitCode;
    _sceneManager.getCurrentScene()->loadScene();
    while (!_exit) {
        _time.computeDeltaTime();
        _sceneManager.resetLoading();
        _pluginManager.preProcessing();
        if (isExiting() || _sceneManager.isSceneUnloaded())
            continue;
        _sceneManager.getCurrentScene()->updateComponents();
        if (isExiting() || _sceneManager.isSceneUnloaded())
            continue;
        _pluginManager.lateUpdate();
        if (isExiting() || _sceneManager.isSceneUnloaded())
            continue;
        _pluginManager.postProcessing();
        if (isExiting() || _sceneManager.isSceneUnloaded())
            continue;
    }
    _pluginManager.endingScripts();
    return _exitCode;
}

void polymorph::engine::Engine::exit(ExitCode code = 0)
{
    _exitCode = code;
    _exit = true;
}

void polymorph::engine::Engine::_openProject()
{
    try {
        _projectConfig = std::make_unique<myxmlpp::Doc>(_projectPath + "/" + _projectName + ".pcf.engine");
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

void polymorph::engine::Engine::_initExectutionOrder()
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


void polymorph::engine::Engine::_initLayers()
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


void polymorph::engine::Engine::_initDebugSettings()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try {
        auto debug = settings->findChild("Debug");
        isDebugSession = debug->findAttribute("enabled")->getValueBool("true", "false");

        if (isDebugSession)
            _logger.initLogInstance(Logger::DEBUG_MODE);
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MINOR);
    }
}

void polymorph::engine::Engine::_initGameData()
{

    std::shared_ptr<myxmlpp::Node> scenes = _projectConfig->getRoot()->findChild("Scenes");

    if (scenes->empty())
        throw ConfigurationException("No scenes found to build", Logger::MAJOR);

    for (auto &scene : *scenes)
        _scenes.push_back(std::make_shared<polymorph::engine::Scene>(scene, *this));

}

std::string polymorph::engine::Engine::getProjectPath()
{
    return _projectPath;
}

polymorph::engine::Engine::~Engine() = default;

std::shared_ptr<polymorph::engine::Scene>
polymorph::engine::Engine::findSceneByName(const std::string& name)
{
    for (auto & _scene : _scenes) {
        if (_scene->name == name)
            return _scene;
    }
    return nullptr;
}

std::shared_ptr<polymorph::engine::Scene>
polymorph::engine::Engine::findSceneById(const std::string& id)
{
    for (auto & _scene : _scenes) {
        if (_scene->id == id)
            return _scene;
    }
    return nullptr;
}

void polymorph::engine::Engine::addScene(const std::shared_ptr<Scene>& scene)
{
    _scenes.push_back(scene);
}

void polymorph::engine::Engine::_initPhysicSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/PhysicsSettings");

    _physicsSettings = std::make_unique<Settings::PhysicsSettings>(node);
}

void polymorph::engine::Engine::_initAudioSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/AudioSettings");

    _audioSettings = std::make_unique<Settings::AudioSettings>(node);
}

void polymorph::engine::Engine::_initVideoSettings()
{
    auto node = _projectConfig->getRoot()->findChildBySPath("EngineSettings/VideoSettings");

    _videoSettings = std::make_shared<Settings::VideoSettings>(node);
}


std::vector<std::shared_ptr<polymorph::engine::Entity>> polymorph::engine::Engine::getPrefabs()
{
    return _prefabs;
}

std::vector<polymorph::engine::Config::XmlComponent> polymorph::engine::Engine::getDefaultConfigs()
{
    return _defaultConfigs;
}

polymorph::engine::Config::XmlComponent &polymorph::engine::Engine::getDefaultConfig(const std::string& type)
{
    for (auto &c: _defaultConfigs) {
        if (c.getType() == type)
            return c;
    }
    _logger.log("No default config available for type '"+type+"'.", Logger::DEBUG);
    return *Config::XmlComponent::Empty;
}


void polymorph::engine::Engine::loadEngine()
{
    try {
        auto p = _projectConfig->getRoot()->findChild("Plugins");
        if (p)
            _pluginManager.loadPlugins(_pluginsPath, *p, *this);
        else
            _logger.log("[Plugins] No plugins found in project config.", Logger::MINOR);
    } catch (ExceptionLogger &e) {
        e.what();
    }
    _initTemplates();
    _initPrefabs();
    _initGameData();

    if (_scenes.empty())
        throw std::runtime_error("No scenes built");
    _sceneManager.setCurrentScene(*_scenes.begin());
}

void polymorph::engine::Engine::_initPrefabs()
{

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Prefabs");

        for (auto &prefab: *prefabs) {
            try {
                _prefabsConfigs.push_back(std::make_shared<Config::XmlEntity>(prefab, *this, _projectPath));
                _prefabs.push_back(_prefabsConfigs.back()->makeInstance(false, true));
            } catch (myxmlpp::Exception &e) {
                _logger.log("[Configuration] Error loading prefab." + e.baseWhat(), Logger::MINOR);
            } catch (ExceptionLogger &e) {
                e.what();
            }
        }
    } catch (myxmlpp::NodeNotFoundException &e) {
        _logger.log("[Configuration] Error loading prefabs: no prefabs to load." + e.baseWhat(),
                    Logger::MINOR);
    }catch (myxmlpp::Exception &e) {
        _logger.log("[Configuration] Error loading prefabs: " + e.baseWhat(),
                    Logger::MINOR);
    } catch (ExceptionLogger &e) {
        e.what();
    }

}

void polymorph::engine::Engine::_initTemplates()
{

    try {
        std::shared_ptr<myxmlpp::Node> prefabs = _projectConfig->getRoot()->findChild("Templates");

        for (auto &prefab: *prefabs) {
            try
            {
                auto path = _projectPath + "/" +
                            prefab->findAttribute("path")->getValue();
#ifdef _WIN32
                std::replace(path.begin(), path.end(), '/', '\\');
#endif
                auto templateDoc = myxmlpp::Doc(path);
                _defaultConfigs.emplace_back(
                        Config::XmlComponent(templateDoc.getRoot()));
                } catch (myxmlpp::Exception &e) {
                    _logger.log("[Configuration] Error template: " + e.baseWhat(),
                                Logger::MINOR);
                } catch (ExceptionLogger &e) {
                    e.what();
                } catch (std::exception &e) {
                    _logger.log("[Unknown] Error loading template: \n" + std::string(e.what()),
                                Logger::MINOR);
                }
        }
    } catch (myxmlpp::NodeNotFoundException &e) {
        _logger.log("[Configuration] Error loading components templates: no templates to load." + e.baseWhat(),
                    Logger::MINOR);
    } catch (myxmlpp::Exception &e) {
        _logger.log("[Configuration] Error loading components templates: " + e.baseWhat(),
                    Logger::MINOR);
    } catch (ExceptionLogger &e) {
        e.what();
    } catch (std::exception &e) {
        _logger.log("[Unknown] Error loading components templates: \n" + std::string(e.what()),
                    Logger::MINOR);
    }
    auto tmp = _pluginManager.getTemplates();
    _defaultConfigs.insert(_defaultConfigs.end(), tmp.begin(), tmp.end());

}

void polymorph::engine::Engine::setWindowLessMode()
{
    isWindowlessSession = true;
}

bool polymorph::engine::Engine::isWindowLessSession()
{
    return isWindowlessSession;
}

bool polymorph::engine::Engine::isDebugMode()
{
    return isDebugSession;
}

void polymorph::engine::Engine::loadScriptingAPI(std::unique_ptr<IScriptFactory> scriptFactory)
{
    _scriptingApi = ScriptingApi(std::move(scriptFactory));
}

void polymorph::engine::Engine::_initPluginsExectutionOrder()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try {
        auto execOrder =settings->findChild("PluginsExecutionOrder");

        for (auto &type : *execOrder) {
            auto t = type->findAttribute("value")->getValue();
            _pluginsExecOrder.push_back(t);
        }
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}

std::string polymorph::engine::Engine::getTitle()
{
    return _projectName;
}

std::shared_ptr<polymorph::engine::Settings::VideoSettings> polymorph::engine::Engine::getVideoSettings()
{
    return _videoSettings;
}

polymorph::engine::PluginManager &polymorph::engine::Engine::getPluginManager()
{
    return _pluginManager;
}
