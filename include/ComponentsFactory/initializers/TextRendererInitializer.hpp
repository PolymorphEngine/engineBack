/*
** EPITECH PROJECT, 2020
** TextRendererInitalizer.hpp
** File description:
** header for TextRendererInitalizer.c
*/

#ifndef ENGINE_TEXTRENDERERINITIALIZER_HPP
#define ENGINE_TEXTRENDERERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class TextRendererComponent;
    class TextRendererInitializer : public AComponentInitializer<TextRendererComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            TextRendererInitializer(Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_TEXTRENDERERINITIALIZER_HPP
