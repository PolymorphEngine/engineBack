/*
** EPITECH PROJECT, 2022
** BoxColliderInitializer.cpp
** File description:
** BoxColliderInitializer.cpp
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Components.hpp>
#include "ComponentsFactory/initializers/BoxColliderInitializer.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"


Polymorph::BoxColliderInitializer::BoxColliderInitializer(Polymorph::Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("BoxCollider", data, entity)
{
}

void Polymorph::BoxColliderInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("box", component->box);
  //  component->DebugTexture = nullptr;
    data.setProperty("DebugTexture", component->DebugTexture);
    component->box->setTexture(component->DebugTexture);
}

void Polymorph::BoxColliderInitializer::reference()
{
    data.setProperty("renderer", component->renderer);
}
