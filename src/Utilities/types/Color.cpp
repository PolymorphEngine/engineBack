/*
** EPITECH PROJECT, 2020
** Color.cpp
** File description:
** Color.cpp
*/

#include <polymorph/Types.hpp>
#include <polymorph/Config.hpp>


polymorph::engine::Color::Color(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager) : ASerializableObject("Color")
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

polymorph::engine::Color::Color(unsigned char r, unsigned char g,
                        unsigned char b, unsigned char a): ASerializableObject("Color")
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void
polymorph::engine::Color::setColor(unsigned char red, unsigned char green,
                           unsigned char blue, unsigned char alpha)
{
    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;
}
