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

            explicit Color(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager);
            explicit Color(unsigned char r, unsigned char g, unsigned char b);
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
            void setColor(unsigned char r, unsigned char g, unsigned char b);

///////////////////////////--------------------------///////////////////////////

    };

}

#endif //ENGINE_COLOR_HPP
