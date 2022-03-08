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
#include <map>
#include <unordered_map>
#include "factory/ComponentInitializer.hpp"
#include "ref_ptr.hpp"



namespace Polymorph
{
    namespace Config{
        class XmlScene;
    }

    class Engine;
    class Entity;
    class Timer;

    class Scene
    {
        public:
            using SceneId = std::size_t;
            inline SceneId getSceneId()
            {
                static size_t lastId = 0;
                ++lastId;
                return lastId;
            };

            Scene(Config::XmlScene &data, Engine &game);

        private:
            std::vector<std::shared_ptr<Entity>> _entities;
            //std::unordered_map<std::string, std::vector<ComponentFactory::Initializer>> _execMap;
            std::map<std::shared_ptr<Timer>, Entity&> _destroyQueueList;
            std::string &id;
            Engine& _game;
            Config::XmlScene &_data;

        public:
            void updateComponents();
            void loadScene();
            void unloadScene();
            void updateDestroyQueueList();
            safe_ptr<Entity> find(const std::string &name);
            std::shared_ptr<Entity> &find(Entity &entity);
            std::shared_ptr<Entity> &findId(std::string &id);

            Entity &Pop(Entity &entity);
            Entity &Pop(std::string &id);
            int countChildren(std::vector<std::shared_ptr<Entity>>::iterator &entity, std::string &parent_id);

            void Destroy(Entity &entity);
            void Destroy(Entity &entity, float delayInSeconds);
            // Statics
            static Scene &Current;

    };
}


#endif //ENGINE_SCENE_HPP
