/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.cpp
** File description:
** TransformInitializer.hpp.cpp
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

namespace Polymorph
{
    TransformInitializer::TransformInitializer(Config::XmlComponent &data, Entity &entity)
        : AComponentInitializer( "Transform", data, entity)
    {
        component = std::shared_ptr<Component>(new TransformComponent(entity));
    }

    std::shared_ptr<Component> &TransformInitializer::build()
    {
        auto trm = std::dynamic_pointer_cast<TransformComponent>(component);

        data.setProperty("position", trm->_position);
        data.setProperty("scale", trm->_scale);
        data.setProperty("rotation", trm->_rotation);

        return component;
    }

    void TransformInitializer::reference()
    {
        std::vector<GameObject> refs;
        data.setProperty("children", refs);

        auto trm = std::dynamic_pointer_cast<TransformComponent>(component);
        for (auto &ref: refs) {
            if (!ref)
                Logger::log("Ref child null", Logger::DEBUG);
            else if (!ref->transform)
                Logger::log("Impossible has happened ... TRANSFORM IS NULL !!!",
                            Logger::DEBUG);
            else
                ref->transform->setParent(trm);
        }
    }
}
