/*
** EPITECH PROJECT, 2022
** SphereRendererComponent.cpp
** File description:
** SphereRendererComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>

Polymorph::SphereRendererComponent::SphereRendererComponent(Polymorph::GameObject gameObject) : ADrawable3dComponent("SphereRenderer", gameObject)
{

}

void Polymorph::SphereRendererComponent::draw()
{
    sphere->setCenter(Vector3(transform->getPosition()) + offset);
    sphere->draw();
}
