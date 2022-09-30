/*
** EPITECH PROJECT, 2020
** CanvasInitializer
** File description:
** header for CanvasInitializer.cpp
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Factory.hpp"

namespace Polymorph
{
    class CanvasComponent;

    class CanvasInitializer
            : public AComponentInitializer<CanvasComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            CanvasInitializer(Config::XmlComponent &data,
                              GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}