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

void Collider2dComponent::_broadCastCollisionStay(Collider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionStay(collider);
}

void Collider2dComponent::_broadCastCollisionEnter(Collider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionEnter(collider);
}

void Collider2dComponent::_broadCastCollisionExit(Collider2dComponent &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionExit(collider);
}


void Collider2dComponent::update()
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


void Collider2dComponent::_checkCollisionToBroadCast(Collider2dComponent &collider)
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

Collider2dComponent::Collider2dComponent(Entity &gameObject, std::string &type)
:Component(type, gameObject)
{
    _allColliders.push_back(this);
    
    _colliderIdx = _allColliders.end() - 1;
}

Collider2dComponent::~Collider2dComponent()
{
    _allColliders.erase(_colliderIdx);
}
