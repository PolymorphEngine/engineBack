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
    namespace Config{class XmlEngine{};}
    class Entity{};
    class Component{};
    class Scene{
    public:
        using SceneId = std::size_t;
        void updateComponents();
    };
    class IPolymorphDisplay{
    public:
        virtual bool isRunning();
        virtual void clearDisplay();
        virtual void draw();
    };
    class PolymorphEvents{
    public:
       void storeEvents();
    };

    class Engine
    {
    public:
        Engine(std::any data);

    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        Config::XmlEngine _data;
        std::shared_ptr<Scene> _actual;
        Scene::SceneId _firstScene;
        IPolymorphDisplay _display;
        PolymorphEvents _event;


    public:
        void run();
    };
}


#endif //ENGINE_ENGINE_HPP
