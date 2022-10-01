/*
** EPITECH PROJECT, 2020
** SpriteRendererInitializer.hpp
** File description:
** header for SpriteRendererInitializer.c
*/

#ifndef ENGINE_CAMERAINITIALIZER_HPP
#define ENGINE_CAMERAINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class CameraComponent;

    class CameraInitializer : public AComponentInitializer<CameraComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            CameraInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_CAMERAINITIALIZER_HPP
