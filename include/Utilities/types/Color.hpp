/*
** EPITECH PROJECT, 2020
** Color.hpp
** File description:
** header for Color.c
*/

#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include <myxmlpp.hpp>

namespace Polymorph
{
    class Color
    {
///////////////////////////////// Constructors /////////////////////////////////
        public:
            Color() = default;

            explicit Color(unsigned char r, unsigned char g, unsigned char b,
                           unsigned char a = 255);

            explicit Color(std::shared_ptr<myxmlpp::Node> &data,
                           Config::XmlComponent &manager);

            ~Color() = default;
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            void setColor(unsigned char red, unsigned char green,
                          unsigned char blue, unsigned char alpha = 255);

///////////////////////////--------------------------///////////////////////////

    };

}

#endif //ENGINE_COLOR_HPP
