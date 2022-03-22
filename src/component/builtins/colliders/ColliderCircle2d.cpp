/*
** EPITECH PROJECT, 2022
** Collider2dCircleComponent.cpp
** File description:
** Collider2dCircleComponent.cpp
*/

#include "default/Colliders/ColliderCircle2d.hpp"
#include "default/Colliders/ColliderRect2d.hpp"
#include "default/TransformComponent.hpp"
#include "Exceptions/ExceptionLogger.hpp"
#include "Utilities/Types/Circle.hpp"

using namespace Polymorph;

bool ColliderCircle2dComponent::checkCollision(Collider2dComponent &other)
{
    auto tmpPosition = Vector2(transform.getPosition()) + offset;
    auto otherPosition = Vector2(other.transform.getPosition()) + other.offset;
    auto circleShape = dynamic_cast<ColliderCircle2dComponent *>(&other);
    auto boxShape = dynamic_cast<ColliderRect2dComponent *>(&other);

    if (circleShape) {
        return Circle::intersect(tmpPosition, radius, otherPosition, circleShape->radius);
    } else if (boxShape) {
        return false;
    }
    throw ExceptionLogger("ColliderBox2dComponent::checkCollision: unknown collider type");
}
