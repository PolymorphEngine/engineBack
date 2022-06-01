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
    int tmp = 0;
    manager.setSubProperty("r", data, tmp);
    r = tmp;
    manager.setSubProperty("g", data, tmp);
    g = tmp;
    manager.setSubProperty("b", data, tmp);
    b = tmp;
    manager.setSubProperty("a", data, tmp);
    a = tmp;
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
