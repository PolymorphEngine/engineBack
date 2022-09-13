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

#include <myxmlpp.hpp>
#include "Utilities/safe_ptr.hpp"
#include "Core/entity/Entity.hpp"


namespace Polymorph
{
    namespace Config{
        class XmlScene;
    }

    class Engine;
    class Entity;
    using GameObject = safe_ptr<Entity>;
    using EntityIterator = std::vector<std::shared_ptr<Entity>>::iterator;
    class Timer;

    /**
     * @class Scene a container class that's store's all entities from a game scene
     */
    class Scene
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Scene(std::shared_ptr<myxmlpp::Node> &data, Engine &game);
            explicit Scene(std::string sceneName, Engine &game);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::string name;
            std::string id;
        private:
            std::vector<std::shared_ptr<Entity>> _entities;
            std::vector<std::shared_ptr<Entity>> _entitiesToAdd;
            std::map<std::shared_ptr<Timer>, Entity&> _destroyQueueList;
            Engine &_game;
            std::shared_ptr<Config::XmlScene> _config_data;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @details Loops trough entities twice:
             *          Once to call update
             *          Then to call draw
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
             * @details Check for entities to _erase based on their delay,
             *          with their respective timer.
             *          Erases them if time's up.
             */
            void updateDestroyQueueList();

            /**
             * @details Get all entities of a list
             * @returns An array of safe_ptr to the entities in the scene
             */
             std::vector<GameObject> getAll() const noexcept;

            /**
             * @details Looks for the first occurrence of entity with the parameter name
             * @param needle: The name of the entity to find
             * @return A safe_ptr to an Entity (alias GameObject type)
             *         GameObject(nullptr) if not found.
             */
            GameObject find(const std::string &needle);

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
             * @details Looks for an entity by it's unique id
             *          passed as parameter.
             * @param id: the unique id of the entity
             * @return A iterator to an Entity (alias GameObject type).
             *         end() if not found.
             */
            EntityIterator findItById(const std::string &id);

            /**
             * @details Add an entity to the entities list
             * @param entity a shared_ptr to an entity to add in the list
             */
             void addEntity(const std::shared_ptr<Entity>& entity);
             /**
              * @details Add an entity to the entities list
              * @param entity a shared_ptr to an entity to add in the list
              */
             void addEntityToAddQueue(const std::shared_ptr<Entity>& entity);

            /**
            * @details Add an entity to the entities list at the desired index
            * @param entity a shared_ptr to an entity to add in the list
            * @param idx the desired index
            */
            void addEntityAtIdx(const std::shared_ptr<Entity>& entity, std::size_t idx);


            /**
              * @details Adds an entity to the destroy queue of the scene
              * @param entity: the entity to push in queue
              */
            void destroy(Entity &entity);


            /**
              * @details Adds an entity to the destroy queue of the scene
              * @param entity: the entity to push in queue
              * @param delayInSeconds: The delay in seconds before destroying it once in queue
              */
            void destroy(Entity &entity, float delayInSeconds);

            /**
             * @details Remove an entity iterator
             * @param it: entity iterator to remove
             */
            std::shared_ptr<Entity> pop(EntityIterator it);

            /**
             * @return number of parent entity in the scene
             */
            std::size_t countParents();

            template<class T>
            std::vector<safe_ptr<T>> getComponentsInScene() const {
                std::vector<safe_ptr<T>> components;

                for (auto &entity : _entities) {
                    if (entity->componentExist<T>()) {
                        components.push_back(entity->getComponent<T>());
                    }
                }
                return components;
            };


        private:
            /**
             * @details Erase an entity (and his children) from scene
             * @param entity: the entity to _erase
             */
            void _erase(Entity &entity);

            /**
              * @details Erase an entity (and his children) from scene
              * @param entity: the entity to _erase
              */
            void _erase(std::string &id);

            void _eraseChildren(Entity &entity);

//////////////////////--------------------------/////////////////////////

    };
}


#endif //ENGINE_SCENE_HPP
