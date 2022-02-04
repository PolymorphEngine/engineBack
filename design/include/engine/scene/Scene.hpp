/*
** EPITECH PROJECT, 2020
** Scene.hpp.h
** File description:
** header for Scene.c
*/

#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP

#include <vector>
#include <memory>
#include <iostream>

namespace Polymorph
{
    namespace Config{class XmlScene{};}
    class Entity{};
    class Component{};
    class Engine{};

    class Scene
    {
    public:
        Scene(Config::XmlScene data, Engine game);
        using SceneId = std::size_t;
        inline SceneId getSceneId()
        {
            static size_t lastId = 0;
            ++lastId;
            return lastId;
        }

    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::vector<std::unique_ptr<Component>> _components;
        SceneId _id;
        std::shared_ptr<Engine> _game;

    public:
        void updateComponents();

    };
}


#endif //ENGINE_SCENE_HPP
