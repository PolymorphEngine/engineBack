/*
** EPITECH PROJECT, 2020
** Vector2.hpp.h
** File description:
** header for Vector2.c
*/

#ifndef ENGINE_VECTOR_HPP
#define ENGINE_VECTOR_HPP


namespace Polymorph
{
    class Vector2;
    class Vector3
    {
        public:
            Vector3(float x, float y): x(x), y(y), z(0){};
            Vector3(float x, float y, float z): x(x), y(y), z(z){};
            Vector3(Vector3 &copy) = default;
            Vector3 operator+(Vector3 &other) const;
            Vector3 &operator+=(Vector3 &other);
            explicit Vector3(Vector2 &copy);
            Vector3(): x(0), y(0), z(0){};
            ~Vector3() = default;

            float x;
            float y;
            float z;
            static Vector3 Zero;
    };



    class Vector2
    {
        public:
            Vector2(float x, float y): x(x), y(y){};
            Vector2(Vector2 &copy) = default;
            explicit Vector2(Vector3 &copy);
            Vector2(): x(0), y(0){};
            ~Vector2() = default;

            float x;
            float y;
            static Vector2 Zero;
    };
}

#endif //ENGINE_VECTOR_HPP
