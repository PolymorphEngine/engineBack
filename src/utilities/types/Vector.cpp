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

    Vector3::Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z)
    {

    }

    Vector3::Vector3(float x, float y) : x(x), y(y), z(z)
    {

    }

    Vector2::Vector2(Vector3 &copy)
    {
        x = copy.x;
        y = copy.y;
    }

    Vector2::Vector2(float x, float y): x(x), y(y)
    {
    }

    Vector2::Vector2()
    {
        x = 0;
        y = 0;
    }
}