/*
** EPITECH PROJECT, 2020
** ScriptingApi.cpp
** File description:
** header for ScriptingApi.c
*/

#include "ScriptingAPI/ScriptingApi.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"
#include <Polymorph/Debug.hpp>

Polymorph::ScriptingApi::Initializer
Polymorph::ScriptingApi::create(std::string &type,
                                Polymorph::Config::XmlComponent &data,
                                Polymorph::Entity &entity)
{
    if (!_instance || !_instance->_scriptFactory)
    {
        Logger::log("[Scripting API] No Script factory loaded to try load component type: '"+type+"'.", Logger::DEBUG);
        return nullptr;
    }
    return _instance->_scriptFactory->create(type, data, entity);
}

Polymorph::ScriptingApi::ScriptingApi(std::string libPath)
{
    if (_instance != nullptr)
        throw ExceptionLogger("[Scripting API] Tried to create ScriptingAPI where one exist already.", Logger::MAJOR);
    _instance = this;
    try 
    {
        loadHandler(libPath);
    } catch (ExceptionLogger &e) {
        Logger::log("[Scripting API] "+ std::string(e.what()), Logger::MAJOR);
        return;
    }
    _loadSymbols();
    _loadFactory();
}

void *Polymorph::ScriptingApi::getHandler()
{
    if (!_instance)
        return nullptr;
    return _instance->_handler;
}

void Polymorph::ScriptingApi::_loadSymbols()
{
    try {
        _loader = loadSymbol<ScriptFactoryLoader, ScriptingApi>("createFactory");
        _unloader = loadSymbol<ScriptFactoryUnLoader, ScriptingApi>("destroyFactory");
    } catch(...) {}
}

void Polymorph::ScriptingApi::_loadFactory()
{
    if (_loader != nullptr)
        _scriptFactory = _loader();
}

Polymorph::ScriptingApi::~ScriptingApi()
{
    if (_unloader != nullptr)
        _unloader(_scriptFactory);
    _instance = nullptr;
}
