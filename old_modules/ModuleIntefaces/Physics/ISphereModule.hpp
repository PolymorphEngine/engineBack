/*
** EPITECH PROJECT, 2020
** ISphereModule
** File description:
** header for ISphereModule.cpp
*/

#pragma once

namespace Polymorph
{
    class IBoxModule;

    class ISphereModule
    {
        public:
            virtual ~ISphereModule() = default;

            virtual void setCenter(float x, float y, float z) = 0;

            virtual void setRadius(float radius) = 0;

            virtual void
            setColor(unsigned char r, unsigned char g, unsigned char b,
                     unsigned char a) = 0;

            virtual bool collideWithBox(const IBoxModule &box) const = 0;

            virtual bool
            collideWithSphere(const ISphereModule &sphere) const = 0;

            virtual void draw() = 0;

            virtual void drawWires() = 0;
    };

}
