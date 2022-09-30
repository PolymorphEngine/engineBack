/*
** EPITECH PROJECT, 2020
** ITexture.hpp
** File description:
** header for ITexture.hpp.cpp
*/

#pragma once

namespace Polymorph
{
    class ITextureModule
    {
        public:
            virtual ~ITextureModule() = default;

            virtual void setPosition(float x, float y) = 0;

            virtual void draw(unsigned char r, unsigned char g,
                              unsigned char b, unsigned char a) = 0;

            virtual float getTextureWidth() = 0;

            virtual float getTextureHeight() = 0;

            virtual void setTextureRect(float x, float y, float w, float h) = 0;
    };
}
