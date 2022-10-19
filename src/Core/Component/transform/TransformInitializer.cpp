/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.cpp
** File description:
** TransformInitializer.hpp.cpp
*/


#include <Polymorph/Core.hpp>
#include "Core/Component/transform/TransformInitializer.hpp"

namespace Polymorph
{
    TransformInitializer::TransformInitializer(Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("Transform", data, entity)
        {}

    void TransformInitializer::build()
    {
        data.setProperty("position", component->_position);
        data.setProperty("scale", component->_scale);
        data.setProperty("rotation", component->_rotation);
    }

    void TransformInitializer::reference()
    {
        std::vector<GameObject> refs;
        data.setProperty("children", refs);

        for (auto &ref: refs) {
            if (!ref)
                continue;
            if (ref->isPrefab())
                SceneManager::instantiate(ref, component->transform, false);
            else
                ref->transform->setParent(Transform(component));
        }
    }
}
