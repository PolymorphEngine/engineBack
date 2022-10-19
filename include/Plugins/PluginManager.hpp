/*
** EPITECH PROJECT, 2020
** PluginManager.hpp
** File description:
** header for PluginManager.c
*/

#ifndef PLUGINMANAGER_HPP
#define PLUGINMANAGER_HPP

#include "DynamicLoader/DynamicLoader.hpp"
#include "IPlugin.hpp"

namespace Polymorph
{
    
    class PluginManager
    {
        public:
            
        private:
            static inline std::vector<std::string> _pluginsPath;
            static inline std::vector<DynamicLibLoader> _pluginsLoaders;
            static inline std::vector<std::shared_ptr<IPlugin>> _plugins;
            
        public:
            static void loadPlugins(const std::string &pluginsPath, Config::XmlNode &list, Engine &game);


            template<typename symbol>
            static inline symbol getSymbol(const std::string &symbolName)
            {
                for (auto &plugin : _pluginsLoaders) {
                    auto s = plugin.loadSymbol<symbol>(symbolName, true);
                    if (s)
                        return s;
                }
                return nullptr;
            };
            
            
            static std::shared_ptr<IComponentInitializer> tryCreateComponent(std::string &type, Config::XmlComponent &data, GameObject entity);
            static void startingScripts();
            static void preProcessing();
            static void lateUpdate();
            static void postProcessing();
            static void endingScripts();
            
        private:
            static std::shared_ptr<IPlugin>
            _loadPlugin(const std::string &pluginPath,
            Engine &game, const std::string &name);

    };
}

#endif //PLUGINMANAGER_HPP
