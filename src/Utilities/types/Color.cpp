/*
** EPITECH PROJECT, 2020
** Color.cpp
** File description:
** Color.cpp
*/

#include <Polymorph/Types.hpp>
#include <Polymorph/Config.hpp>


Polymorph::Color::Color(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    manager.setSubProperty("r", data, reinterpret_cast<int &>(r));
    manager.setSubProperty("g", data, reinterpret_cast<int &>(g));
    manager.setSubProperty("b", data, reinterpret_cast<int &>(b));
    manager.setSubProperty("a", data, reinterpret_cast<int &>(a));
}

Polymorph::Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void
Polymorph::Color::setColor(unsigned char red, unsigned char green, unsigned char blue)
{
    this->r = red;
    this->g = green;
    this->b = blue;
}
