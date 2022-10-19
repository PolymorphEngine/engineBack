/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutInitializer
** File description:
** header for VerticalGroupLayoutInitializer.cpp
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Factory.hpp"

namespace Polymorph
{
    class VerticalGroupLayoutComponent;

    class VerticalGroupLayoutInitializer
            : public AComponentInitializer<VerticalGroupLayoutComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            VerticalGroupLayoutInitializer(Config::XmlComponent &data,
                                           GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}