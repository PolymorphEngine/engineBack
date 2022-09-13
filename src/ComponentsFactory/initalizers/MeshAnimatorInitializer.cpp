/*
** EPITECH PROJECT, 2022
** MeshAnimatorInitializer.cpp
** File description:
** MeshAnimatorInitializer.cpp
*/


#include "ComponentsFactory/initializers/MeshAnimatorInitializer.hpp"

Polymorph::MeshAnimatorInitializer::MeshAnimatorInitializer(Polymorph::Config::XmlComponent &data,
                                                            Polymorph::GameObject entity) : AComponentInitializer<MeshAnimatorComponent>("MeshAnimator", data, entity)
{

}

void Polymorph::MeshAnimatorInitializer::build()
{
    data.setProperty("currentAnimationName", component->currentAnimationName);
    data.setProperty("_animations", component->_animations);
}

void Polymorph::MeshAnimatorInitializer::reference()
{
    data.setProperty("target", component->target);
}

