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
    
    void PluginManager::loadPlugins(const std::string &pluginsPath, Config::XmlNode &list,
                               Engine &game)
    {
        for (auto &node : list) {
            auto name = node->findAttribute("name")->getValue();
            try {
                auto plugin = _loadPlugin(pluginsPath + "/" + name, game, name);
                _plugins.push_back(plugin);
            } catch (ExceptionLogger &e) {
                e.what();
            }
        }
    }
        
    
    std::shared_ptr<Polymorph::IPlugin> PluginManager::_loadPlugin(const std::string &pluginPath,
    Engine &game, const std::string &name)
    {
        _pluginsLoaders.emplace_back(DynamicLibLoader());
        _pluginsPath.emplace_back(pluginPath);
        _pluginsLoaders.back().loadHandler(pluginPath + "/" + name + ".so");
        auto doc = myxmlpp::Doc(pluginPath + "/" + name + ".pcf.plugin");
      
        auto loader = getSymbol<Symbols::loadPluginDEF>(Symbols::loadPlugin);
        return std::shared_ptr<IPlugin>(loader(*doc.getRoot(), game, pluginPath));
    }

    void PluginManager::preProcessing()
    {
        for (auto &plugin : _plugins) {
            plugin->preUpdateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::lateUpdate()
    {

        for (auto &plugin : _plugins) {
            plugin->updateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::postProcessing()
    {
        for (auto &plugin : _plugins) {
            plugin->postUpdateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::startingScripts()
    {
        for (auto &plugin : _plugins) {
            plugin->startScripts(SceneManager::Current);
        }      
    }

    void PluginManager::endingScripts()
    {

        for (auto &plugin : _plugins) {
            plugin->endScripts(SceneManager::Current);
        }
    }

    std::shared_ptr<IComponentInitializer> PluginManager::tryCreateComponent(std::string &type,
    Config::XmlComponent &data,
    GameObject entity)
    {
        for (auto &plugin : _plugins) {
            if (plugin->hasComponent(type))
                return plugin->createComponent(type, data, entity);
        }  
        return nullptr;
    }
}
