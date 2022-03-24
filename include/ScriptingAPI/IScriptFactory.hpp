/*
** EPITECH PROJECT, 2020
** ScriptFactory
** File description:
** header for ScriptFactory.c
*/


#pragma once

namespace Polymorph
{
    class AComponentInitializer;
    class IScriptFactory
    {
    
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IScriptFactory() = default;
            using Initializer = std::shared_ptr<AComponentInitializer>;

//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual Initializer create(std::string &type, Config::XmlComponent &data, Entity &entity) = 0;
    
    
        private:
    
//////////////////////--------------------------/////////////////////////
    
    };
}


