/*
** EPITECH PROJECT, 2020
** Component.hpp.h
** File description:
** header for Component.c
*/

#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include "IComponent.hpp"
#include "safe_ptr.hpp"


namespace Polymorph
{
    // COMPONENT TYPES
    class TransformComponent;


    class Entity;
    /**
     * @class A class that is used to define any behavior for an entity in the game
     */
    class Component : public IComponent
    {
        public:
            explicit Component(Entity &game_object);
            Component(const std::string &type, Entity &game_object);
            /**
             * @property A reference to the unique transform component of the entity
             */
            TransformComponent &transform;
            /**
             * @property A reference to the entity which the component is bind to.
             */
            Entity &gameObject;

            /**
             * @property The state of the component which defines if the component is updated or not.
             */
            bool enabled = true;

            /**
             * @summary An overridable method that's called once per frame in the game loop.
             */
            void Update()override;

            /**
             * @summary An overridable method that's called once in the lifetime of the component.
             *          It is called before the games start (or upon component creation at runtime).
             * @warning Is called even if the enable state of the component is set to false on creation.
             */
            void OnAwake()override;

            /**
             * @summary An overridable method that's called once in the lifetime of the component,
             *          It is called before the Update method (or upon component creation at runtime).
             * @warning Is called ONLY when the enabled state of the component is passed to true.
             */
            void Start()override;

            /**
             * @summary An overridable method that draws the component if its an drawable only.
             *          Called once per frame.
             */
            void Draw() override;

            void SetAsStarted() final {started = true;};
            void SetAsAwaked() final {awaked = true;};
            bool IsAwaked() const final {return awaked;}
            bool IsStarted() const final {return started;}
            
            /**
             * @summary Getter that return's the type of the component.
             * @return the type of the component as std::string.
             */ 
            std::string getType() const final {return _type;}

        protected:
            std::string name;
            std::string _type;
            bool awaked = false;
            bool started = false;

            //  Entity Re-define
        public:
            /**
             * @summary Looks for a component by type
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> GetComponent();
            
            /**
             * @summary Looks for a component by type in parent's
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> GetComponentInParent();
            
            /**
             * @summary Looks for a component by type in children
             * @tparam T: The 'T' type of the component to look for.
             * @warning Using depth first search !
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> GetComponentInChildren();
            
            /**
             * @summary Adds a component to the entity
             * @tparam T: The 'T' type of the component to add.
             * @warning Does nothing if the component is already added
             * @warning The type 'T' must have an initializer in the component factory to be added this way
             * @warning The type 'T' must inherit from the Component class to be added
             * @returns A safe pointer to the component 'T'
             */
            template <typename T>
            safe_ptr<T> AddComponent();

            /**
             * @summary Checks if a component of type 'T' exist in the entity
             * @tparam T: The 'T' type of the component to check for.
             * @warning The type 'T' must inherit from the Component class to be checked
             * @returns True if the component exist
             */
            template <typename T>
            bool ComponentExist();

            /**
             * @summary Deletes the component of type 'T' from the entity
             * @tparam T: The 'T' type of the component to delete.
             * @warning The type 'T' must inherit from the Component class to be deleted
             * @returns True if the component existed and was deleted successfully
             */
            template <typename T>
            bool DeleteComponent();
    };

}


#endif //ENGINE_COMPONENT_HPP
