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
}

void TextRendererInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("text", component->text);
}

void TextRendererInitializer::reference()
{

}