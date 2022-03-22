/*
** EPITECH PROJECT, 2022
** Rect.cpp
** File description:
** Rect.cpp
*/

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
