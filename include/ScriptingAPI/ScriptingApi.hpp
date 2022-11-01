/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "Utilities/safe_ptr.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"
#include "ISerializableObjectFactory.hpp"
#include "Node.hpp"
#include "Debug/Log/Logger.hpp"
#include "Debug/Exceptions/ExceptionLogger.hpp"


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
            ScriptingApi(ScriptingApi &&c) noexcept: _scriptFactory(std::move(c._scriptFactory)), _objectFactory(std::move(c._objectFactory)) {};
            ScriptingApi(ScriptingApi &c): _scriptFactory(std::move(c._scriptFactory)), _objectFactory(std::move(c._objectFactory)) {};

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
            std::unique_ptr<ISerializableObjectFactory> _objectFactory;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setSerializableObjectFactory(std::unique_ptr<ISerializableObjectFactory> factory);
            
            Initializer
            create(std::string &type, Config::XmlComponent &data,
                   safe_ptr<Entity> entity);


            ASerializableObject createObject(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager)
            {
                if (!_objectFactory->hasType(type))
                    throw ExceptionLogger("[Scripting API] Tried to create object of type '" + type + "' but no factory for this type exist in project, trying in plugins ...", Logger::INFO);
                return _objectFactory->createC(type, data, manager);
            }
            
            std::shared_ptr<ASerializableObject> createSharedObject(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager)
            {
                if (!_objectFactory->hasType(type))
                    throw ExceptionLogger("[Scripting API] Tried to create shared object of type '" + type + "' but no factory for this type exist in project, trying in plugins ...", Logger::INFO);
                return _objectFactory->createS(type, data, manager);
            }
            


        private:

    };
}



