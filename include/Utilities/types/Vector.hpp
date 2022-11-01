/*
** EPITECH PROJECT, 2020
** Vector2.hpp.h
** File description:
** header for Vector2.c
*/

#ifndef ENGINE_VECTOR_HPP
#define ENGINE_VECTOR_HPP


#include <memory>
#include "myxmlpp.hpp"
#include "Config/XmlComponent.hpp"

namespace polymorph::engine
{
    class Vector2;

    class Vector3;

    class Vector3 : public ASerializableObject
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Vector3();

            ~Vector3() override = default;

            Vector3(float x, float y);

            Vector3(float x, float y, float z);

            Vector3(const Vector3 &copy) = default;

            Vector3(const Vector2 &copy);

            Vector3(std::shared_ptr<myxmlpp::Node> &data,
                    Config::XmlComponent &manager);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline bool builtin_type = true;
            float x;
            float y;
            float z;
            static Vector3 Zero;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            Vector3 operator+(const Vector2 &other) const;

            Vector3 &operator+=(const Vector2 &other);

            Vector3 operator-(const Vector2 &other) const;

            Vector3 &operator-=(const Vector2 &other);

            Vector3 operator/(const Vector2 &other) const;

            Vector3 &operator/=(const Vector2 &other);

            Vector3 operator*(const Vector2 &other) const;

            Vector3 &operator*=(const Vector2 &other);

            Vector3 &operator=(const Vector2 &other);

            bool operator==(const Vector2 &other) const;

            bool operator!=(const Vector2 &other) const;

            Vector3 operator+(const Vector3 &other) const;

            Vector3 &operator+=(const Vector3 &other);

            Vector3 operator-(const Vector3 &other) const;

            Vector3 &operator-=(const Vector3 &other);

            Vector3 operator/(const Vector3 &other) const;

            Vector3 &operator/=(const Vector3 &other);

            Vector3 operator*(const Vector3 &other) const;

            Vector3 &operator*=(const Vector3 &other);

            bool operator==(const Vector3 &other) const;

            bool operator!=(const Vector3 &other) const;

            Vector3 operator+(float value) const;

            Vector3 &operator+=(float value);

            Vector3 operator-(float value) const;

            Vector3 &operator-=(float value);

            Vector3 operator/(float value) const;

            Vector3 &operator/=(float value);

            Vector3 operator*(float value) const;

            Vector3 &operator*=(float value);

            Vector3 delta(const Vector2 &other) const;

            float distance(const Vector2 &b) const;

            Vector3 delta(const Vector3 &other) const;

            float distance(const Vector3 &b) const;

            Vector3 delta(float x, float y) const;

            float distance(float x, float y);

            Vector3 delta(float x, float y, float z) const;

            float distance(float x, float y, float z);

            Vector3 reverse() const;

            Vector3 &reverse();

            Vector3 lerp(const Vector3 &destination, float factor) const;

            Vector3 lerp(const Vector2 &destination, float factor) const;
//////////////////////--------------------------/////////////////////////

    };

    class Vector2 : ASerializableObject
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Vector2(float x, float y);

            Vector2(const Vector2 &copy) = default;

            Vector2(const Vector3 &copy);

            Vector2();

            Vector2(std::shared_ptr<myxmlpp::Node> &data,
                    Config::XmlComponent &manager);

            ~Vector2() override = default;
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline bool builtin_type = true;
            float x;
            float y;
            static Vector2 Zero;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            Vector2 operator+(const Vector2 &other) const;

            Vector2 &operator+=(const Vector2 &other);

            Vector2 operator-(const Vector2 &other) const;

            Vector2 &operator-=(const Vector2 &other);

            Vector2 operator/(const Vector2 &other) const;

            Vector2 &operator/=(const Vector2 &other);

            Vector2 operator*(const Vector2 &other) const;

            Vector2 &operator*=(const Vector2 &other);

            bool operator==(const Vector2 &other) const;

            bool operator!=(const Vector2 &other) const;

            Vector2 operator+(const Vector3 &other) const;

            Vector2 &operator+=(const Vector3 &other);

            Vector2 operator-(const Vector3 &other) const;

            Vector2 &operator-=(const Vector3 &other);

            Vector2 operator/(const Vector3 &other) const;

            Vector2 &operator/=(const Vector3 &other);

            Vector2 operator*(const Vector3 &other) const;

            Vector2 &operator*=(const Vector3 &other);

            Vector2 &operator=(const Vector3 &other);

            bool operator==(const Vector3 &other) const;

            bool operator!=(const Vector3 &other) const;

            Vector2 operator+(float value) const;

            Vector2 &operator+=(float value);

            Vector2 operator-(float value) const;

            Vector2 &operator-=(float value);

            Vector2 operator/(float value) const;

            Vector2 &operator/=(float value);

            Vector2 operator*(float value) const;

            Vector2 &operator*=(float value);

            Vector2 delta(const Vector2 &other) const;

            float distance(const Vector2 &b) const;

            Vector2 delta(const Vector3 &other) const;

            float distance(const Vector3 &b) const;

            Vector2 delta(float x, float y) const;

            float distance(float x, float y);

            float distance(float x, float y, float z);

            Vector2 reverse() const;

            Vector2 &reverse();

            Vector2 lerp(const Vector3 &destination, float factor) const;

            Vector2 lerp(const Vector2 &destination, float factor) const;


//////////////////////--------------------------/////////////////////////

    };
}

#endif //ENGINE_VECTOR_HPP
