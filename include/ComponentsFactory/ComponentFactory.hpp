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

#include <iostream>
#include <map>

#include <functional>
#include <vector>
#include <memory>

// @COMPONENTS: (add components include here)
#include "ComponentsFactory/initializers/TransformInitializer.hpp"
#include "ComponentsFactory/initializers/SpriteRendererInitializer.hpp"
#include "ComponentsFactory/initializers/TextRendererInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderCircle2dInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderRect2dInitializer.hpp"

namespace Polymorph
{
    class IComponentInitializer;
    class ComponentFactory
    {
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;
///////////////////////////////// Constructors /////////////////////////////////

        public:
            static Initializer create(std::string &type, Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        private:
            static const inline std::map<std::string,
            std::function<Initializer (Config::XmlComponent &data, GameObject entity)>>
            _buildables =
            {
                // @INITIALIZERS: (add Component Initializers here)
                // @TRANSFORM:
                {
                        {"Transform", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new TransformInitializer(data, entity));}},
                        {"ColliderCircle2d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderCircle2dInitializer(data, entity));}},
                        {"ColliderRect2d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderRect2dInitializer(data, entity));}},
                        {"SpriteRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new SpriteRendererInitializer(data, entity));}},
                        {"TextRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new TextRendererInitializer(data, entity));}},
                },
            };
///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COMPONENTFACTORY_HPP
