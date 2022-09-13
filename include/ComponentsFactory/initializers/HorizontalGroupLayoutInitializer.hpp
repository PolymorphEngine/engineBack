/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutInitializer
** File description:
** header for HorizontalGroupLayoutInitializer.cpp
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Factory.hpp"

namespace Polymorph
{
    class HorizontalGroupLayoutComponent;

    class HorizontalGroupLayoutInitializer
            : public AComponentInitializer<HorizontalGroupLayoutComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            HorizontalGroupLayoutInitializer(Config::XmlComponent &data,
                                           GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}