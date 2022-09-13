/*
** EPITECH PROJECT, 2022
** ColliderMesh3dInitializer.cpp
** File description:
** ColliderMesh3dInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>
#include "ComponentsFactory/initializers/ColliderMesh3dInitializer.hpp"


Polymorph::ColliderMesh3dInitializer::ColliderMesh3dInitializer(Polymorph::Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("ColliderMesh3dd", data, entity)
{
}
void Polymorph::ColliderMesh3dInitializer::build()
{
    data.setProperty("offset", component->offset);
   // component->DebugTexture = nullptr;
    data.setProperty("DebugTexture", component->DebugTexture);
}

void Polymorph::ColliderMesh3dInitializer::reference()
{
    data.setProperty("renderer", component->renderer);
}
