/*
** EPITECH PROJECT, 2020
** Collider2dComponent.cpp
** File description:
** Collider2dComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Events.hpp>

using namespace Polymorph;

void ACollider2dComponent::_broadCastCollisionStay(ACollider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionStay(collider);
}

void ACollider2dComponent::_broadCastCollisionEnter(ACollider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionEnter(collider);
}

void ACollider2dComponent::_broadCastCollisionExit(ACollider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionExit(collider);
}


void ACollider2dComponent::update()
{
    for (auto c2 = _colliderIdx + 1; c2 != _allColliders.end(); ++c2)
    {
        for (; !(*c2)->enabled && c2 != _allColliders.end(); ++c2);
        if (c2 == _allColliders.end())
            return;
        _checkCollisionToBroadCast(**c2);
        (*c2)->_checkCollisionToBroadCast(*this);
    }
}


void ACollider2dComponent::_checkCollisionToBroadCast(ACollider2dComponent &collider)
{
    bool collided = checkCollision(collider);

    if (collided
    && _encountered.contains(collider.gameObject.getId())
    && _encountered[collider.gameObject.getId()])
    {
        _broadCastCollisionStay(collider);
    }

    else if (collided
    && (!_encountered.contains(collider.gameObject.getId())
    || !_encountered[collider.gameObject.getId()]) )
    {
        _encountered[collider.gameObject.getId()] = true;
        _broadCastCollisionEnter(collider);
    }

    else if (!collided &&
        _encountered.contains(collider.gameObject.getId())
        && _encountered[collider.gameObject.getId()])
    {
        _broadCastCollisionExit(collider);
        _encountered[collider.gameObject.getId()] = false;
    }
}

ACollider2dComponent::ACollider2dComponent(Entity &gameObject, std::string type)
:Component(type, gameObject)
{
    _allColliders.push_back(this);

    _colliderIdx = _allColliders.end() - 1;
}

ACollider2dComponent::~ACollider2dComponent()
{
    _allColliders.erase(_colliderIdx);
}
