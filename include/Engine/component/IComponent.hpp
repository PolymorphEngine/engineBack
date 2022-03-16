/*
** EPITECH PROJECT, 2020
** IComponent.hpp.h
** File description:
** header for IComponent.c
*/

#ifndef ENGINE_ICOMPONENT_HPP
#define ENGINE_ICOMPONENT_HPP

#include <iostream>

namespace Polymorph
{
    /**
     * @class IComponent interface class for all components
     */
    class IComponent
    {
        //  Component Specific
        public:
            virtual void update() = 0;
            virtual void onAwake() = 0;
            virtual void start() = 0;
            virtual bool isAwaked() const = 0;
            virtual void setAsStarted() = 0;
            virtual void setAsAwaked() = 0;
            virtual bool isStarted() const = 0;
            virtual void draw() = 0;
            virtual std::string getType() const = 0;

    };
}

#endif //ENGINE_ICOMPONENT_HPP
