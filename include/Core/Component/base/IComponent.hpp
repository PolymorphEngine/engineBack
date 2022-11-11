/*
** EPITECH PROJECT, 2020
** IComponent.hpp.h
** File description:
** header for IComponent.c
*/

#pragma once

#include <iostream>

namespace polymorph::engine
{
    /**
     * @class IComponent interface class for all components
     */
    class IComponent
    {
            //  Component Specific
        public:
            /**
             * @brief A method that's called once per frame in the game loop.
             */
            virtual void update() = 0;

            /**
             * @details A method that's called once in the lifetime of the component.
             *          It is called before the games start (or upon component creation at runtime).
             * @warning Is called even if the enable state of the component is set to false on creation.
             */
            virtual void onAwake() = 0;

            /**
             * @details A method that's called once in the lifetime of the component,
             *          It is called before the update method (or upon component creation at runtime).
             * @warning Is called ONLY when the enabled state of the component is passed to true.
             */
            virtual void start() = 0;

            /**
             * @brief Set the commponent as awaked to update it
             */
            virtual bool isAwaked() const = 0;

            /**
             * @brief Set the commponent as started after calling start()
             */
            virtual void setAsStarted() = 0;

            /**
             * @brief Get the status of the component
             * @return true if the component is awaked
             */
            virtual void setAsAwaked() = 0;

            /**
             * @brief Get the status of the component
             * @return true if the component is started
             */
            virtual bool isStarted() const = 0;

            /**
             * @details Getter that return's the type of the component.
             * @return the type of the component as std::string.
             */
            virtual std::string getType() const = 0;

    };
}
