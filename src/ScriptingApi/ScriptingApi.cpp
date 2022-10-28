/*
** EPITECH PROJECT, 2020
** ScriptingApi.cpp
** File description:
** header for ScriptingApi.c
*/

#include "ScriptingAPI/ScriptingApi.hpp"
#include <polymorph/Debug.hpp>
#include <polymorph/Core.hpp>

polymorph::engine::ScriptingApi::ScriptingApi(std::unique_ptr<IScriptFactory> factory)
{
    if (_scriptFactory != nullptr)
        throw ExceptionLogger("[Scripting API] Tried to create ScriptingAPI where one exist already.", Logger::MAJOR);
    _scriptFactory = std::move(factory);
}

polymorph::engine::ScriptingApi::~ScriptingApi()
{
    _scriptFactory = nullptr;
}

polymorph::engine::ScriptingApi::Initializer
polymorph::engine::ScriptingApi::create(std::string &type,
                                polymorph::engine::Config::XmlComponent &data,
                               safe_ptr<Entity> entity)
{
    if (!_scriptFactory) {
        entity->Debug.log("[Scripting API] No Script factory loaded to try load component type: '" + type + "'.", Logger::DEBUG);
        return nullptr;
    }
    if (_scriptFactory->hasType(type))
        return _scriptFactory->create(type, data, entity);
    return nullptr;
}
