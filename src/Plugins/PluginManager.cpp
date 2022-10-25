/*
** EPITECH PROJECT, 2020
** PluginManager.cpp
** File description:
** PluginManager.cpp
*/


#include <Polymorph/Plugins.hpp>
#include <Polymorph/Config.hpp>
#include "Plugins/PluginManager.hpp"


namespace Polymorph
{

    void PluginManager::loadPlugins(const std::string &pluginsPath,
                                    Config::XmlNode &list, Engine &game)
    {
        for (auto &node : list) {
            auto name = node->findAttribute("name")->getValue();
            _game.getAssetManager()->addPath(pluginsPath + "/" + name + "/Assets/");
        }
        for (auto &node : list) {
            auto name = node->findAttribute("name")->getValue();
            try {
                auto plugin = _loadPlugin(pluginsPath + name, game, name);
                _plugins.push_back(plugin);
            } catch (ExceptionLogger &e) {
                e.what();
            }
        }
    }


    std::shared_ptr<Polymorph::IPlugin> PluginManager::_loadPlugin(const std::string &pluginPath,
                                                                   Engine &game, const std::string &name)
    {
        _pluginsLoaders.emplace_back();
        _pluginsPath.emplace_back(pluginPath);
        _pluginsLoaders.back().loadHandler(pluginPath +"/"+ name + ".so");
        auto doc = myxmlpp::Doc(pluginPath +"/"+ name + ".pcf.plugin");

        auto loader = _pluginsLoaders.back().loadSymbol<Symbols::createPluginDEF>(Symbols::createPlugin);
        return std::shared_ptr<IPlugin>(loader(*doc.getRoot(), game, pluginPath));
    }
    void PluginManager::preProcessing()
    {
        
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->preUpdateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->preUpdateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }
    }

    void PluginManager::lateUpdate()
    {
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->updateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->updateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;

        }
    }

    void PluginManager::postProcessing()
    {
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->postUpdateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->postUpdateInternalSystems(SceneManager::Current);
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }
    }

    void PluginManager::startingScripts()
    {
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->startScripts(SceneManager::Current);
            if (Engine::isExiting())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->startScripts(SceneManager::Current);
            if (Engine::isExiting())
                return;
        }
    }

    void PluginManager::endingScripts()
    {
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->endScripts(SceneManager::Current);
            if (Engine::isExiting())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->endScripts(SceneManager::Current);
            if (Engine::isExiting())
                return;
        }
    }

    std::shared_ptr<IComponentInitializer> PluginManager::tryCreateComponent(std::string &type,
                                                                             Config::XmlComponent &data,
                                                                             GameObject entity)
    {
        for (auto &plugin : _plugins) {
            if (plugin->hasComponent(type))
            {
                if (!plugin->isEnabled()) {
                    Logger::log("Plugin " + plugin->getPackageName() + " is disabled, can't create component '" + type +"'", Logger::MINOR);
                    return nullptr;
                }
                return plugin->createComponent(type, data, entity);
            }
        }
        return nullptr;
    }

    std::vector<Config::XmlComponent>
    PluginManager::getTemplates()
    {
        std::vector<Config::XmlComponent> templates;

        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
            {
                auto tmp = plugin->getComponentTemplates();
                templates.insert(templates.end(), tmp.begin(), tmp.end());
            }
        }
        return templates;
    }

    GameObject PluginManager::getPrefab(const std::string &id)
    {
        for (auto &plugin : _plugins) {
            if (plugin->isEnabled() && plugin->hasPrefab(id))
            {
                auto e = plugin->getPrefabConf(id)->makeInstance(true, false);
                _prefabs.push_back(e);
                return GameObject(e);
            }
        }
        return GameObject(nullptr);
    }

    PluginManager::PluginManager(Engine &game) : _game(game) 
    {
        _pluginsOrder = _game.getPluginExecOrder();
    }

    bool PluginManager::_isPluginPrioritary(const std::string &pluginName)
    {
        for (auto &plugin : _pluginsOrder)
            if (plugin == pluginName)
                return true;
        return false;
    }

    std::shared_ptr<AssetManager>
    PluginManager::getAssetManager()
    {
        return _game.getAssetManager();
    }
}
