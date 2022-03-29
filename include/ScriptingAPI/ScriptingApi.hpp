/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "DynamicLoader/DynamicLoader.hpp"
#include "Utilities/safe_ptr.hpp"


namespace Polymorph
{
    namespace Config{class XmlComponent;}

    class IScriptFactory;
    class IComponentInitializer;
    class Entity;
    
    
    class ScriptingApi : public DynamicLibLoader
    {
    
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ScriptingApi(std::string libPath);

            ~ScriptingApi();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;

        private:
            using ScriptFactoryLoader = IScriptFactory *(*)();
            using ScriptFactoryUnLoader = void (*)(IScriptFactory *);
            ScriptFactoryLoader _loader = nullptr;
            ScriptFactoryUnLoader _unloader = nullptr;
            std::string _handlerPath;
            IScriptFactory *_scriptFactory = nullptr;
            static inline ScriptingApi *_instance = nullptr;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static Initializer create(std::string &type, Config::XmlComponent &data, safe_ptr<Entity> entity);

            static void *getHandler();

        private:
            void _loadFactory();
            void _loadSymbols();
    
    };
}



