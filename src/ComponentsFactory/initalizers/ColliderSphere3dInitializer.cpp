/*
** EPITECH PROJECT, 2022
** ColliderSphere3dInitializer.cpp
** File description:
** ColliderSphere3dInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include "ComponentsFactory/initializers/ColliderSphere3dInitializer.hpp"


Polymorph::ColliderSphere3dInitializer::ColliderSphere3dInitializer(Polymorph::Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("ColliderMesh3d", data, entity)
{
}
void Polymorph::ColliderSphere3dInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("sphere", component->sphere);
}

void Polymorph::ColliderSphere3dInitializer::reference()
{
    data.setProperty("renderer", component->renderer);
}
