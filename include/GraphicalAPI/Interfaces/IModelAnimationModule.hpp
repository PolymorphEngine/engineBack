/*
** EPITECH PROJECT, 2020
** IModelAnimationModule.hpp
** File description:
** header for IModelAnimationModule.c
*/

#pragma once

#include <cstddef>
#include "IModelModule.hpp"

namespace Polymorph
{
    class IModelAnimationModule
    {
        public:
            virtual ~IModelAnimationModule() = default;

            virtual void update(const IModelModule &model) = 0;
            virtual void incrementIdx() = 0;
            virtual void resetIdx() = 0;
            virtual void tick() = 0;
            virtual unsigned int getNbFrames() = 0;
    };
}
