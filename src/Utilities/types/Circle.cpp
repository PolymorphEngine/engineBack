/*
** EPITECH PROJECT, 2022
** Circle.cpp
** File description:
** Circle.cpp
*/

#include <Polymorph/Types.hpp>
#include <cmath>

Polymorph::Circle::Circle(const Polymorph::Vector2 &center, float radius): center(center), radius(radius)
{
}

Polymorph::Circle::Circle(const Polymorph::Circle &circle): center(circle.center), radius(circle.radius)
{
}

Polymorph::Circle::Circle(float x, float y, float radius): center(x, y), radius(radius)
{
}

bool Polymorph::Circle::intersect(const Polymorph::Circle &circle1,
                                  const Polymorph::Circle &circle2)
{
    auto tmp = circle1.center.delta(circle2.center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle1.radius + circle2.radius)
        return true;
    return false;
}

bool Polymorph::Circle::intersect(const Polymorph::Circle &circle,
                                  const Polymorph::Vector2 &center,
                                  float radius)
{
    auto tmp = circle.center.delta(center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle.radius + radius)
        return true;
    return false;
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &center,
                                  float radius,
                                  const Polymorph::Circle &circle)
{
    auto tmp = circle.center.delta(center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle.radius + radius)
        return true;
    return false;
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &center1,
                                  float radius1,
                                  const Polymorph::Vector2 &center2,
                                  float radius2)
{
    auto tmp = center1.delta(center2);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= radius1 + radius2)
        return true;
    return false;
}
