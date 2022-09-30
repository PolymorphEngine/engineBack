/*
** EPITECH PROJECT, 2020
** SpriteAnimatorInitializer
** File description:
** header for SpriteAnimator.c
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Factory.hpp"

namespace Polymorph
{
    class SpriteAnimatorScript;

    class SpriteAnimatorInitializer
            : public AComponentInitializer<SpriteAnimatorScript>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            SpriteAnimatorInitializer(Config::XmlComponent &data,
                                      GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}