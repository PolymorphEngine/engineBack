/*
** EPITECH PROJECT, 2022
** Circle.cpp
** File description:
** Circle.cpp
*/

#include <polymorph/Types.hpp>
#include <cmath>


polymorph::engine::Circle::Circle(const polymorph::engine::Vector2 &center, float radius): center(center), radius(radius), ASerializableObject("Circle")
{
}

polymorph::engine::Circle::Circle(const polymorph::engine::Circle &circle): center(circle.center), radius(circle.radius), ASerializableObject("Circle")
{
}

polymorph::engine::Circle::Circle(float x, float y, float radius): center(x, y), radius(radius), ASerializableObject("Circle")
{
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Circle &circle1,
                                  const polymorph::engine::Circle &circle2)
{
    auto tmp = circle1.center.delta(circle2.center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle1.radius + circle2.radius)
        return true;
    return false;
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Circle &circle,
                                  const polymorph::engine::Vector2 &center,
                                  float radius)
{
    auto tmp = circle.center.delta(center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle.radius + radius)
        return true;
    return false;
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &center,
                                  float radius,
                                  const polymorph::engine::Circle &circle)
{
    auto tmp = circle.center.delta(center);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= circle.radius + radius)
        return true;
    return false;
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &center1,
                                  float radius1,
                                  const polymorph::engine::Vector2 &center2,
                                  float radius2)
{
    auto tmp = center1.delta(center2);

    if (sqrtf(powf(tmp.x, 2.0f) + powf(tmp.y, 2.0f)) <= radius1 + radius2)
        return true;
    return false;
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Rect &rect,
                                const polymorph::engine::Circle &circle)
{
    auto circleDistanceX = fabs(circle.center.x - rect.x);
    auto circleDistanceY = fabs(circle.center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + circle.radius) || circleDistanceY > (rect.height/2 + circle.radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(circle.radius, 2)));
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &position,
                                const polymorph::engine::Vector2 &size,
                                const polymorph::engine::Circle &circle)
{
    auto circleDistanceX = fabs(circle.center.x - position.x);
    auto circleDistanceY = fabs(circle.center.y - position.y);

    if (circleDistanceX > (size.x/2 + circle.radius) || circleDistanceY > (size.y/2 + circle.radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(circle.radius, 2)));
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &position,
                                const polymorph::engine::Vector2 &size,
                                const polymorph::engine::Vector2 &center,
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

bool polymorph::engine::Circle::intersect(const polymorph::engine::Rect &rect,
                                const polymorph::engine::Vector2 &center,
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

bool polymorph::engine::Circle::intersect(const polymorph::engine::Circle &circle,
                                  const polymorph::engine::Rect &rect)
{
    auto circleDistanceX = fabs(circle.center.x - rect.x);
    auto circleDistanceY = fabs(circle.center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + circle.radius) || circleDistanceY > (rect.height/2 + circle.radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(circle.radius, 2)));
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Circle &circle,
                                  const polymorph::engine::Vector2 &position,
                                  const polymorph::engine::Vector2 &size)
{
    auto circleDistanceX = fabs(circle.center.x - position.x);
    auto circleDistanceY = fabs(circle.center.y - position.y);

    if (circleDistanceX > (size.x/2 + circle.radius) || circleDistanceY > (size.y/2 + circle.radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(circle.radius, 2)));
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &center, float radius,
                                  const polymorph::engine::Vector2 &position,
                                  const polymorph::engine::Vector2 &size)
{
    auto circleDistanceX = fabs(center.x - position.x);
    auto circleDistanceY = fabs(center.y - position.y);

    if (circleDistanceX > (size.x/2 + radius) || circleDistanceY > (size.y/2 + radius))
        return false;
    if (circleDistanceX <= (size.x/2) || circleDistanceY <= (size.y/2))
        return true;
    return ((pow((circleDistanceX - size.x/2), 2) + pow((circleDistanceY - size.y/2), 2)) <= (pow(radius, 2)));
}

bool polymorph::engine::Circle::intersect(const polymorph::engine::Vector2 &center, float radius,
                                  const polymorph::engine::Rect &rect)
{
    auto circleDistanceX = fabs(center.x - rect.x);
    auto circleDistanceY = fabs(center.y - rect.y);

    if (circleDistanceX > (rect.width/2 + radius) || circleDistanceY > (rect.height/2 + radius))
        return false;
    if (circleDistanceX <= (rect.width/2) || circleDistanceY <= (rect.height/2))
        return true;
    return ((pow((circleDistanceX - rect.width/2), 2) + pow((circleDistanceY - rect.height/2), 2)) <= (pow(radius, 2)));
}

polymorph::engine::Circle::Circle(std::shared_ptr<myxmlpp::Node> &data,
                          polymorph::engine::Config::XmlComponent &manager): ASerializableObject("Circle")
{
    manager.setSubProperty("center", data, center);
    manager.setSubProperty("radius", data, radius);
}
