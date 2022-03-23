/*
** EPITECH PROJECT, 2020
** Rect.hpp.h
** File description:
** header for Rect.c
*/

#ifndef ENGINE_RECT_HPP
#define ENGINE_RECT_HPP

#include "Vector.hpp"

namespace Polymorph
{
    class Circle;
    class Rect
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Rect(float x, float y, float w, float h)
            : x(x), y(y), width(w), height(h){};

            Rect(Vector2 &position, float w, float h)
            : x(position.x), y(position.y), width(w), height(h){};

            Rect(Vector2 &position, Vector2 &size)
            : x(position.x), y(position.y), width(size.x), height(size.y){};

            Rect(float x, float y, Vector2 &size)
            : x(x), y(y), width(size.x), height(size.y){};
            ~Rect() = default;

            Rect(Rect &copy) = default;;

            Rect(): x(0), y(0), width(0), height(0){};
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            float x;
            float y;
            float width;
            float height;
            static Rect Zero;
//////////////////////--------------------------/////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            static bool intersect(const Rect &rect1, const Rect &rect2);
            static bool intersect(const Vector2 &position, const Vector2 &size, const Rect &rect);
            static bool intersect(const Rect &rect, const Vector2 &position, const Vector2 &size);
            static bool intersect(const Vector2 &position1, const Vector2 &size1, const Vector2 &position2, const Vector2 &size2);

            static bool intersect(const Rect &rect, const Circle &circle);
            static bool intersect(const Vector2 &position, const Vector2 &size, const Circle &circle);
            static bool intersect(const Vector2 &position, const Vector2 &size, const Vector2 &center, float radius);
            static bool intersect(const Rect &rect, const Vector2 &center, float radius);
            static bool intersect(const Circle &circle, const Rect &rect);
            static bool intersect(const Circle &circle, const Vector2 &position, const Vector2 &size);
            static bool intersect(const Vector2 &center, float radius, const Vector2 &position, const Vector2 &size);
            static bool intersect(const Vector2 &center, float radius, const Rect &rect);

//////////////////////--------------------------/////////////////////////

    };
}


#endif //ENGINE_RECT_HPP
