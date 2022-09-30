/*
** EPITECH PROJECT, 2020
** ICmaeraModule.hpp
** File description:
** header for ICmaeraModule.hpp.cpp
*/

#pragma once

namespace Polymorph
{
    class ICameraModule
    {
        public:
            virtual ~ICameraModule() = default;

            virtual void move(float x, float y, float z) = 0;

            virtual void setPosition(float x, float y, float z) = 0;

            virtual void setTarget(float x, float y, float z) = 0;

            virtual void setUp(float x, float y, float z) = 0;

            virtual void setFOV(float fov) = 0;

            virtual void begin3DMode() = 0;

            virtual void end3DMode() = 0;
    };
}

