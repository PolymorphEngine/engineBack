/*
** EPITECH PROJECT, 2022
** BoxCollider.cpp
** File description:
** BoxCollider.cpp
*/

#include <Polymorph/Components.hpp>
#include "ColliderSphere3d.hpp"
#include "BoxCollider.hpp"
#include "ColliderMesh3d.hpp"

Polymorph::BoxColliderComponent::BoxColliderComponent(Polymorph::GameObject gameObject) : ACollider3dComponent(gameObject, "BoxCollider")
, DebugTexture(nullptr)
{
}

bool Polymorph::BoxColliderComponent::checkCollision(Polymorph::ACollider3dComponent &other)
{
    auto boxShape = dynamic_cast<BoxColliderComponent *>(&other);
    auto meshShape = dynamic_cast<ColliderMesh3dComponent *>(&other);
    auto sphereShape = dynamic_cast<ColliderSphere3dComponent *>(&other);

    if (boxShape)
        return (!renderer ? box : renderer->box)->collideWithBox(*(!boxShape->renderer ? boxShape->box : boxShape->renderer->box));
    if (meshShape && meshShape->getBox())
        return meshShape->getBox()->collideWithBox(*(!renderer ? box : renderer->box));
    if (sphereShape)
        return (!renderer ? box : renderer->box)->collideWithSphere(*(!sphereShape->renderer ? sphereShape->sphere : sphereShape->renderer->sphere));
    throw ExceptionLogger("BoxColliderComponent::checkCollision: unknown collider type (check if collider has a module)");
}

void Polymorph::BoxColliderComponent::setColliderPosition()
{
    (!renderer ? box : renderer->box)->setOrigin(transform->getPosition() + offset);
}

void Polymorph::BoxColliderComponent::debugDraw()
{
    if (!!renderer)
        return;
    box->draw();
}
