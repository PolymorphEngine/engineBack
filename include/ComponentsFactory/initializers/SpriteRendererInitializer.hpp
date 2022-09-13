/*
** EPITECH PROJECT, 2020
** SpriteRendererInitializer.hpp
** File description:
** header for SpriteRendererInitializer.c
*/

#ifndef ENGINE_SPRITERENDERERINITIALIZER_HPP
#define ENGINE_SPRITERENDERERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class SpriteRendererComponent;
    class SpriteRendererInitializer : public AComponentInitializer<SpriteRendererComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            SpriteRendererInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_SPRITERENDERERINITIALIZER_HPP
