/*
** EPITECH PROJECT, 2020
** SphereRendererInitalizer.cpp
** File description:
** SphereRendererInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

SphereRendererInitializer::SphereRendererInitializer(Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("SphereRenderer", data, entity)
{

}

void SphereRendererInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("sphere", component->sphere);
}

void SphereRendererInitializer::reference()
{

}
