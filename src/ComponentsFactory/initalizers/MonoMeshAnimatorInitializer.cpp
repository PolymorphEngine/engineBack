/*
** EPITECH PROJECT, 2022
** MonoMeshAnimatorInitializer.cpp
** File description:
** MonoMeshAnimatorInitializer.cpp
*/


#include "ComponentsFactory/initializers/MonoMeshAnimatorInitializer.hpp"

Polymorph::MonoMeshAnimatorInitializer::MonoMeshAnimatorInitializer(Polymorph::Config::XmlComponent &data,
    Polymorph::GameObject entity) : AComponentInitializer<MonoMeshAnimatorComponent>("MonoMeshAnimator", data, entity)
{

}

void Polymorph::MonoMeshAnimatorInitializer::build()
{
    data.setProperty("currentAnimationName", component->currentAnimationName);
    data.setProperty("animEnabled", component->animEnabled);
    data.setProperty("anims", component->anims);

}

void Polymorph::MonoMeshAnimatorInitializer::reference()
{
    data.setProperty("target", component->target);
}

