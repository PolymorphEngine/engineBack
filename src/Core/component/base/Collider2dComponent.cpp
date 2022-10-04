/*
** EPITECH PROJECT, 2020
** Collider2dComponent.cpp
** File description:
** Collider2dComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Events.hpp>
#include "base/ACollider2d.hpp"


using namespace Polymorph;

void ACollider2dComponent::_broadCastCollisionStay(ACollider2dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider2dHandler>())
        c->onCollisionStay(collider);
}

void ACollider2dComponent::_broadCastCollisionEnter(ACollider2dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider2dHandler>())
        c->onCollisionEnter(collider);
}

void ACollider2dComponent::_broadCastCollisionExit(ACollider2dComponent &collider)
{
    for (auto &c: gameObject->getComponents<ICollider2dHandler>())
        c->onCollisionExit(collider);
}


void ACollider2dComponent::update()
{
    setColliderPosition();
    _instanceStore.updateInstances();
    auto _allColliders = _instanceStore.getInstances();

    auto thisIt = std::find_if(_allColliders.begin(), _allColliders.end(),
                               [this](Collider2d collider) { return *collider == *_this_safe; });

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


void ACollider2dComponent::_checkCollisionToBroadCast(ACollider2dComponent &collider)
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

ACollider2dComponent::ACollider2dComponent(GameObject gameObject, std::string type)
:Component(type, gameObject)
{
}

ACollider2dComponent::~ACollider2dComponent()
{
}

void ACollider2dComponent::onAwake()
{
    _this_safe = gameObject->getComponent<ACollider2dComponent>();
    _instanceStore.registerInstance(_this_safe);
}
