/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "Utilities/safe_ptr.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"


namespace polymorph::engine
{
    namespace Config
    {
        class XmlComponent;
    }

    class IScriptFactory;

    class IComponentInitializer;

    class Entity;

    class ScriptingApi
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ScriptingApi(std::unique_ptr<IScriptFactory> factory);
            ScriptingApi() = default;
            ScriptingApi(ScriptingApi &&c) noexcept: _scriptFactory(std::move(c._scriptFactory)) {};
            ScriptingApi(ScriptingApi &c): _scriptFactory(std::move(c._scriptFactory)) {};

            ~ScriptingApi();
            
            ScriptingApi &operator=(ScriptingApi &&other) noexcept
            {
                this->_scriptFactory = std::move(other._scriptFactory);
                return *this;
            }


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;

        private:
            std::unique_ptr<IScriptFactory> _scriptFactory;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            Initializer
            create(std::string &type, Config::XmlComponent &data,
                   safe_ptr<Entity> entity);


        private:

    };
}



