/*
** EPITECH PROJECT, 2020
** TextRendererInitializer.cpp
** File description:
** TextRendererInitializer.cpp
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

using namespace Polymorph;

TextRendererInitializer::TextRendererInitializer(
        Config::XmlComponent &data, Entity &entity): AComponentInitializer("TextRenderer",data, entity)
{
    component = std::shared_ptr<Component>(new TextRendererComponent(entity));

}

std::shared_ptr<Component> &TextRendererInitializer::build()
{
    auto trm = std::dynamic_pointer_cast<TextRendererComponent>(component);
    data.setProperty("offset", trm->offset);
    data.setProperty("text", trm->text);
    return component;
}

void TextRendererInitializer::reference()
{

}