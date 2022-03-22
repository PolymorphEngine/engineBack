/*
** EPITECH PROJECT, 2022
** Collider2dBoxComponent.cpp
** File description:
** Collider2dBoxComponent.cpp
*/

#include "default/Colliders/ColliderRect2d.hpp"
#include "default/Colliders/ColliderCircle2d.hpp"
#include "default/TransformComponent.hpp"
#include "Exceptions/ExceptionLogger.hpp"
#include "Utilities/Types/Rect.hpp"

using namespace Polymorph;

bool ColliderRect2dComponent::checkCollision(Collider2dComponent &other)
{
    auto tmpPosition = Vector2(transform.getPosition()) + offset;
    auto otherPosition = Vector2(other.transform.getPosition()) + other.offset;
    auto circleShape = dynamic_cast<ColliderCircle2dComponent *>(&other);
    auto boxShape = dynamic_cast<ColliderRect2dComponent *>(&other);

    if (circleShape) {
        return true;
    } else if (boxShape) {
        return Rect::intersect(tmpPosition, size, otherPosition, boxShape->size);
    }
    throw ExceptionLogger("ColliderBox2dComponent::checkCollision: unknown collider type");
}
