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
    class IComponent
    {
        //  Component Specific
        public:
            virtual void Update() = 0;
            virtual void OnAwake() = 0;
            virtual void Start() = 0;
            virtual bool IsAwaked() const = 0;
            virtual void SetAsStarted() = 0;
            virtual void SetAsAwaked() = 0;
            virtual bool IsStarted() const = 0;
            virtual void Draw() = 0;
            virtual std::string getType() const = 0;

        protected:

        //  Entity Re-define
        public:
            virtual void setActive(bool active) = 0;
            
    };
}

#endif //ENGINE_ICOMPONENT_HPP
