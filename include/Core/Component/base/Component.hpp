/*
** EPITECH PROJECT, 2020
** Component.hpp.h
** File description:
** header for Component.c
*/

#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include "IComponent.hpp"
#include "Utilities/safe_ptr.hpp"

namespace polymorph::engine
{
    // COMPONENT TYPES
    class TransformComponent;

    using Transform = safe_ptr<TransformComponent>;

    class PluginManager;
    class SceneManager;
    class AssetManager;
    class Logger;
    class Time;
    class Entity;

    using GameObject = safe_ptr<Entity>;

    /**
     * @class Component a class that is used to define any behavior for an
     * entity in the game
     */
    class Component : public IComponent
    {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            /**
             * @brief Created a new component from a game object
             * @param type the type of the component
             * @param game_object the game oejct that the component will be attached to
             */
            Component(const std::string &type, GameObject game_object);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties /////////////////////////////////

        public:
            /**
             * @property A reference to the unique transform component of the entity
             */
            Transform transform = Transform(nullptr);
            /**
             * @property A reference to the entity which the component is bind to.
             */
            GameObject gameObject = GameObject(nullptr);

            /**
             * @property The state of the component which defines if the component is updated or not.
             */
            bool enabled = true;


            PluginManager &Plugin;
            SceneManager &Scene;
            AssetManager &Asset;
            Logger &Debug;
            Time &time;

            /**
             * @property A reference to the engine
             */
            Engine &Game;


        protected:
            /**
             * @property name name of the component
             */
            std::string name;

            /**
             * @property _type type of the component
             */
            std::string _type;

            /**
             * @property awaked know if the component needs to be updated or not
             */
            bool awaked = false;

            /**
             * @property started know if the component  has been started or not yet
             */
            bool started = false;

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Methods /////////////////////////////////

        public:
            /**
             * @details An overridable method that's called once per frame in the game loop.
             */
            void update() override;

            /**
             * @details An overridable method that's called once in the lifetime of the component.
             *          It is called before the games start (or upon component creation at runtime).
             * @warning Is called even if the enable state of the component is set to false on creation.
             */
            void onAwake() override;

            /**
             * @details An overridable method that's called once in the lifetime of the component,
             *          It is called before the update method (or upon component creation at runtime).
             * @warning Is called ONLY when the enabled state of the component is passed to true.
             */
            void start() override;

            /**
             * @brief Set the commponent as started after calling start()
             */
            void setAsStarted() final
            { started = true; };

            /**
             * @brief Set the commponent as awaked to update it
             */
            void setAsAwaked() final
            { awaked = true; };

            /**
             * @brief Get the status of the component
             * @return true if the component is awaked
             */
            bool isAwaked() const final
            { return awaked; }

            /**
             * @brief Get the status of the component
             * @return true if the component is started
             */
            bool isStarted() const final
            { return started; }

            /**
             * @details Getter that return's the type of the component.
             * @return the type of the component as std::string.
             */
            std::string getType() const final
            { return _type; }

            /**
             * @details Looks for a component by type
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template<typename T>
            safe_ptr<T> getComponent();

            /**
             * @details Looks for a component by type in parent's
             * @tparam T: The 'T' type of the component to look for.
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template<typename T>
            safe_ptr<T> getComponentInParent();

            /**
             * @details Looks for a component by type in children
             * @tparam T: The 'T' type of the component to look for.
             * @warning Using depth first search !
             * @warning The type 'T' must inherit from the Component class to be fetched
             * @returns A safe pointer to the component 'T'
             */
            template<typename T>
            safe_ptr<T> getComponentInChildren();

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
             * @returns True if the component exist
             */
            template<typename T>
            bool componentExist();

            /**
             * @details Deletes the component of type 'T' from the entity
             * @tparam T: The 'T' type of the component to delete.
             * @warning The type 'T' must inherit from the Component class to be deleted
             * @returns True if the component existed and was deleted successfully
             */
            template<typename T>
            bool deleteComponent();

///////////////////////////--------------------------///////////////////////////

    };

}


#endif //ENGINE_COMPONENT_HPP
