/*
** EPITECH PROJECT, 2020
** BoxRendererInitializer.hpp
** File description:
** header for BoxRendererInitializer.c
*/

#ifndef ENGINE_BOXRENDERERINITIALIZER_HPP
#define ENGINE_BOXRENDERERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class BoxRendererComponent;
    class BoxRendererInitializer : public AComponentInitializer<BoxRendererComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            BoxRendererInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_BOXRENDERERINITIALIZER_HPP
