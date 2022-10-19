/*
** EPITECH PROJECT, 2020
** ITextModule
** File description:
** header for ITextModule.cpp
*/

#pragma once

#include <string>
#include "ITextModule.hpp"
#include "IFontModule.hpp"

namespace Polymorph
{
    class ITextModule
    {
        public:
            virtual ~ITextModule() = default;

            virtual void setPosition(float x, float y) = 0;

            virtual void
            setColor(unsigned char r, unsigned char g, unsigned char b,
                     unsigned char a) = 0;

            virtual void setText(const std::string &text) = 0;

            virtual void
            draw(const IFontModule &font, float size, float spacing) = 0;
    };

}