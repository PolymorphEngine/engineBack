/*
** EPITECH PROJECT, 2020
** BoxRendererInitalizer.cpp
** File description:
** BoxRendererInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

BoxRendererInitializer::BoxRendererInitializer(Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("BoxRenderer", data, entity)
{

}

void BoxRendererInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("box", component->box);
    data.setProperty("texture", component->texture);
}

void BoxRendererInitializer::reference()
{

}
