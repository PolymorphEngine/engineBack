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
    class ColliderRect2dInitializer : public AComponentInitializer
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderRect2dInitializer(Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            std::shared_ptr<Component> &build() final;

            void reference() final {};

///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COLLIDERRECT2DINITIALIZER_HPP
