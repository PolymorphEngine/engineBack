/*
** EPITECH PROJECT, 2020
** Polymorph.hpp.h
** File description:
** header for Polymorph.c
*/

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <any>
#include <iostream>
#include <memory>
#include <vector>

namespace Polymorph
{
    typedef size_t SceneId;
    namespace Config{class XmlEngine{};}
    class Entity;
    class Component;
    class Scene;
    class IPolymorphDisplay;
    class PolymorphEvents;

    class Engine
    {
    public:
        Engine(std::any data);

    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        Config::XmlEngine _data;
        Scene& _actual;
        SceneId _firstScene;
        IPolymorphDisplay& _display;
        PolymorphEvents& _event;


    public:
        void run();
    };
}


#endif //ENGINE_ENGINE_HPP
