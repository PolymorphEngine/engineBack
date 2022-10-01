/*
** EPITECH PROJECT, 2020
** MeshRendererInitializer.hpp
** File description:
** header for MeshRendererInitializer.c
*/

#ifndef ENGINE_MESHRENDERERINITIALIZER_HPP
#define ENGINE_MESHRENDERERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class MeshRendererComponent;

    class MeshRendererInitializer
            : public AComponentInitializer<MeshRendererComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            MeshRendererInitializer(Config::XmlComponent &data,
                                    GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_MESHRENDERERINITIALIZER_HPP
