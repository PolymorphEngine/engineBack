/*
** EPITECH PROJECT, 2020
** BoxColliderInitializer.hpp
** File description:
** header for BoxColliderInitializer.c
*/

#ifndef ENGINE_BOXCOLLIDERINITIALIZER_HPP
#define ENGINE_BOXCOLLIDERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class BoxColliderComponent;
    class BoxColliderInitializer : public AComponentInitializer<BoxColliderComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            BoxColliderInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////

    };
}


#endif //ENGINE_BOXCOLLIDERINITIALIZER_HPP
