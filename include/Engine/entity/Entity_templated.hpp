/*
** EPITECH PROJECT, 2020
** Entity_templated.hpp
** File description:
** header for Entity_templated.c
*/

#ifndef ENGINE_ENTITY_TEMPLATED_HPP
#define ENGINE_ENTITY_TEMPLATED_HPP

#include <vector>
#include <map>
#include <unordered_map>

#include "safe_ptr.hpp"
#include "factory/ComponentInitializer.hpp"
#include "Engine.hpp"
#include "Log/Logger.hpp"
#include "factory/ComponentFactory.hpp"
#include "Entity.hpp"
#include "Component.hpp"


template <typename T>
Polymorph::safe_ptr<T> Polymorph::Entity::getComponent()
{
    std::shared_ptr<T> component (new T(*this));

    std::string t = component->getType();
    component.reset();
    if (!componentExist(t))
        return safe_ptr<T>(nullptr);
    if (!_components.contains(t)) {
        for (auto &c : _components.find("Default")->second)
            if (c->getType() == t)
                return safe_ptr<T>(std::dynamic_pointer_cast<T>((*c).get()));
    } else
        return safe_ptr<T>(std::dynamic_pointer_cast<T>( (*_components[t].begin())->get() ) );
    return safe_ptr<T>();
}

template<typename T>
Polymorph::safe_ptr<T> Polymorph::Entity::addComponent()
{
    std::shared_ptr<T> component(new T(*this));

    std::string t = component->getType();
    component.reset();
    if (componentExist(t))
        return safe_ptr<T>();
    //TODO: maybe throw/Log ?
    Config::XmlComponent &config = _game.getDefaultConfig(t);
    std::shared_ptr<AComponentInitializer> c = ComponentFactory::create(t, config, *this);

    if (c == nullptr) {
        Logger::log("Unknown component to add at runtime: '" + t +
                    "' (this error maybe occurs because you need to add an initializer for the component in the factory)",
                    Logger::MINOR);
        return safe_ptr<T>();
    }

    c->build();
    c->reference();
    _components[c->getType()].push_back(c);
    (**c)->onAwake();
    (**c)->setAsAwaked();
    if ((**c)->enabled)
    {
        (**c)->start();
        (**c)->setAsStarted();
    }
    return safe_ptr<T>(std::dynamic_pointer_cast<T>((*c).get()));
}

template <typename T>
bool Polymorph::Entity::componentExist()
{
    std::shared_ptr<T> component(new T(*this));
    std::string type = component->getType();
    std::string def("Default");

    component.reset();
    if (!_components.contains(type)) {
        for (auto &c :  _components.find(def)->second) {
            if (c->getType() == type)
                return true;
        }
    } else if (!_components.find(type)->second.empty())
        return true;
    return false;
}

#endif //ENGINE_ENTITY_TEMPLATED_HPP
