/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "Utilities/safe_ptr.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"


namespace Polymorph
{
    namespace Config{class XmlComponent;}

    class IScriptFactory;
    class IComponentInitializer;
    class Entity;


    class ScriptingApi
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ScriptingApi(std::unique_ptr<IScriptFactory> factory);

            ~ScriptingApi();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;

        private:
            static inline std::unique_ptr<IScriptFactory> _scriptFactory = nullptr;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static Initializer create(std::string &type, Config::XmlComponent &data, safe_ptr<Entity> entity);


        private:

    };
}



