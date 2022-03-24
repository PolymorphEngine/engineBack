/*
** EPITECH PROJECT, 2020
** Color.cpp
** File description:
** Color.cpp
*/

#include <Polymorph/Types.hpp>
#include <Polymorph/Config.hpp>


Polymorph::Color::Color(std::shared_ptr<myxmlpp::Node> &data)
{
    int _tmp = -1;

    Config::XmlComponent::setProperty("r", _tmp, data);
    if (_tmp > -1)
        r = _tmp;
    _tmp = -1;
    Config::XmlComponent::setProperty("g", _tmp, data);
    if (_tmp > -1)
        g = _tmp;
    _tmp = -1;
    Config::XmlComponent::setProperty("b", _tmp, data);
    if (_tmp > -1)
        b = _tmp;

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
