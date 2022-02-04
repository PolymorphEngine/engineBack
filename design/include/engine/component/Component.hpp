/*
** EPITECH PROJECT, 2020
** Component.hpp.h
** File description:
** header for Component.c
*/

#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include <iostream>


namespace Polymorph
{
    class Entity{};
    class Engine{};
    class XmlComponent{};

    using ComponentId = std::size_t;

    inline ComponentId getComponentId()
    {
        static size_t lastId = 0;
        ++lastId;
        return lastId;
    }

    class Component
    {
    public:
        Component(Entity entity, Engine game, XmlComponent data);
        Polymorph::Entity gameObject;

        virtual void update() = 0;
        virtual void start() = 0;
    };
}


#endif //ENGINE_COMPONENT_HPP
