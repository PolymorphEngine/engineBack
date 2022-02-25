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
            virtual bool IsStarted() const = 0;
            virtual std::string getType() const = 0;

        protected:

        //  Entity Re-define
        public:
            virtual void setActive(bool active) = 0;
            virtual bool componentExist(const std::string &type) const = 0;
            virtual bool deleteComponent(const std::string &type) = 0;
            virtual bool deleteComponent(IComponent &component) = 0;

        protected:
            virtual void Destroy() = 0;
            virtual void Destroy(float delayInSeconds) = 0;

    };
}

#endif //ENGINE_ICOMPONENT_HPP
