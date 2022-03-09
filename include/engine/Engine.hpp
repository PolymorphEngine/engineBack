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
        explicit Engine(const std::string &filepath);

    private:
        using ExitCode = int;
        std::vector<std::shared_ptr<Scene>> _scenes;
        std::vector<Config::XmlEntity> _prefabs;
        std::vector<Config::XmlComponent> _defaultConfigs;
        std::vector<std::string> _tags;
        std::vector<std::string> _layers;
        std::vector<std::string> _execOrder;
        Config::XmlEngine _data;
        bool _exit = false;
        ExitCode _exitCode = 0;
        

        public:
            /**
             * @summary Getter that fetches the ordered vector of component types.
             *          Order determines which component has to be updated before others.
             * @returns A vector of std::string ordered based on execution order.
             */
            std::vector<std::string> &getExecOrder(){return _execOrder;};

            /**
             * @summary Runs the game.
             */
            int run();
            
            void Exit(ExitCode code);
    };
}


#endif //ENGINE_ENGINE_HPP
