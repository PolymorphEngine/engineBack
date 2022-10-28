/*
** EPITECH PROJECT, 2020
** PluginManager.hpp
** File description:
** header for PluginManager.c
*/

#ifndef PLUGINMANAGER_HPP
#define PLUGINMANAGER_HPP

#include "IPlugin.hpp"
#include "DynamicLoader.hpp"
#include "AssetManager.hpp"

namespace polymorph::engine
{
    
    
    class PluginManager
    {
        public:
            explicit PluginManager(Engine &game);
            
        private:
            std::vector<std::string> _pluginsPath;
            std::vector<DynamicLibLoader> _pluginsLoaders;
            std::vector<std::shared_ptr<IPlugin>> _plugins;
            std::vector<std::shared_ptr<Entity>> _prefabs;
            std::vector<std::string> _pluginsOrder;
            Engine &_game;

        public:
            void loadPlugins(const std::string &pluginsPath, Config::XmlNode &list, Engine &game);
            AssetManager & getAssetManager();


            template<typename symbol>
            inline symbol getSymbol(const std::string &symbolName)
            {
                for (auto &plugin : _pluginsLoaders) {
                    auto s = plugin.loadSymbol<symbol>(symbolName, true);
                    if (s)
                        return s;
                }
                return nullptr;
            };
            
            
            std::shared_ptr<IComponentInitializer> tryCreateComponent(std::string &type, Config::XmlComponent &data, GameObject entity);
            std::vector<Config::XmlComponent> getTemplates();
            GameObject getPrefab(const std::string &id);
            void startingScripts();
            void preProcessing();
            void lateUpdate();
            void postProcessing();
            void endingScripts();
            
        private:
            bool _isPluginPrioritary(const std::string &pluginName);
            
            
            std::shared_ptr<IPlugin>
            _loadPlugin(const std::string &pluginPath,
            Engine &game, const std::string &name);

    };
}

#endif //PLUGINMANAGER_HPP
