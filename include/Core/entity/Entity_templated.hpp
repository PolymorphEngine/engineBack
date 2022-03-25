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

#include "Utilities/safe_ptr.hpp"
#include "Core/Engine.hpp"

#include "ComponentsFactory/ComponentFactory.hpp"
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Log/Logger.hpp"
#include "Core/entity/Entity.hpp"
#include "Core/component/base/Component.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{

    template <typename T>
    safe_ptr<T> Entity::getComponent()
    {
        for (auto &ci: _components) {
            for (auto &c: ci.second) {
                auto toAdd = std::dynamic_pointer_cast<T>((*c).get());
                if (toAdd != nullptr) {
                    return safe_ptr<T>(toAdd);
                }
            }
        }
        return safe_ptr<T>(nullptr);
    }

    template<typename T>
    std::vector<safe_ptr<T>> Entity::getComponents()
    {
        std::vector<safe_ptr<T>> toReturn;

        for (auto &ci: _components) {
            for (auto &c: ci.second) {
                auto toAdd = std::dynamic_pointer_cast<T>((*c).get());
                if (toAdd != nullptr) {
                    toReturn.push_back(safe_ptr<T>(toAdd));
                }
            }
        }

        return toReturn;
    }

    template<typename T>
    safe_ptr<T> Entity::addComponent()
    {
        std::shared_ptr<T> component(new T(*this));

        std::string t = component->getType();
        component.reset();
        if (componentExist(t))
            return safe_ptr<T>(nullptr);
        //TODO: maybe throw/Log ?
        Config::XmlComponent &config = _game.getDefaultConfig(t);

        std::shared_ptr<IComponentInitializer> c = ComponentFactory::create(t, config, *this);
        if (c == nullptr)
            c = ScriptingApi::create(t, config, *this);

        if (c == nullptr) {
            Logger::log("Unknown component to add at runtime: '" + t +
                        "'\n\t(this error maybe occurs because you need to add an initializer for the component in the factory)",
                        Logger::MINOR);
            return safe_ptr<T>(nullptr);
        }

        if (config.getType() != "Empty") {
            c->build();
            c->reference();
        }
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
    bool Entity::componentExist()
    {
        for (auto &ci: _components) {
            for (auto &c: ci.second)
            {
                if (std::dynamic_pointer_cast<T>((*c).get() ) != nullptr)
                    return true;
            }
        }
        return false;
    }
}

#endif //ENGINE_ENTITY_TEMPLATED_HPP
