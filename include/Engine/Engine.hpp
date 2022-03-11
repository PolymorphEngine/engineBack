/*
** EPITECH PROJECT, 2020
** Polymorph.hpp.h
** File description:
** header for Polymorph.c
*/

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <map>
#include <iostream>
#include <myxmlpp.hpp>
#include <memory>
#include <vector>
#include "Entity.hpp"


namespace Polymorph
{
    namespace Config{class XmlEngine{};}
    class Scene;

    /**
     * @class Main container class that holds all game data such as :
     *        Scenes, Prefabs, Configuration files, Settings
     */
    class Engine
    {
    public:
        explicit Engine(const std::string &filepath, const std::string &projectName);

    private:
        using ExitCode = int;
        std::vector<std::shared_ptr<Scene>> _scenes;
        
        
        std::vector<Config::XmlEntity> _prefabs;
        std::vector<Config::XmlComponent> _defaultConfigs;
        
        std::vector<std::string> _layers;
        std::vector<std::string> _execOrder;
        Config::XmlEngine _data;
        bool _exit = false;
        ExitCode _exitCode = 0;
        
        std::string _projectPath;
        std::string _projectName;
        std::unique_ptr<myxmlpp::Doc> _projectConfig;

        public:
            /**
             * @details Getter that fetches the ordered vector of component types.
             *          Order determines which component has to be updated before others.
             * @returns A vector of std::string ordered based on execution order.
             */
            std::vector<std::string> &getExecOrder(){return _execOrder;};

            /**
             * @details Runs the game.
             */
            int run();
            
            void Exit(ExitCode code);
            
        private:
            /**
             * @details Opens the project configuration 
             */
            void _openProject();

            /**
             * @details Inits the execution order informations of components at runtime 
             */
            void _initExectutionOrder();
            
            /**
             * @details Inits the layer types  for game objects
             */
            void _initLayers();

            /**
             * @details Inits the physics settings of the engine
             */
            void _initPhysicSettings();

            /**
             * @details Inits the audio settings of the engine
             */
            void _initAudioSettings();

            /**
             * @details Inits the video settings of the engine
             */
            void _initVideoSettings();

            /**
             * @details Inits the debug settings of the engine
             */
            void _initDebugSettings();
            
            /**
             * @details Inits the game data
             */
            void _initGameData();
    };
}


#endif //ENGINE_ENGINE_HPP
