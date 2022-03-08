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
    typedef size_t SceneId;
    namespace Config{class XmlEngine{};}
    class Scene;
    class IPolymorphDisplay;

    class Engine
    {
    public:
        Engine(const std::string &filepath = nullptr);

    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        std::vector<Config::XmlEntity> _prefabs;
        std::vector<Config::XmlComponent> _defaultConfigs;
        std::vector<std::string> _tags;
        std::vector<std::string> _layers;
        std::vector<std::string> _execOrder;
        Config::XmlEngine _data;
        Scene& _actual;
        SceneId _firstScene;
        IPolymorphDisplay& _display;


        public:
            std::vector<std::string> &getExecOrder(){return _execOrder;};
            void run();
    };
}


#endif //ENGINE_ENGINE_HPP
