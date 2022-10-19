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

bool Polymorph::Circle::intersect(const Polymorph::Rect &rect,
                                const Polymorph::Circle &circle)
{
    auto circleDistanceX = fabs(circle.center.x - rect.x);
    auto circleDistanceY = fabs(circle.center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + circle.radius) || circleDistanceY > (rect.height/2 + circle.radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(circle.radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &position,
                                const Polymorph::Vector2 &size,
                                const Polymorph::Circle &circle)
{
    auto circleDistanceX = fabs(circle.center.x - position.x);
    auto circleDistanceY = fabs(circle.center.y - position.y);

    if (circleDistanceX > (size.x/2 + circle.radius) || circleDistanceY > (size.y/2 + circle.radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(circle.radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &position,
                                const Polymorph::Vector2 &size,
                                const Polymorph::Vector2 &center,
                                float radius)
{
    auto circleDistanceX = fabs(center.x - position.x);
    auto circleDistanceY = fabs(center.y - position.y);

    if (circleDistanceX > (size.x/2 + radius) || circleDistanceY > (size.y/2 + radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Rect &rect,
                                const Polymorph::Vector2 &center,
                                float radius)
{
    auto circleDistanceX = fabs(center.x - rect.x);
    auto circleDistanceY = fabs(center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + radius) || circleDistanceY > (rect.height/2 + radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Circle &circle,
                                  const Polymorph::Rect &rect)
{
    auto circleDistanceX = fabs(circle.center.x - rect.x);
    auto circleDistanceY = fabs(circle.center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + circle.radius) || circleDistanceY > (rect.height/2 + circle.radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(circle.radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Circle &circle,
                                  const Polymorph::Vector2 &position,
                                  const Polymorph::Vector2 &size)
{
    auto circleDistanceX = fabs(circle.center.x - position.x);
    auto circleDistanceY = fabs(circle.center.y - position.y);

    if (circleDistanceX > (size.x/2 + circle.radius) || circleDistanceY > (size.y/2 + circle.radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(circle.radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &center, float radius,
                                  const Polymorph::Vector2 &position,
                                  const Polymorph::Vector2 &size)
{
    auto circleDistanceX = fabs(center.x - position.x);
    auto circleDistanceY = fabs(center.y - position.y);

    if (circleDistanceX > (size.x/2 + radius) || circleDistanceY > (size.y/2 + radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(radius, 2)));
}

bool Polymorph::Circle::intersect(const Polymorph::Vector2 &center, float radius,
                                  const Polymorph::Rect &rect)
{
    auto circleDistanceX = fabs(center.x - rect.x);
    auto circleDistanceY = fabs(center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + radius) || circleDistanceY > (rect.height/2 + radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(radius, 2)));
}

Polymorph::Circle::Circle(std::shared_ptr<myxmlpp::Node> &data,
                          Polymorph::Config::XmlComponent &manager)
{
    manager.setSubProperty("center", data, center);
    manager.setSubProperty("radius", data, radius);
}
