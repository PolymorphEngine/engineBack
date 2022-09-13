/*
** EPITECH PROJECT, 2020
** ButtonInitializer
** File description:
** header for ButtonInitializer.cpp
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Factory.hpp"

namespace Polymorph
{
    class ButtonComponent;

    class ButtonInitializer
            : public AComponentInitializer<ButtonComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ButtonInitializer(Config::XmlComponent &data,
                                           GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}