/*
** EPITECH PROJECT, 2020
** Collider3dComponent.cpp
** File description:
** Collider3dComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Events.hpp>

using namespace Polymorph;

ACollider3dComponent::ACollider3dComponent(GameObject gameObject, const std::string& type)
        :Component(type, gameObject)
{

}

ACollider3dComponent::~ACollider3dComponent()
{

}

void ACollider3dComponent::onAwake()
{
    _this_safe = gameObject->getComponent<ACollider3dComponent>();
    _instanceStore.registerInstance(_this_safe);
}

void ACollider3dComponent::update()
{
    setColliderPosition();
    _instanceStore.updateInstances();
    auto _allColliders = _instanceStore.getInstances();

    auto thisIt = std::find_if(_allColliders.begin(), _allColliders.end(),
        [this](Collider3d collider) { return *collider == *_this_safe; });

    if (thisIt == _allColliders.end())
        return;
    for (auto c2 = thisIt + 1; c2 != _allColliders.end(); ++c2)
    {
        for (; c2 != _allColliders.end() && (!(*c2) || !(*c2)->enabled || !(*c2)->gameObject->isActive()); ++c2);
        if (c2 == _allColliders.end())
            return;
        (*c2)->setColliderPosition();
        _checkCollisionToBroadCast(***c2);
        (*c2)->_checkCollisionToBroadCast(*this);
    }
    if (Logger::isDebugBuild())
    {
        CameraComponent::Current->begin3dMode();
        debugDraw();
        CameraComponent::Current->end3dMode();
    }
}


void ACollider3dComponent::_broadCastCollisionStay(ACollider3dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider3dHandler>())
        c->onCollisionStay(collider);
}

void ACollider3dComponent::_broadCastCollisionEnter(ACollider3dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider3dHandler>())
        c->onCollisionEnter(collider);
}

void ACollider3dComponent::_broadCastCollisionExit(ACollider3dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider3dHandler>())
        c->onCollisionExit(collider);
}

void ACollider3dComponent::_checkCollisionToBroadCast(ACollider3dComponent &collider)
{
    bool collided = checkCollision(collider);

    if (collided
    && _encountered.contains(collider.gameObject->getId())
    && _encountered[collider.gameObject->getId()])
    {
        _broadCastCollisionStay(collider);
    }

    else if (collided
    && (!_encountered.contains(collider.gameObject->getId())
    || !_encountered[collider.gameObject->getId()]) )
    {
        _encountered[collider.gameObject->getId()] = true;
        _broadCastCollisionEnter(collider);
    }

    else if (!collided &&
        _encountered.contains(collider.gameObject->getId())
        && _encountered[collider.gameObject->getId()])
    {
        _broadCastCollisionExit(collider);
        _encountered[collider.gameObject->getId()] = false;
    }
}
