/*
** EPITECH PROJECT, 2020
** ScriptFactory
** File description:
** header for ScriptFactory.c
*/


#pragma once

#include <memory>
#include <functional>
#include "Utilities/safe_ptr.hpp"

namespace Polymorph
{
    namespace Config
    {
        class XmlComponent;
    }
    class Entity;

    class IComponentInitializer;

    using GameObject = Polymorph::safe_ptr<Polymorph::Entity>;
    using Initializer = std::shared_ptr<IComponentInitializer>;
    class IScriptFactory
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IScriptFactory() = default;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:

            using FactoryLambda = std::function<Initializer (Config::XmlComponent &data, GameObject entity)>;
            template<typename T>
            static inline FactoryLambda _make()
            {
                return [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new T(data, entity));};
            }

            virtual Initializer
            create(std::string &type, Config::XmlComponent &data,
                   safe_ptr<Entity> entity) = 0;

            virtual bool hasType(std::string &type) = 0;

        private:

//////////////////////--------------------------/////////////////////////

    };
}
#define SCRIPT(S) {#S, _make<S##Initializer>()},



