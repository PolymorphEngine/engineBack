/*
** EPITECH PROJECT, 2020
** ScriptFactory
** File description:
** header for ScriptFactory.c
*/


#pragma once

#include <memory>
#include "Utilities/safe_ptr.hpp"

namespace Polymorph
{
    namespace Config
    {
        class XmlComponent;
    }
    class Entity;

    class IComponentInitializer;

    using Initializer = std::shared_ptr<IComponentInitializer>;

    class IScriptFactory
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IScriptFactory() = default;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual Initializer
            create(std::string &type, Config::XmlComponent &data,
                   safe_ptr<Entity> entity) = 0;

            virtual bool hasType(std::string &type) = 0;

        private:

//////////////////////--------------------------/////////////////////////

    };
}



