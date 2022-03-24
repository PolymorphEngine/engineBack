/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "DynamicLoader/DynamicLoader.hpp"


namespace Polymorph
{
    namespace Config{class XmlComponent;}

    class IScriptFactory;
    class AComponentInitializer;
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
            using Initializer = std::shared_ptr<AComponentInitializer>;

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
            static Initializer create(std::string &type, Config::XmlComponent &data, Entity &entity);

            static void *getHandler();

        private:
            void _loadFactory();
            void _loadSymbols();
    
    };
}



