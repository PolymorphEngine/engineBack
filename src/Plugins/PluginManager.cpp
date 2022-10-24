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
        _pluginsLoaders.emplace_back(DynamicLibLoader());
        _pluginsPath.emplace_back(pluginPath);
        _pluginsLoaders.back().loadHandler(pluginPath +"/"+ name + ".so");
        auto doc = myxmlpp::Doc(pluginPath +"/"+ name + ".pcf.plugin");
      
        auto loader = _pluginsLoaders.back().loadSymbol<Symbols::createPluginDEF>(Symbols::createPlugin);
        return std::shared_ptr<IPlugin>(loader(*doc.getRoot(), game, pluginPath));
    }

    void PluginManager::preProcessing()
    {
        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
                plugin->preUpdateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::lateUpdate()
    {

        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
                plugin->updateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::postProcessing()
    {
        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
                plugin->postUpdateInternalSystems(SceneManager::Current);
        }
    }

    void PluginManager::startingScripts()
    {
        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
                plugin->startScripts(SceneManager::Current);
        }      
    }

    void PluginManager::endingScripts()
    {
        for (auto &plugin : _plugins) {
            if (plugin->isEnabled())
                plugin->endScripts(SceneManager::Current);
        }
    }

    std::shared_ptr<IComponentInitializer> PluginManager::tryCreateComponent(std::string &type,
    Config::XmlComponent &data,
    GameObject entity)
    {
        for (auto &plugin : _plugins) {
            if (plugin->hasComponent(type))
                if (!plugin->isEnabled()) {
                    Logger::log("Plugin " + plugin->getPackageName() + " is disabled, can't create component '" + type +"'", Logger::MINOR);
                    return nullptr;
                }
            return plugin->createComponent(type, data, entity);
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


}
