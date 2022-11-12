/*
** EPITECH PROJECT, 2020
** Color.hpp
** File description:
** header for Color.c
*/

#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include <myxmlpp/myxmlpp.hpp>

namespace polymorph::engine
{
    class Color : ASerializableObject
    {
///////////////////////////////// Constructors /////////////////////////////////
        public:
            Color() : ASerializableObject("Color") {};

            explicit Color(unsigned char r, unsigned char g, unsigned char b,
                           unsigned char a = 255);

            explicit Color(std::shared_ptr<myxmlpp::Node> &data,
                           Config::XmlComponent &manager);

            ~Color() override = default;
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            static inline bool builtin_type = true;
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

    constexpr bool operator==(const Color& lhs, const Color& rhs) {
        return lhs.a == rhs.a && lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
    }

}

#endif //ENGINE_COLOR_HPP
