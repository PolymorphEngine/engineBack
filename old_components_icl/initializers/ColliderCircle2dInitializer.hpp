/*
** EPITECH PROJECT, 2020
** ColliderCircle2dInitializer.hpp
** File description:
** header for ColliderCircle2dInitializer.c
*/

#ifndef ENGINE_COLLIDERCIRCLE2DINITIALIZER_HPP
#define ENGINE_COLLIDERCIRCLE2DINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class ColliderCircle2dComponent;

    class ColliderCircle2dInitializer
            : public AComponentInitializer<ColliderCircle2dComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderCircle2dInitializer(Config::XmlComponent &data,
                                        GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final
            {};

///////////////////////////--------------------------///////////////////////////

    };
}


#endif //ENGINE_COLLIDERCIRCLE2DINITIALIZER_HPP
