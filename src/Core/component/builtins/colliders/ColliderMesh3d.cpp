/*
** EPITECH PROJECT, 2022
** ColliderMesh3d.cpp
** File description:
** ColliderMesh3d.cpp
*/

#include <Polymorph/Components.hpp>
#include "ColliderSphere3d.hpp"
#include "ColliderMesh3d.hpp"
#include "BoxCollider.hpp"

Polymorph::ColliderMesh3dComponent::ColliderMesh3dComponent(Polymorph::GameObject gameObject) : ACollider3dComponent(gameObject, "ColliderMesh3d")
, DebugTexture(nullptr)
{

}

void Polymorph::ColliderMesh3dComponent::onAwake()
{
    ACollider3dComponent::onAwake();
    auto scale = renderer->transform->getScale();
    renderer->mesh->setScale(scale);
}

bool Polymorph::ColliderMesh3dComponent::checkCollision(Polymorph::ACollider3dComponent &other)
{
    auto boxShape = dynamic_cast<BoxColliderComponent *>(&other);
    auto meshShape = dynamic_cast<ColliderMesh3dComponent *>(&other);
    auto sphereShape = dynamic_cast<ColliderSphere3dComponent *>(&other);
    _box = getBox();

    if (!_box) {
        Logger::log("Mesh collider missing box", Logger::MINOR);
        return false;
    }

    if (boxShape && _box)
        return _box->collideWithBox(*(!boxShape->renderer ? boxShape->box : boxShape->renderer->box));
    if (meshShape && _box) {
        auto b = meshShape->getBox();
        if (b)
            return _box->collideWithBox(*b);
        else {
            Logger::log("Mesh collider missing box", Logger::MINOR);
            return false;
        }
    }
    if (sphereShape && _box)
        return _box->collideWithSphere(*(!sphereShape->renderer ? sphereShape->sphere : sphereShape->renderer->sphere));
    throw ExceptionLogger("ColliderMesh3dComponent::checkCollision: unknown collider type");
}

void Polymorph::ColliderMesh3dComponent::setColliderPosition() {
    _box = getBox();
    if (_box)
        _box->setOrigin(transform->getPosition() + offset);
}

std::shared_ptr<Polymorph::BoxModule> Polymorph::ColliderMesh3dComponent::getBox()
{
    if (!_box && !!renderer)
    {
        _box = std::make_shared<BoxModule>(*renderer->mesh);
        if (DebugTexture)
            _box->setTexture(DebugTexture);
    }
    return _box;
}

std::shared_ptr<Polymorph::BoxModule> Polymorph::ColliderMesh3dComponent::regenBox()
{
    _box = std::make_shared<BoxModule>(*renderer->mesh);
    return _box;
}

void Polymorph::ColliderMesh3dComponent::debugDraw()
{
    if (getBox())
    {
        _box->draw();
    }
}
