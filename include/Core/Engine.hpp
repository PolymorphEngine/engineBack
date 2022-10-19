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

#include "Utilities/safe_ptr.hpp"
#include "Utilities/Time.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"


namespace Polymorph
{
    namespace Config
    {
        class XmlEntity;

        class XmlComponent;
    }
    namespace Settings
    {
        class VideoSettings;

        class AudioSettings;

        class PhysicsSettings;
    }
    class DisplayModule;

    class Entity;

    class Scene;

    class Time;

    class ScriptingApi;

    class TextureModule;

    class SplashScreen;

    using ExitCode = int;

    /**
     * @class Engine Main container class that holds all game data such as :
     *        Scenes, Prefabs, Configuration files, Settings
     */
    class Engine
    {
        public:
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            /**
             * @brief Creates an instance of engine by passing the project path containing all resources needed to load it such as config and assets
             * @param projectPath path containing resources to load
             * @param projectName name of the main config file in the projectPath (do not include extension cause it's also the window title / project name)
             */
            explicit Engine(const std::string &projectPath,
                            std::string projectName);

            ~Engine();
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            /**
             * @property _scenes list of all of the scenes
             */
            std::vector<std::shared_ptr<Scene>> _scenes;

            /**
             * @property _prefabs list of all of the prefabs
             */
            std::vector<std::shared_ptr<Entity>> _prefabs;

            /**
             * @property _prefabsConfigs list of all of the configuration of the prefabs
             */
            std::vector<std::shared_ptr<Config::XmlEntity>> _prefabsConfigs;

            /**
             * @property _defaultConfigs default configuration for the components
             */
            std::vector<Config::XmlComponent> _defaultConfigs;

            /**
             * @property _layers order of entities in the scenes
             */
            std::vector<std::string> _layers;

            /**
             * @property _execOrder order of execution of the components
             */
            std::vector<std::string> _execOrder;

            /**
             * @property _exit exit or not the program
             */
            static inline bool _exit = false;

            /**
             * @property _exitCode exit code of the program
             */
            static inline ExitCode _exitCode = 0;

            /**
             * @property _projectPath path to the project
             */
            std::string _projectPath;
            std::string _pluginsPath;

            /**
             * @property _projectName name of the project
             */
            std::string _projectName;

            /**
             * @property is_debug_session set the engine in debug mode or not
             */
            bool isDebugSession = false;

            /**
             * @property is_windowless_session set the engine in windowless mode or not
             */
            bool isWindowlessSession = false;

            /**
             * @property _projectConfig configuration of the project
             */
            std::unique_ptr<myxmlpp::Doc> _projectConfig;

            /**
             * @property _time time class of the engine
             */
            Time _time;

            /**
             * @property _physicsSettings physics settings of the engine
             */
            std::unique_ptr<Settings::PhysicsSettings> _physicsSettings;

            /**
             * @property _audioSettings audio settings of the engine
             */
            std::unique_ptr<Settings::AudioSettings> _audioSettings;

            /**
             * @property _videoSettings video settings of the engine
             */
            std::shared_ptr<Settings::VideoSettings> _videoSettings;
           
            /**
             * @property _scriptingApi scripting api of the engine to manage scripts of the game
             */
            std::unique_ptr<ScriptingApi> _scriptingApi;
            /**
             * @property _splashScreen splash screen of the engine
             */
   //         std::unique_ptr<SplashScreen> _splashScreen;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @details Getter that fetches the ordered vector of component types.
             *          Order determines which component has to be updated before others.
             * @returns A vector of std::string ordered based on execution order.
             */
            std::vector<std::string> &getExecOrder()
            { return _execOrder; };

            /**
             * @details Runs the game.
             */
            int run();

            /**
             * @biref Loads a script factory from the filepath to an shared library ('.so')
             * @param scriptFactory the path to the shared library
             * @warning the path must be relative to the executable
             */
            void loadScriptingAPI(std::unique_ptr<IScriptFactory> scriptFactory);

            /**
             * @brief Loads a graphical api from the filepath to an shared library ('.so')
             * @param graphicalLibPath the path to the shared library
             * @warning the path must be relative to the executable
             */
            //void loadGraphicalAPI(const std::string &graphicalLibPath);

            /**
             * @brief Loads the game configuration and inits all gameObjects/Components/Scenes
             */
            void loadEngine();

            /**
             * @brief Exit the program with a specified exit code
             * @param code exit code of the program
             */
            static void exit(ExitCode code);

            /**
             * @brief Getter to know if we should exit or not
             * @return exit status of the program
             */
            static bool isExiting()
            { return _exit; };

            /**
             * @brief Getter of the project path
             * @return the project path
             */
            std::string getProjectPath();

            /**
             * @brief Getter of prefabs
             * @return A list of all the prefabs loaded
             */
            std::vector<std::shared_ptr<Entity>> getPrefabs();

            /**
             * @brief Change the display of the engine to windowless so no display
             */
            void setWindowLessMode();

            /**
             * @brief Check if the display mode is in set to windowless or not
             * @return true if the engine is in windowless mode
             */
            bool isWindowLessSession();


            /**
             * @brief Check if the engine is in debug mode or not
             * @return true if debug is on
             */
            bool isDebugMode();
            /**
             * @brief Getter of default configuration of the components
             * @return the default configuration of the components
             */
            std::vector<Config::XmlComponent> getDefaultConfigs();

            /**
             * @brief Getter of default configuration of a specific component
             * @param type type of the component
             * @return the default configuration of the component type
             */
            Config::XmlComponent &getDefaultConfig(const std::string &type);

            /**
             * @details Find a scene by its name, returns the first matched
             * @param name the name of the scene to find
             * @return the required scene
             */
            std::shared_ptr<Scene> findSceneByName(const std::string &name);

            /**
             * @details Find a scene by its id, returns the first matched
             * @param id the name of the scene to find
             * @return the required scene
             */
            std::shared_ptr<Scene> findSceneById(const std::string &id);

            /**
             * Add the provided scene to the engine's scenes list
             * @param scene the scene to add
             */
            void addScene(const std::shared_ptr<Scene> &scene);


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
             * @details Inits the game prefabs
             */
            void _initPrefabs();

            /**
             * @details Inits the components default configs
             */
            void _initTemplates();

            /**
             * @details Inits the game data
             */
            void _initGameData();
//////////////////////--------------------------/////////////////////////

    };
}


#endif //ENGINE_ENGINE_HPP
