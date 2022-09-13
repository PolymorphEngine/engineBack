/*
** EPITECH PROJECT, 2020
** MeshRendererInitalizer.cpp
** File description:
** MeshRendererInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

MeshRendererInitializer::MeshRendererInitializer(Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("MeshRenderer", data, entity)
{

}

void MeshRendererInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("mesh", component->mesh);
    data.setProperty("texture", component->texture);
}

void MeshRendererInitializer::reference()
{

}
