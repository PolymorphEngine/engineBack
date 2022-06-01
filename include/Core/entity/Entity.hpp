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

#include "Utilities/safe_ptr.hpp"

namespace Polymorph
{
    class Component;
    class IComponentInitializer;
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
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Entity(Config::XmlEntity &data, Engine &game);
            ~Entity();

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            /**
             * @property The unique mandatory component of an entity
             *           it's like his identity in the world.
             */
            Transform transform = Transform(nullptr);

            /**
             * @property The entity's name (not necessarily unique)
             */
            std::string name;

        private:
            bool _isPrefab;
            bool _wasPrefab;
            bool _active;
            std::string _stringId;
            std::string _prefabId;
            std::vector<std::string> _tags;
            std::string _layer;
            Engine &_game;
            std::vector<std::string> _order;
            Config::XmlEntity &_xml_config;
            std::unordered_map<std::string, std::vector<std::shared_ptr<IComponentInitializer>>> _components;
//////////////////////--------------------------/////////////////////////





/////////////////////////////// METHODS ////////////////////////////////////
        public:

            /**
             * @details Check for game object state
             * @returns The state of the game object
             */
            bool isActive() const;

            bool isPrefab() const;
            bool wasPrefab() const;

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
            void update();

            /**
             * @details start the game object by starting the components
             */
            void start();

            /**
             * @details Looks for the drawable component of the entity,
             *          then calls draw() of children.
             */
            void draw();

            /**
             * @details Draws the children
             */
            void drawChildren(TransformComponent &trm);

            /**
             * @details Get a child entity by its name
             * @param nameToFind The name of the child
             * @return The child entity
             */
            safe_ptr<Entity> find(const std::string &nameToFind);
            safe_ptr<Entity> findByPrefabId(const std::string &nameToFind);

            /**
             * @details Get a child entity by its index
             * @param idx The idx of the wanted child
             * @return The child entity
             */
            safe_ptr<Entity> childAt(std::size_t idx);

            /**
             * @details Awakes the entity by calling onAwake() of the components
             */
            void awake();

            void addComponent(std::string &component, Config::XmlComponent &config, GameObject gameObject);

            /**
             * @details Looks for a component by type
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> getComponent();

            /**
             * @details Looks for all components of type T
             * @tparam T: The 'T' type of the components to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A vector of safe pointer to the components of type 'T'
             */
            template <typename T>
            std::vector<safe_ptr<T>> getComponents();

            /**
             * @details Adds a component to the entity
             * @tparam T: The 'T' type of the component to add.
             * @warning Does nothing if the component is already added
             * @warning The type 'T' must have an initializer in the component factory to be added this way
             * @warning The type 'T' must inherit from the Component class to be added
             * @returns A safe pointer to the component 'T'
             */
            template<typename T>
            safe_ptr<T> addComponent();

            /**
             * @details Checks if a component of type 'T' exist in the entity
             * @tparam T: The 'T' type of the component to check for.
             * @warning The type 'T' must inherit from the Component class to be checked
             * @bug is not found by compiler !!!
             * @returns True if the component exist
             */
            template <typename T>
            bool componentExist();

            /**
             * @details Deletes the component of type 'T' from the entity
             * @tparam T: The 'T' type of the component to delete.
             * @warning The type 'T' must inherit from the Component class to be deleted
             * @returns True if the component existed and was deleted successfully
             */
            template <typename T>
            bool deleteComponent();

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
            std::string &getPrefabId() {return _prefabId;};

            /**
             * @details A setter for the entity's unique id
             * @param An std::string of the entity's unique id
             */
             void setId(const std::string &id) {_stringId = id;};
             void setPrefabId(const std::string &id) {_stringId = id;};

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
//////////////////////--------------------------/////////////////////////



    };
    using GameObject = safe_ptr<Entity>;
}


#endif //ENGINE_ENTITY_HPP
