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
#include "PhysicsSettings.hpp"
#include "AudioSettings.hpp"
#include "VideoSettings.hpp"


namespace Polymorph
{
    namespace Config{class XmlEntity;class XmlComponent;}
    class Scene;
    using ExitCode = int;

    /**
     * @class Engine Main container class that holds all game data such as :
     *        Scenes, Prefabs, Configuration files, Settings
     */
    class Engine
    {
        public:
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            explicit Engine(const std::string &filepath, const std::string &projectName);
            ~Engine();
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            std::vector<std::shared_ptr<Scene>> _scenes;
            std::vector<Config::XmlEntity> _prefabs;
            std::vector<Config::XmlComponent> _defaultConfigs;

            std::vector<std::string> _layers;
            std::vector<std::string> _execOrder;
            bool _exit = false;
            ExitCode _exitCode = 0;

            std::string _projectPath;
            std::string _projectName;
            std::unique_ptr<myxmlpp::Doc> _projectConfig;

            std::unique_ptr<Settings::PhysicsSettings> _physicsSettings;
            std::unique_ptr<Settings::AudioSettings> _audioSettings;
            std::unique_ptr<Settings::VideoSettings> _videoSettings;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
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

            void exit(ExitCode code);

            std::string getProjectPath();

            std::vector<Config::XmlEntity> getPrefabs();

            std::vector<Config::XmlComponent> getDefaultConfigs();

            Config::XmlComponent &getDefaultConfig(std::string type);



            /**
             * @details Find a scene by its name, returns the first matched
             * @param name the name of the scene to find
             * @return the required scene
             */
            std::shared_ptr<Scene> findSceneByName(const std::string& name);

            /**
             * @details Find a scene by its id, returns the first matched
             * @param id the name of the scene to find
             * @return the required scene
             */
            std::shared_ptr<Scene> findSceneById(std::string id);

            /**
             * Add the provided scene to the engine's scenes list
             * @param scene the scene to add
             */
            void addScene(const std::shared_ptr<Scene>& scene);


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
//////////////////////--------------------------/////////////////////////

    };
}


#endif //ENGINE_ENGINE_HPP
