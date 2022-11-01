/*
** EPITECH PROJECT, 2020
** ISerializableObjectFactory.hpp
** File description:
** header for ISerializableObjectFactory.c
*/


#pragma once

#include "ASerializableObject.hpp"
#include "myxmlpp.hpp"
#include "Utilities/safe_ptr.hpp"

namespace polymorph::engine
{
    class ASerializableObject;
    namespace Config
    {
        class XmlComponent;
    }
    class Entity;
    using GameObject = safe_ptr<Entity>;
    class ISerializableObjectFactory
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:

            virtual ~ISerializableObjectFactory() = default;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:

            virtual std::shared_ptr<ASerializableObject>
            createS(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager) = 0;

            virtual bool hasType(std::string &type) = 0;

        protected:
            using FactoryLambdaS = std::function<std::shared_ptr<ASerializableObject>(std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager)>;
            template<typename T>
            static inline FactoryLambdaS _make()
            {
                return [](std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager) -> std::shared_ptr<ASerializableObject>{ return std::shared_ptr<ASerializableObject>(new T(data, manager));};
            }

    };

}

#define MAKE_SERIALIZABLE(ns, S) {#S, _make<ns::S##Impl>()},


