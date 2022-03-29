/*
** EPITECH PROJECT, 2020
** ScriptingApi.cpp
** File description:
** header for ScriptingApi.c
*/

#include "ScriptingAPI/ScriptingApi.hpp"
#include <Polymorph/Debug.hpp>

Polymorph::ScriptingApi::ScriptingApi(std::unique_ptr<IScriptFactory> factory)
{
    if (_scriptFactory != nullptr)
        throw ExceptionLogger("[Scripting API] Tried to create ScriptingAPI where one exist already.", Logger::MAJOR);
    _scriptFactory = std::move(factory);
}

Polymorph::ScriptingApi::~ScriptingApi()
{
    _scriptFactory = nullptr;
}

Polymorph::ScriptingApi::Initializer
Polymorph::ScriptingApi::create(std::string &type,
                                Polymorph::Config::XmlComponent &data,
                                Polymorph::Entity &entity)
{
    if (!_scriptFactory) {
        Logger::log("[Scripting API] No Script factory loaded to try load component type: '" + type + "'.", Logger::DEBUG);
        return nullptr;
    }
    return _scriptFactory->create(type, data, entity);
}
