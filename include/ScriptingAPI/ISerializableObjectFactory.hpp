/*
** EPITECH PROJECT, 2020
** ISerializableObjectFactory.hpp
** File description:
** header for ISerializableObjectFactory.c
*/


#pragma once

#include "ASerializableObject.hpp"
#include "myxmlpp.hpp"

namespace polymorph::engine
{
    class ASerializableObject;
    namespace Config
    {
        class XmlComponent;
    }

    class ISerializableObjectFactory
    {
    
    ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
    
            virtual ~ISerializableObjectFactory() = default;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:

            using FactoryLambdaC = std::function<std::shared_ptr<ASerializableObject>(std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager)>;
            template<typename T>
            static inline FactoryLambdaC _makeC()
            {
                return [](Config::XmlComponent &data, GameObject entity) -> ASerializableObject{ return T(data, entity);};
            }

            virtual ASerializableObject
            createC(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager) = 0;
         
            using FactoryLambdaS = std::function<std::shared_ptr<ASerializableObject>(std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager)>;
            template<typename T>
            static inline FactoryLambdaS _makeS()
            {
                return [](Config::XmlComponent &data, GameObject entity) -> std::shared_ptr<ASerializableObject>{ return std::make_shared<T>(data, entity);};
            }
            virtual std::shared_ptr<ASerializableObject>
            createS(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager) = 0;

            virtual bool hasType(std::string &type) = 0;

    
    };

}

#define MAKE_SERIALIZABLE(S) {#S, _makeC<S>()},
#define MAKE_SERIALIZABLE_S(S) {#S, _makeS<S>()},

