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
    class ColliderCircle2dInitializer : public AComponentInitializer
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderCircle2dInitializer(Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            std::shared_ptr<Component> &build() final;

            void reference() final {};

///////////////////////////--------------------------///////////////////////////

    };
}


#endif //ENGINE_COLLIDERCIRCLE2DINITIALIZER_HPP
