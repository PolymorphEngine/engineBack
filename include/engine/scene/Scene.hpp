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
#include <factory/ComponentFactory.hpp>
#include "factory/ComponentInitializer.hpp"

#include "Entity.hpp"
#include "IComponent.hpp"
#include "Time.hpp"
#include "ref_ptr.hpp"



namespace Polymorph
{
    namespace Config{
        class XmlScene;
    }

    class Engine;

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
            std::unordered_map<std::string, std::vector<ComponentFactory::Initializer>> _execMap;
            std::map<std::shared_ptr<Timer>, Entity&> _destroyQueueList;
            SceneId _id;
            Engine& _game;
            Config::XmlScene &_data;
            std::unordered_map<std::string, std::vector<ComponentFactory::Initializer>> generateExecMap();
            void addToExecMap(
                    const std::vector<ComponentFactory::Initializer> &components);

        public:
            void updateComponents();
            void loadScene();
            void initScene();
            void updateDestroyQueueList();
            Entity &find(const std::string &name);
            Entity &find(const Entity &entity);
            Entity &findId(const std::string &id);

            Entity &Pop(const Entity &entity);
            Entity &Pop(const std::string &id);
            Entity &Pop(const std::string &id, TransformComponent &parent);

            // Statics
            static void Destroy(Entity &entity);
            static void Destroy(Entity &entity, float delayInSeconds);
            static Scene &Current;

    };
}


#endif //ENGINE_SCENE_HPP
