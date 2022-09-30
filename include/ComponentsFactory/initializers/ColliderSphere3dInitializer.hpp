
/*
** EPITECH PROJECT, 2020
** ColliderSphere3ddInitializer.hpp
** File description:
** header for ColliderSphere3ddInitializer.c
*/

#ifndef ENGINE_COLLIDERSPHERE3DINITIALIZER_HPP
#define ENGINE_COLLIDERSPHERE3DINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class ColliderSphere3dComponent;

    class ColliderSphere3dInitializer
            : public AComponentInitializer<ColliderSphere3dComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderSphere3dInitializer(Config::XmlComponent &data,
                                        GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COLLIDERSPHERE3DINITIALIZER_HPP
