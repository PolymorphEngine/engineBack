/*
** EPITECH PROJECT, 2020
** Entity.hpp.h
** File description:
** header for Entity.c
*/

#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP

#include <iostream>
#include <vector>
#include <memory>

namespace Polymorph
{
    class Component{};
    class Engine{};
    namespace Config{
        class XmlEntity{};
    }

    using EntityId = std::size_t;

    inline EntityId getEntityId()
    {
        static size_t lastId = 0;
        ++lastId;
        return lastId;
    }

    class Entity
    {
    public:
        Entity(Config::XmlEntity data,  Engine game)
        {
            _data = data;
            _game = game;
            _id = getEntityId();
        };

    private:
        EntityId _id;
        Polymorph::Config::XmlEntity _data;
        Polymorph::Engine _game;
        std::vector<std::shared_ptr<Polymorph::Component>> _components;
    };
}


#endif //ENGINE_ENTITY_HPP
