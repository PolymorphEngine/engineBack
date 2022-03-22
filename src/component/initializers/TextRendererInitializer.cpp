/*
** EPITECH PROJECT, 2020
** TextRendererInitializer.cpp
** File description:
** TextRendererInitializer.cpp
*/
#include "factory/ComponentFactory.hpp"
#include "default/drawables/TextRendererComponent.hpp"
#include "XmlComponent.hpp"
#include "GraphicalAPI/TextModule.hpp"

using namespace Polymorph;

TextRendererInitializer::TextRendererInitializer(
        Config::XmlComponent &data, Entity &entity): AComponentInitializer("TextRenderer",data, entity)
{

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