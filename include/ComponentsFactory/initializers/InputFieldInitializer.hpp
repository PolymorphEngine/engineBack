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
    class InputFieldComponent;

    class InputFieldInitializer
            : public AComponentInitializer<InputFieldComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            InputFieldInitializer(Config::XmlComponent &data,
                                           GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}