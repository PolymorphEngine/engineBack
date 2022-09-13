/*
** EPITECH PROJECT, 2020
** ColliderMesh3ddInitializer.hpp
** File description:
** header for ColliderMesh3ddInitializer.c
*/

#ifndef ENGINE_COLLIDERMESH3DINITIALIZER_HPP
#define ENGINE_COLLIDERMESH3DINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class ColliderMesh3dComponent;
    class ColliderMesh3dInitializer : public AComponentInitializer<ColliderMesh3dComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            ColliderMesh3dInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COLLIDERMESH3DINITIALIZER_HPP
