/*
** EPITECH PROJECT, 2020
** Circle.hpp
** File description:
** header for Circle.c
*/

#ifndef ENGINE_CIRCLE_HPP
#define ENGINE_CIRCLE_HPP

#include "Vector.hpp"

namespace Polymorph
{

    class Circle
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
    public:

        Circle(const Vector2 &center, float radius);
        Circle(const Circle &circle);
        Circle(float x, float y, float radius);
        ~Circle() = default;
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Vector2 center;
            float radius;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static bool intersect(const Circle &circle1, const Circle &circle2);
            static bool intersect(const Circle &circle, const Vector2 &center, float radius);
            static bool intersect(const Vector2 &center, float radius, const Circle &circle);
            static bool intersect(const Vector2 &center1, float radius1, const Vector2 &center2, float radius2);
//////////////////////--------------------------/////////////////////////

    };

}


#endif //ENGINE_CIRCLE_HPP
