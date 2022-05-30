/*
** EPITECH PROJECT, 2022
** Rect.cpp
** File description:
** Rect.cpp
*/

#include <Polymorph/Types.hpp>
#include "Rect.hpp"


bool Polymorph::Rect::intersect(const Polymorph::Rect &rect1, const Polymorph::Rect &rect2)
{
    if (rect1.x + rect1.width < rect2.x
        || rect1.x > rect2.x + rect2.width
        || rect1.y + rect1.height < rect2.y
        || rect1.y > rect2.y + rect2.height)
        return false;
    return true;
}

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &position,
                                const Polymorph::Vector2 &size,
                                const Polymorph::Rect &rect)
{
    if (rect.x + rect.width < position.x
        || rect.x > position.x + size.x
        || rect.y + rect.height < position.y
        || rect.y > position.y + size.y)
        return false;
    return true;
}

bool Polymorph::Rect::intersect(const Polymorph::Rect &rect,
                                const Polymorph::Vector2 &position,
                                const Polymorph::Vector2 &size)
{
    if (rect.x + rect.width < position.x
        || rect.x > position.x + size.x
        || rect.y + rect.height < position.y
        || rect.y > position.y + size.y)
        return false;
    return true;
}

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &position1,
                                const Polymorph::Vector2 &size1,
                                const Polymorph::Vector2 &position2,
                                const Polymorph::Vector2 &size2)
{
    if (position1.x + size1.x < position2.x
        || position1.x > position2.x + size2.x
        || position1.y + size1.y < position2.y
        || position1.y > position2.y + size2.y)
        return false;
    return true;
}

bool Polymorph::Rect::intersect(const Polymorph::Rect &rect,
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

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &position,
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

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &position,
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

bool Polymorph::Rect::intersect(const Polymorph::Rect &rect,
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

bool Polymorph::Rect::intersect(const Polymorph::Circle &circle,
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

bool Polymorph::Rect::intersect(const Polymorph::Circle &circle,
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

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &center, float radius,
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

bool Polymorph::Rect::intersect(const Polymorph::Vector2 &center, float radius,
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

Polymorph::Rect::Rect(std::shared_ptr<myxmlpp::Node> &data,
                      Polymorph::Config::XmlComponent &manager)
{
    auto r = *data->begin();
    
    x = r->findAttribute("x")->getValueFloat();
    y = r->findAttribute("y")->getValueFloat();
    width = r->findAttribute("width")->getValueFloat();
    height = r->findAttribute("height")->getValueFloat();
}
