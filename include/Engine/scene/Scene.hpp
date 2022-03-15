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
#include "safe_ptr.hpp"
#include "Node.hpp"


namespace Polymorph
{
    namespace Config{
        class XmlScene;
    }

    class Engine;
    class Entity;
    using GameObject = safe_ptr<Entity>;
    class Timer;

    /**
     * @class A container class that's store's all entities from a game scene
     */
    class Scene
    {
        public:
            Scene(std::shared_ptr<myxmlpp::Node> &data, Engine &game);
        private:
            std::vector<std::shared_ptr<Entity>> _entities;
            std::map<std::shared_ptr<Timer>, Entity&> _destroyQueueList;
            Engine &_game;
            std::shared_ptr<Config::XmlScene> _config_data;

        public:
            std::string name;
            std::string id;
            
            /**
             * @details Loops trough entities twice:
             *          Once to call Update
             *          Then to call Draw
             *          Finally updates the destroy queue
             *          GameObject(nullptr) if not found.
             */
            void updateComponents();

            /**
             * @details Generates Entities and their Components from configuration files.
             */
            void loadScene();
            
            /**
             * @details Erases all entities and their components from scene
             */
            void unloadScene();

            /**
             * @details Check for entities to erase based on their delay,
             *          with their respective timer.
             *          Erases them if time's up.
             */
            void updateDestroyQueueList();
            
            /**
             * @details Looks for the first occurrence of entity with the parameter name
             * @param name: The name of the entity to find
             * @return A safe_ptr to an Entity (alias GameObject type) 
             *         GameObject(nullptr) if not found.
             */
            GameObject find(const std::string &name);

            /**
             * @details Looks for all occurrences of entities with the parameter name
             * @param name: The name of the entities to find
             * @return A vector of safe_ptr to entities (alias GameObject type) 
             */
            std::vector<GameObject> findAll(const std::string &name);


            /**
             * @details Looks for the first occurrence of entity with has the tag
             *          passed as parameter.
             * @param tag: The filter tag
             * @return A safe_ptr to an Entity (alias GameObject type). 
             *         GameObject(nullptr) if not found.
             */
            GameObject findByTag(const std::string &tag);

            
            /**
             * @details Looks for all occurrences of entities filtered by the tag parameter
             * @param tag: The filter tag
             * @return A vector of safe_ptr to entities (alias GameObject type)
             */
             std::vector<GameObject> findAllByTag(const std::string &tag);


            /**
             * @details Looks for an entity by it's unique id
             *          passed as parameter.
             * @param id: the unique id of the entity
             * @return A safe_ptr to an Entity (alias GameObject type). 
             *         GameObject(nullptr) if not found.
             */
            GameObject findById(const std::string &id);


            /**
             * @details Erase an entity (and his children) from scene
             * @param entity: the entity to erase
             */
            void Erase(Entity &entity);


            /**
              * @details Erase an entity (and his children) from scene
              * @param entity: the entity to erase
              */
            void Erase(std::string &id);

            /**
              * @details Adds an entity to the destroy queue of the scene
              * @param entity: the entity to push in queue
              */
            void Destroy(Entity &entity);


            /**
              * @details Adds an entity to the destroy queue of the scene
              * @param entity: the entity to push in queue
              * @param delayInSeconds: The delay in seconds before destroying it once in queue
              */
            void Destroy(Entity &entity, float delayInSeconds);
            

        private:
            /**
              * @details Counts all children in an entity
              * @param entity: An iterator of the parent entity
              * @param parent_id: The id of the parent entity
              * @returns The total count of children and sub-children of an entity
              */
            int _countChildren(std::vector<std::shared_ptr<Entity>>::iterator &entity, std::string &parent_id);

    };
}


#endif //ENGINE_SCENE_HPP
