/*
** EPITECH PROJECT, 2020
** ColliderRect2dInitializer.hpp
** File description:
** header for ColliderRect2dInitializer.c
*/

#ifndef ENGINE_COLLIDERRECT2DINITIALIZER_HPP
#define ENGINE_COLLIDERRECT2DINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class ColliderRect2dComponent;
    class ColliderRect2dInitializer : public AComponentInitializer<ColliderRect2dComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderRect2dInitializer(Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final {};

///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COLLIDERRECT2DINITIALIZER_HPP
