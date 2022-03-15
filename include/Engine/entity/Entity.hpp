/*
** EPITECH PROJECT, 2020
** Entity.hpp.h
** File description:
** header for Entity.c
*/

#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP


#include <vector>
#include <map>
#include <unordered_map>

#include "safe_ptr.hpp"
#include "XmlEntity.hpp"

namespace Polymorph
{
    class Component;
    class AComponentInitializer;
    class Engine;
    class TransformComponent;
    namespace Config{
        class XmlEntity;
        class XmlComponent;
    }

    /**
     * @class Entity a container class which is defined by the components it
     * holds.
     */
    class Entity
    {
        public:
            Entity();
            Entity(std::shared_ptr<Config::XmlEntity> &data, std::shared_ptr<Engine> &game);
            ~Entity();

            /**
             * @property The unique mandatory component of an entity
             *           it's like his identity in the world.
             */
            std::shared_ptr<TransformComponent> transform;

            /**
             * @property The entity's name (not necessarily unique)
             */
            std::string name;

            /**
             * @details Check for game object state
             * @returns The state of the game object
             */
            bool isActive() const;

            /**
             * @details Changes the game object state
             * @param active: the new state of the object
             */
            void setActive(bool active);

            /**
             * @details Check if the game object has the tag passed as parameter.
             * @param tag: The tag to look for.
             * @returns True if the game object has the tag, False otherwise.
             */
            bool hasTag(const std::string &tag) const;


            /**
             * @details Adds to the game object the tag passed as parameter.
             * @param tag: The tag to add
             */
            void addTag(const std::string &tag);

            /**
             * @details Deletes from the game object the tag passed as parameter.
             * @param tag: The tag to delete
             */
            void deleteTag(const std::string &tag);

            /**
             * @details Updates the game object by updating in the component execution order
             *          all components.
             */
            void Update();

            /**
             * @details Looks for the drawable component of the entity,
             *          then calls Draw() of children.
             */
            void Draw();

            /**
             * @details Draws the children
             */
            void DrawChildren(TransformComponent &trm);

            /**
             * @details Awakes the entity by calling OnAwake() of the components
             */
            void Awake();


            /**
             * @details Looks for a component by type
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> GetComponent();

            void addComponent(std::string &component, Config::XmlComponent &config);

            /**
             * @details Adds a component to the entity
             * @tparam T: The 'T' type of the component to add.
             * @warning Does nothing if the component is already added
             * @warning The type 'T' must have an initializer in the component factory to be added this way
             * @warning The type 'T' must inherit from the Component class to be added
             * @returns A safe pointer to the component 'T'
             */
            template<typename T>
            safe_ptr<T> AddComponent();

            /**
             * @details Checks if a component of type 'T' exist in the entity
             * @tparam T: The 'T' type of the component to check for.
             * @warning The type 'T' must inherit from the Component class to be checked
             * @returns True if the component exist
             */
            template <typename T>
            bool componentExist() const;

            /**
             * @details Deletes the component of type 'T' from the entity
             * @tparam T: The 'T' type of the component to delete.
             * @warning The type 'T' must inherit from the Component class to be deleted
             * @returns True if the component existed and was deleted successfully
             */
            template <typename T>
            bool DeleteComponent();

            /**
             * @details A getter to fetch the entity's name
             * @returns An std::string of the entity's name
             */
            std::string getName() const{return name;};

            /**
             * @details A getter to fetch the entity's unique id
             * @returns An std::string of the entity's unique id
             */
            std::string &getId() {return _stringId;};

            /**
             * @details A getter to fetch the XmlEntity associated with the
             * entity
             * @returns The associated XmlEntity
             */
             Config::XmlEntity &getXmlConfig() const noexcept;

            /**
             * @details Comparator operator that compares 2 entities based on unique id.
             * @param entity: the entity to compare with.
             * @returns True if the entities are the same otherwise false.
             */
            bool operator==(Entity &entity)
            {
                return (entity.getId() == this->getId());
            }

            /**
             * @details Comparator operator that compares 2 entities based on unique id.
             * @param entity: the entity to compare with.
             * @returns False if the entities are the same otherwise True.
             */
            bool operator!=(Entity &entity)
            {
                return (entity.getId() != this->getId());
            }

            /**
             * @details Comparator operator that compares an entity and an id based on
             *          the entity's unique id.
             * @param id: the id to compare with.
             * @returns True if the entity's id is the same as the id passed
             *          the same otherwise False.
             */
            bool operator==(const std::string &id)
            {
                return (this->getId() == id);
            }

            /**
             * @details Comparator operator that compares an entity and an id based on
             *          the entity's unique id.
             * @param id: the id to compare with.
             * @returns False if the entity's id is the same as the id passed
             *          the same otherwise True.
             */
            bool operator!=(const std::string &id)
            {
                return (this->getId() != id);
            }

        private:
            bool componentExist(std::string &type);
            bool _isPrefab;
            bool _active;
            std::string _stringId;
            std::vector<std::string> _tags;
            std::string _layer;
            std::shared_ptr<Engine> _game;
            std::vector<std::string> _order;
            Config::XmlEntity &_xml_config;
            std::unordered_map<std::string, std::vector<std::shared_ptr<AComponentInitializer>>> _components;

    };
    using GameObject = safe_ptr<Entity>;
}


#endif //ENGINE_ENTITY_HPP
