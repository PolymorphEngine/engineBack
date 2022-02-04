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
    class Entity{
    public:
        bool isActive();
    };
    class Component{
    public:
        bool enabled;
        std::shared_ptr<Entity> gameObject;
        virtual void update() = 0;
        virtual void start() = 0;
    };
    class Engine{};

    class Scene
    {
    public:
        using SceneId = std::size_t;
        inline SceneId getSceneId()
        {
            static size_t lastId = 0;
            ++lastId;
            return lastId;
        }

        Scene(Config::XmlScene data, Engine game);

    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::vector<std::unique_ptr<Component>> _components;
        SceneId _id;
        std::shared_ptr<Engine> _game;

    public:
        void updateComponents();
        void loadScene();
        void initScene();

    };
}


#endif //ENGINE_SCENE_HPP
