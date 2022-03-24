/*
** EPITECH PROJECT, 2020
** SpriteRendererInitializer.hpp
** File description:
** header for SpriteRendererInitializer.c
*/

#ifndef ENGINE_SPRITERENDERERINITIALIZER_HPP
#define ENGINE_SPRITERENDERERINITIALIZER_HPP

#include "ComponentsFactory/ComponentInitializer.hpp"

namespace Polymorph
{
    class SpriteRendererInitializer : public AComponentInitializer
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            SpriteRendererInitializer(Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            std::shared_ptr<Component> &build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_SPRITERENDERERINITIALIZER_HPP
