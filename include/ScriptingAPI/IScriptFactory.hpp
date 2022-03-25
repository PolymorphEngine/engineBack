/*
** EPITECH PROJECT, 2020
** ScriptFactory
** File description:
** header for ScriptFactory.c
*/


#pragma once

#include <memory>

namespace Polymorph
{
    namespace Config {class XmlComponent;}
    class Entity;
    class AComponentInitializer;
    using Initializer = std::shared_ptr<AComponentInitializer>;
    
    class IScriptFactory
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IScriptFactory() = default;

//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual Initializer create(std::string &type, Config::XmlComponent &data, Entity &entity) = 0;
    
    
        private:
    
//////////////////////--------------------------/////////////////////////
    
    };
}



