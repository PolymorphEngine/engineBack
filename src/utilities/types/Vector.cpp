/*
** EPITECH PROJECT, 2020
** Vector.cpp.c
** File description:
** Vector.cpp.c
*/

#include "Types/Vector.hpp"

namespace Polymorph
{
    Vector3::Vector3(Vector2 &copy)
    {
        x = copy.x;
        y = copy.y;
        z = 0;
    }

    Vector2::Vector2(Vector3 &copy)
    {
        x = copy.x;
        y = copy.y;
    }
}