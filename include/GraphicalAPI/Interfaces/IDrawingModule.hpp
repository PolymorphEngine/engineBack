/*
** EPITECH PROJECT, 2020
** IDrawing
** File description:
** header for IDrawing.cpp
*/

#pragma once

namespace Polymorph
{
    class IDrawingModule
    {
        public:
            virtual ~IDrawingModule() = default;

            virtual void
            clear(unsigned char r, unsigned char g, unsigned char b,
                  unsigned char a) = 0;

            virtual void beginDrawing() = 0;

            virtual void endDrawing() = 0;
    };

}