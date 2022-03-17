/*
** EPITECH PROJECT, 2020
** Collider2dComponent.cpp
** File description:
** Collider2dComponent.cpp
*/

#include "default/Colliders/Collider2d.hpp"
#include "interfaces/ICollider2dHandler.hpp"
#include "Entity_templated.hpp"

using namespace Polymorph;

void Collider2dComponent::_broadCastCollisionStay(Collider2d &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionStay(collider);
}

void Collider2dComponent::_broadCastCollisionEnter(Collider2d &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionEnter(collider);
}

void Collider2dComponent::_broadCastCollisionExit(Collider2d &collider)
{
    for (auto &c: gameObject.getComponents<ICollider2dHandler>())
        c->onCollisionExit(collider);
}

void Collider2dComponent::update()
{
    if (not _computer)
        return;
    
    auto actual = 0;
    
    for (auto c1 = _allColliders.begin(); c1 != _allColliders.end(); ++actual)
    {
        for (;!(*c1)->enabled; ++c1);
        for (auto c2 = c1 + 1; c2 != _allColliders.end(); ++c2)
        {
            for (;!(*c2)->enabled; ++c2);
            (*c1)->_checkCollisionToBroadCast((*c2));
        }
    }
}

void Collider2dComponent::_checkCollisionToBroadCast(Collider2d &collider)
{
    bool collided = checkCollision(collider);
    
    if (collided 
    && _encountered.contains(collider->gameObject.getId())
    && _encountered[collider->gameObject.getId()])
    {
        _broadCastCollisionStay(collider);
    }
    
    else if (collided 
    && (!_encountered.contains(collider->gameObject.getId())
    || !_encountered[collider->gameObject.getId()]) )
    {
        _encountered[collider->gameObject.getId()] = true;
        _broadCastCollisionEnter(collider);
    }
    
    else if (!collided &&
        _encountered.contains(collider->gameObject.getId())
        && _encountered[collider->gameObject.getId()])
    {
        _broadCastCollisionExit(collider);
        _encountered[collider->gameObject.getId()] = false;
    }
}
