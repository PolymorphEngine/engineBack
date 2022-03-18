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
    class Vector3;

    class Vector3
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Vector3();
            ~Vector3() = default;
            Vector3(float x, float y);
            Vector3(float x, float y, float z);
            Vector3(const Vector3 &copy) = default;
            explicit Vector3(const Vector2 &copy);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            float x;
            float y;
            float z;
            static Vector3 Zero;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            Vector3 operator+(const Vector3 &other) const;
            Vector3 &operator+=(const Vector3 &other);
            Vector3 operator-(const Vector3 &other) const;
            Vector3 &operator-=(const Vector3 &other);
            bool operator==(const Vector3 &other) const;
            bool operator!=(const Vector3 &other) const;
//////////////////////--------------------------/////////////////////////

    };



    class Vector2
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Vector2(float x, float y);
            Vector2(const Vector2 &copy) = default;
            explicit Vector2(const Vector3 &copy);
            Vector2();
            ~Vector2() = default;
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            float x;
            float y;
            static Vector2 Zero;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            Vector2 operator+(const Vector2 &other) const;
            Vector2 &operator+=(const Vector2 &other);
            Vector2 operator-(const Vector2 &other) const;
            Vector2 &operator-=(const Vector2 &other);
            bool operator==(const Vector2 &other) const;
//////////////////////--------------------------/////////////////////////

    };
}

#endif //ENGINE_VECTOR_HPP
