/*
** EPITECH PROJECT, 2020
** ComponentFactory.hpp.h
** File description:
** header for ComponentFactory.c
*/

// @TEMPLATE:
//                  {"*", [](Config::XmlComponent &data, Entity &entity) -> Initializer{ return Initializer(new *Initializer(data, entity));}},

#ifndef ENGINE_COMPONENTFACTORY_HPP
#define ENGINE_COMPONENTFACTORY_HPP

#include "factory/ComponentInitializer.hpp"
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <memory>

// @COMPONENTS: (add components include here)
#include "factory/initializers/TransformInitializer.hpp"


namespace Polymorph
{
    class ComponentFactory
    {
        public:
            using Initializer = std::shared_ptr<AComponentInitializer>;

            static Initializer create(std::string &type, Config::XmlComponent &data, Entity &entity)
            {
                if (!_buildables.contains(type))
                    return nullptr;
                return _buildables[type](data, entity);
            };

        private:
            static inline std::map<std::string,
            std::function<Initializer(Config::XmlComponent &data, Entity &entity)>>
            _buildables =
            {
                // @INITIALIZERS: (add Component Initializers here)
                // @TRANSFORM:
                {"Transform", [](Config::XmlComponent &data, Entity &entity) -> Initializer{ return Initializer(new TransformInitializer(data, entity));}},
            };
    };
}

#endif //ENGINE_COMPONENTFACTORY_HPP
