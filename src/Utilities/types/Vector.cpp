/*
** EPITECH PROJECT, 2020
** Vector.cpp.c
** File description:
** Vector.cpp.c
*/

#include <Polymorph/Types.hpp>
#include "Vector.hpp"
#include <cmath>


namespace Polymorph
{
    
    // VECTOR3
    
    Vector3::Vector3(const Vector2 &copy)
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
    {}

    Vector3::Vector3(float x, float y) : x(x), y(y), z(0)
    {}

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 &Vector3::operator+=(const Vector3 &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    bool Vector3::operator==(const Vector3 &other) const {
        if (this->x != other.x || this->y != other.y || this->z != other.z)
            return false;
        return true;
    }

    bool Vector3::operator!=(const Vector3 &other) const {
        return !(*this == other);
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 &Vector3::operator-=(const Vector3 &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3 Vector3::operator+(const Vector2 &other) const {
      return {x + other.x, y + other.y, z};
    }

    Vector3 &Vector3::operator+=(const Vector2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector3 Vector3::operator-(const Vector2 &other) const
    {
        return {x - other.x, y - other.y, z};
    }

    Vector3 &Vector3::operator-=(const Vector2 &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector3 Vector3::operator/(const Vector2 &other) const
    {
        return {x / other.x, y / other.y, z};
    }

    Vector3 &Vector3::operator/=(const Vector2 &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector3 Vector3::operator*(const Vector2 &other) const
    {
        return {x * other.x, y * other.y, z};
    }

    Vector3 &Vector3::operator*=(const Vector2 &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector3 &Vector3::operator=(const Vector2 &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool Vector3::operator==(const Vector2 &other) const
    {
        return (x == other.x && y == other.y);
    }

    bool Vector3::operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }

    Vector3 Vector3::operator/(const Vector3 &other) const
    {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vector3 &Vector3::operator/=(const Vector3 &other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vector3 Vector3::operator*(const Vector3 &other) const
    {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector3 &Vector3::operator*=(const Vector3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vector3 Vector3::operator+(float value) const
    {
        return {x + value, y + value, z + value};
    }

    Vector3 &Vector3::operator+=(float value)
    {
        x += value;
        y += value;
        z += value;

        return *this;
    }

    Vector3 Vector3::operator-(float value) const
    {
        return {x - value, y - value, z - value};
    }

    Vector3 &Vector3::operator-=(float value)
    {
        x -= value;
        y -= value;
        z -= value;
        return *this;
    }

    Vector3 Vector3::operator/(float value) const
    {
        return {x / value, y / value, z / value};
    }

    Vector3 &Vector3::operator/=(float value)
    {
        this->x /= value;
        this->y /= value;
        this->z /= value;
        return *this;
    }

    Vector3 Vector3::operator*(float value) const
    {
        return {this->x * value, this->y * value, this->z * value};
    }

    Vector3 &Vector3::operator*=(float value)
    {
        this->x *= value;
        this->y *= value;
        this->z *= value;
        return *this;
    }

    Vector3 Vector3::delta(const Vector2 &other) const
    {
        return other - *this;
    }

    float Vector3::distance(const Vector2 &b) const
    {
        auto delta = this->delta(b);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }

    Vector3 Vector3::delta(const Vector3 &other) const
    {
        return other - *this;
    }

    float Vector3::distance(const Vector3 &b) const
    {
        auto delta = this->delta(b);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2) + powf(delta.z, 2));
    }

    Vector3 Vector3::delta(float x, float y) const
    {
        return Vector3(x, y, 0) - *this;
    }

    float Vector3::distance(float x, float y)
    {
        auto delta = this->delta(x, y);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }

    Vector3 Vector3::delta(float x, float y, float z) const
    {
        auto b = Vector3(x, y, z);
        return this->delta(b);
    }

    float Vector3::distance(float x, float y, float z)
    {
        auto delta = this->delta(x, y, z);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2) + powf(delta.z, 2));
    }

    Vector3 Vector3::reverse() const
    {
        return {-x, -y, -z};
    }

    Vector3 &Vector3::reverse()
    {
        x = -x;
        y = -y;
        z = -z;
        return *this;
    }

    Vector3 Vector3::lerp(const Vector3 &destination, float factor) const
    {
        return {std::lerp(x, destination.x, factor), std::lerp(y, destination.y, factor), std::lerp(z, destination.z, factor)};
    }

    Vector3 Vector3::lerp(const Vector2 &destination, float factor) const
    {
        return {std::lerp(x, destination.x, factor), std::lerp(y, destination.y, factor), z};
    }

    Vector3::Vector3(std::shared_ptr<myxmlpp::Node> &data,
                     Config::XmlComponent &manager)
    {
        auto r = *data->begin();

        x = r->findAttribute("x")->getValueFloat();
        y = r->findAttribute("y")->getValueFloat();
        z = r->findAttribute("z")->getValueFloat();
    }




    // VECTOR2
    
    Vector2::Vector2(const Vector3 &copy)
    {
        x = copy.x;
        y = copy.y;
    }

    Vector2::Vector2(float x, float y): x(x), y(y)
    {}

    Vector2::Vector2()
    {
        x = 0;
        y = 0;
    }

    Vector2 Vector2::operator+(const Vector2 &other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2 &Vector2::operator+=(const Vector2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool Vector2::operator==(const Vector2 &other) const
    {
        return false;
    }

    Vector2 Vector2::operator-(const Vector2 &other) const {
        return {x - other.x, y - other.y};
    }

    Vector2 &Vector2::operator-=(const Vector2 &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 Vector2::delta(const Vector2 &other) const
    {
        return other - *this;
    }

    float Vector2::distance(const Vector2 &b) const
    {
        auto delta = this->delta(b);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }

    Vector2 Vector2::operator/(const Vector2 &other) const
    {
        return {x / other.x, y / other.y};
    }

    Vector2 &Vector2::operator/=(const Vector2 &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2 Vector2::operator*(const Vector2 &other) const
    {
        return {x * other.x, y * other.y};
    }

    Vector2 &Vector2::operator*=(const Vector2 &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    bool Vector2::operator!=(const Vector2 &other) const
    {
        return (x != other.x || y != other.y);
    }

    Vector2 Vector2::operator+(const Vector3 &other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2 &Vector2::operator+=(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 Vector2::operator-(const Vector3 &other) const
    {
        return {x - other.x, y - other.y};
    }

    Vector2 &Vector2::operator-=(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 Vector2::operator/(const Vector3 &other) const
    {
        return {x / other.x, y / other.y};
    }

    Vector2 &Vector2::operator/=(const Vector3 &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2 Vector2::operator*(const Vector3 &other) const
    {
        return {x * other.x, y * other.y};
    }

    Vector2 &Vector2::operator*=(const Vector3 &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2 &Vector2::operator=(const Vector3 &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool Vector2::operator==(const Vector3 &other) const
    {
        return (x == other.x && y == other.y);
    }

    bool Vector2::operator!=(const Vector3 &other) const
    {
        return (x != other.x || y != other.y);
    }

    Vector2 Vector2::operator+(float value) const
    {
        return {x + value, y + value};
    }

    Vector2 &Vector2::operator+=(float value)
    {
        x += value;
        y += value;
        return *this;
    }

    Vector2 Vector2::operator-(float value) const
    {
        return {x - value, y - value};
    }

    Vector2 &Vector2::operator-=(float value)
    {
        x -= value;
        y -= value;
        return *this;
    }

    Vector2 Vector2::operator/(float value) const
    {
        return {x / value, y / value};
    }

    Vector2 &Vector2::operator/=(float value)
    {
        x /= value;
        y /= value;
        return *this;
    }

    Vector2 Vector2::operator*(float value) const
    {
        return {x * value, y * value};
    }

    Vector2 &Vector2::operator*=(float value)
    {
        x *= value;
        y *= value;
        return *this;
    }

    Vector2 Vector2::delta(const Vector3 &other) const
    {
        return other - *this;
    }

    float Vector2::distance(const Vector3 &b) const
    {
        auto delta = this->delta(b);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }

    Vector2 Vector2::delta(float x, float y) const
    {
        return {x - this->x, y - this->y};
    }

    float Vector2::distance(float x, float y)
    {
        auto delta = this->delta(x, y);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }


    float Vector2::distance(float x, float y, float z)
    {
        auto delta = this->delta(x, y);
        return sqrtf(powf(delta.x, 2) + powf(delta.y, 2));
    }


    Vector2 Vector2::reverse() const
    {
        return {-x, -y};
    }

    Vector2 &Vector2::reverse()
    {
        x *= -1;
        y *= -1;
        return *this;
    }

    Vector2 Vector2::lerp(const Vector3 &destination, float factor) const
    {
        return {std::lerp(x, destination.x, factor), std::lerp(y, destination.y, factor)};
    }

    Vector2 Vector2::lerp(const Vector2 &destination, float factor) const
    {
        return {std::lerp(x, destination.x, factor), std::lerp(y, destination.y, factor)};
    }

    Vector2::Vector2(std::shared_ptr<myxmlpp::Node> &data,
                     Config::XmlComponent &manager)
    {
        auto r = *data->begin();

        x = r->findAttribute("x")->getValueFloat();
        y = r->findAttribute("y")->getValueFloat();
    }
}