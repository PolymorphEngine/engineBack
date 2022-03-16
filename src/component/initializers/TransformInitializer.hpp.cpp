/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.cpp
** File description:
** TransformInitializer.hpp.cpp
*/

#include "factory/ComponentInitializer.hpp"
#include "factory/initializers/TransformInitializer.hpp"
#include "default/TransformComponent.hpp"
#include "XmlComponent.hpp"

namespace Polymorph
{
    TransformInitializer::TransformInitializer(Config::XmlComponent &data, Entity &entity)
        : AComponentInitializer( "Transform", data, entity){
        component = std::shared_ptr<Component>(new TransformComponent(entity));
    }
    
    std::shared_ptr<Component> &TransformInitializer::build()
    {
        auto trm = std::dynamic_pointer_cast<TransformComponent>(component);
        data.setProperty("position", trm->position);
        data.setProperty("scale", trm->position);
        data.setProperty("rotation", trm->position);
        return component;
    }
    
    void TransformInitializer::reference(){
        std::vector<GameObject> refs;
        data.setProperty("children", refs);

        auto trm = std::dynamic_pointer_cast<TransformComponent>(component);
        for (auto &ref: refs)
        {
            if (!ref)
                Logger::Log("Ref child null", Logger::DEBUG);
            else if (!ref->transform) {
                Logger::Log("Impossible has happened ... TRANSFORM IS NULL !!!", Logger::DEBUG);
            }
            else
                ref->transform->SetParent(trm);
        }
    }
}
