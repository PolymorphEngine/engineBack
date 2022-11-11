/*
** EPITECH PROJECT, 2020
** PluginManager.cpp
** File description:
** PluginManager.cpp
*/


#include <polymorph/Plugins.hpp>
#include <polymorph/Config.hpp>
#include "Plugins/PluginManager.hpp"
#include "ScriptingAPI/ScriptingApi.hpp"


namespace polymorph::engine
{

    void PluginManager::loadPlugins(const std::string &pluginsPath,
                                    Config::XmlNode &list, Engine &game)
    {
        _pluginsOrder = _game.getPluginExecOrder();
        for (auto &node : list) {
            auto name = node->findAttribute("name")->getValue();
            _game.getAssetManager().addPath(pluginsPath + "/" + name + "/Assets/");
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


    std::shared_ptr<polymorph::engine::IPlugin> PluginManager::_loadPlugin(const std::string &pluginPath,
                                                                   Engine &game, const std::string &name)
    {
        _pluginsLoaders.emplace_back();
        _pluginsPath.emplace_back(pluginPath);
#ifdef _WIN32
        _pluginsLoaders.back().loadHandler(pluginPath +"/"+ name + ".dll");
#else
        _pluginsLoaders.back().loadHandler(pluginPath +"/"+ name + ".so");
#endif
        auto doc = myxmlpp::Doc(pluginPath +"/"+ name + ".pcf.plugin");

        auto loader = _pluginsLoaders.back().loadSymbol<Symbols::createPluginDEF>(Symbols::createPlugin);
        return std::shared_ptr<IPlugin>(loader(*doc.getRoot(), game, pluginPath));
    }
    void PluginManager::preProcessing()
    {
        auto c = _game.getSceneManager().getCurrentScene();
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->preUpdateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->preUpdateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;
        }
    }

    void PluginManager::lateUpdate()
    {
        auto c = _game.getSceneManager().getCurrentScene();
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->updateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->updateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;

        }
    }

    void PluginManager::postProcessing()
    {
        auto c = _game.getSceneManager().getCurrentScene();
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->postUpdateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->postUpdateInternalSystems(c);
            if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                return;
        }
    }

    void PluginManager::startingScripts()
    {
        auto c = _game.getSceneManager().getCurrentScene();
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->startScripts(c);
            if (_game.isExiting())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->startScripts(c);
            if (_game.isExiting())
                return;
        }
    }

    void PluginManager::endingScripts()
    {
        auto c = _game.getSceneManager().getCurrentScene();
        for (auto &plugin : _pluginsOrder) {
            auto res = std::find_if(_plugins.begin(), _plugins.end(), [&plugin](const auto &p) {
                return p->getPackageName() == plugin;});
            if (res != _plugins.end() && (*res)->isEnabled())
                (*res)->endScripts(c);
            if (_game.isExiting())
                return;
        }

        for (auto &plugin : _plugins) {
            if (!_isPluginPrioritary(plugin->getPackageName()) && plugin->isEnabled())
                plugin->endScripts(c);
            if (_game.isExiting())
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
                    entity->Debug.log("Plugin " + plugin->getPackageName() + " is disabled, can't create component '" + type +"'", Logger::MINOR);
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
    }

    bool PluginManager::_isPluginPrioritary(const std::string &pluginName)
    {
        for (auto &plugin : _pluginsOrder)
            if (plugin == pluginName)
                return true;
        return false;
    }

    AssetManager &
    PluginManager::getAssetManager()
    {
        return _game.getAssetManager();
    }

    std::shared_ptr<ASerializableObject>
    PluginManager::tryCreateSharedObject(std::string &type,
                                         Config::XmlComponent &manager,
                                         std::shared_ptr<Config::XmlNode> &data,
                                         PluginManager &Plugins)
    {
        for (auto &plugin : _plugins) {
            if (plugin->hasObject(type))
            {
                if (!plugin->isEnabled())
                    throw ExceptionLogger("Plugin " + plugin->getPackageName() + " is disabled, can't create object '" + type +"'", Logger::MAJOR);
                return plugin->createSharedObject(type, manager, data, Plugins);
            }
        }
        throw ExceptionLogger("No plugin found for object '" + type + "'", Logger::MAJOR);
    }

    std::shared_ptr<ASerializableObject>
    PluginManager::tryEmptyCreateSharedObject(std::string &type,
                                              PluginManager &Plugins)
    {
        for (auto &plugin : _plugins) {
            if (plugin->hasObject(type))
            {
                if (!plugin->isEnabled())
                    throw ExceptionLogger("Plugin " + plugin->getPackageName() + " is disabled, can't create object '" + type +"'", Logger::MAJOR);
                return plugin->createEmptySharedObject(type, Plugins);
            }
        }
        throw ExceptionLogger("No plugin found for object '" + type + "'", Logger::MAJOR);
    }
}
