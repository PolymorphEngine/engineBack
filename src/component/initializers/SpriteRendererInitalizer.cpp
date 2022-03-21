/*
** EPITECH PROJECT, 2020
** SpriteRendererInitalizer.cpp
** File description:
** SpriteRendererInitalizer.cpp
*/

#include "factory/ComponentFactory.hpp"
#include "default/drawables/SpriteRendererComponent.hpp"
#include "XmlComponent.hpp"
#include "GraphicalAPI/Sprite.hpp"

using namespace Polymorph;

SpriteRendererInitializer::SpriteRendererInitializer(
        Config::XmlComponent &data, Entity &entity): AComponentInitializer("SpriteRenderer",data, entity)
{
    
}

std::shared_ptr<Component> &SpriteRendererInitializer::build()
{
    auto trm = std::dynamic_pointer_cast<SpriteRendererComponent>(component);
    data.setProperty("offset", trm->offset);
    data.setProperty("sprite", *trm->sprite);
    return component;
}

void SpriteRendererInitializer::reference()
{

}
