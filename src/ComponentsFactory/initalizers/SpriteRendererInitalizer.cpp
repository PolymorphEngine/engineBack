/*
** EPITECH PROJECT, 2020
** SpriteRendererInitalizer.cpp
** File description:
** SpriteRendererInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

SpriteRendererInitializer::SpriteRendererInitializer(
        Config::XmlComponent &data, Entity &entity): AComponentInitializer("SpriteRenderer",data, entity)
{
    component = std::shared_ptr<Component>(new SpriteRendererComponent(entity));

}

std::shared_ptr<Component> &SpriteRendererInitializer::build()
{
    auto trm = std::dynamic_pointer_cast<SpriteRendererComponent>(component);
    data.setProperty("offset", trm->offset);
    data.setProperty("sprite", trm->sprite);
    return component;
}

void SpriteRendererInitializer::reference()
{

}
