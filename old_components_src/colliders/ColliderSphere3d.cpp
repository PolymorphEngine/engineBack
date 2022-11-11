/*
** EPITECH PROJECT, 2022
** ColliderSphere3d.cpp
** File description:
** ColliderSphere3d.cpp
*/

#include <Polymorph/Components.hpp>
#include "ColliderSphere3d.hpp"
#include "ColliderMesh3d.hpp"
#include "BoxCollider.hpp"

Polymorph::ColliderSphere3dComponent::ColliderSphere3dComponent(Polymorph::GameObject gameObject) : ACollider3dComponent(gameObject, "ColliderSphere3d")
{
}

bool Polymorph::ColliderSphere3dComponent::checkCollision(Polymorph::ACollider3dComponent &other)
{
    auto boxShape = dynamic_cast<BoxColliderComponent *>(&other);
    auto meshShape = dynamic_cast<ColliderMesh3dComponent *>(&other);
    auto sphereShape = dynamic_cast<ColliderSphere3dComponent *>(&other);

    if (boxShape)
        return (!renderer ? sphere : renderer->sphere)->collideWithBox(*(!boxShape->renderer ? boxShape->box : boxShape->renderer->box));
    if (meshShape) {
        if (meshShape->getBox())
            return meshShape->getBox()->collideWithSphere(*(!renderer ? sphere : renderer->sphere));
        else {
            Logger::log("Mesh collider missing box", Logger::MINOR);
            return false;
        }
    }
    if (sphereShape)
        return (!renderer ? sphere : renderer->sphere)->collideWithSphere(*(!sphereShape->renderer ? sphereShape->sphere : sphereShape->renderer->sphere));
    throw ExceptionLogger("ColliderSphere3dComponent::checkCollision: unknown collider type");
}

void Polymorph::ColliderSphere3dComponent::setColliderPosition()
{
    sphere->setCenter(transform->getPosition() + offset);
}

void Polymorph::ColliderSphere3dComponent::debugDraw()
{
    if (!!renderer)
        return;
    sphere->draw();
}
