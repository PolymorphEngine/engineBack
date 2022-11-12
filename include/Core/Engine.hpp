/*
** EPITECH PROJECT, 2020
** polymorph.hpp.h
** File description:
** header for polymorph.c
*/

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <map>
#include <iostream>
#include <myxmlpp.hpp>
#include <memory>
#include <vector>
#include <atomic>

#include "Utilities/safe_ptr.hpp"
#include "Utilities/Time.hpp"
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Debug/Log/Logger.hpp"
#include "Plugins/PluginManager.hpp"
#include "Plugins/AssetManager.hpp"
#include "Core/Scene/SceneManager.hpp"



namespace polymorph::engine
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

    class PluginManager;
    class AssetManager;
    class Logger;

    class Entity;

    class Scene;

    class Time;

    class ScriptingApi;
    class SceneManager;


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
            explicit Engine(std::string projectName,const std::string &projectPath, std::string pluginPath);

            ~Engine();
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            Logger _logger;

            PluginManager _pluginManager;

            SceneManager _sceneManager;

            /**
 * @property _scriptingApi scripting api of the engine to manage scripts of the game
 */
            ScriptingApi _scriptingApi;

            AssetManager _assetManager;

            /**
             * @property _time time class of the engine
             */
            Time _time;

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
             * @property _pluginsExecOrder order of execution of the plugins
             */
            std::vector<std::string> _pluginsExecOrder;
            /**
             * @property _exit exit or not the program
             */
            std::atomic<bool> _exit = false;

            /**
             * @property _exitCode exit code of the program
             */
            std::atomic<ExitCode> _exitCode = 0;

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

            std::vector<std::string> &getPluginExecOrder()
            { return _pluginsExecOrder; };

            AssetManager &getAssetManager()
            { return _assetManager; };

            SceneManager &getSceneManager()
            { return _sceneManager; };

            Logger &getLogger()
            {
                return _logger;
            }
            ScriptingApi &getScriptingApi()
            {
                return _scriptingApi;
            }

            Time &getTime()
            {
                return _time;
            };



            /**
             * @details Runs the game.
             */
            int run();

            /**
             * @biref Loads a script factory from the filepath to an shared library ('.so')
             * @param scriptFactory the path to the shared library
             * @warning the path must be relative to the executable
             */
            void loadScriptingAPI(std::unique_ptr<IScriptFactory> scriptFactory, std::unique_ptr<ISerializableObjectFactory> serializableObjectFactory);

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

            PluginManager &getPluginManager();

            /**
             * @brief Exit the program with a specified exit code
             * @param code exit code of the program
             */
            void exit(ExitCode code);

            /**
             * @brief Getter to know if we should exit or not
             * @return exit status of the program
             */
            bool isExiting() const
            { return _exit; };

            /**
             * @brief Getter of the project path
             * @return the project path
             */
            std::string getProjectPath();

            /**
             * @brief Getter of the project title
             * @return the project title
             */
            std::string getTitle();

            /**
             * @brief Getter of the project video settings
             * @return the project video settings
             */
            std::shared_ptr<Settings::VideoSettings> getVideoSettings();

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

            void _initPluginsExectutionOrder();

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
