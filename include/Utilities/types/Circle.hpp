/*
** EPITECH PROJECT, 2020
** Circle.hpp
** File description:
** header for Circle.c
*/

#ifndef ENGINE_CIRCLE_HPP
#define ENGINE_CIRCLE_HPP

#include "Vector.hpp"

namespace polymorph::engine
{
    class Rect;

    class Circle : ASerializableObject
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:

            Circle(const Vector2 &center, float radius);

            Circle(const Circle &circle);

            Circle(float x, float y, float radius);

            Circle(std::shared_ptr<myxmlpp::Node> &data,
                   Config::XmlComponent &manager);

            ~Circle() override = default;
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline bool builtin_type = true;
            Vector2 center;
            float radius;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static bool intersect(const Circle &circle1, const Circle &circle2);

            static bool intersect(const Circle &circle, const Vector2 &center,
                                  float radius);

            static bool intersect(const Vector2 &center, float radius,
                                  const Circle &circle);

            static bool intersect(const Vector2 &center1, float radius1,
                                  const Vector2 &center2, float radius2);

            static bool intersect(const Rect &rect, const Circle &circle);

            static bool intersect(const Vector2 &position, const Vector2 &size,
                                  const Circle &circle);

            static bool intersect(const Vector2 &position, const Vector2 &size,
                                  const Vector2 &center, float radius);

            static bool
            intersect(const Rect &rect, const Vector2 &center, float radius);

            static bool intersect(const Circle &circle, const Rect &rect);

            static bool intersect(const Circle &circle, const Vector2 &position,
                                  const Vector2 &size);

            static bool intersect(const Vector2 &center, float radius,
                                  const Vector2 &position, const Vector2 &size);

            static bool
            intersect(const Vector2 &center, float radius, const Rect &rect);
//////////////////////--------------------------/////////////////////////

    };

}


#endif //ENGINE_CIRCLE_HPP
