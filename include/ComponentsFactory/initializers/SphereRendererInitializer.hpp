/*
** EPITECH PROJECT, 2020
** SphereRendererInitializer.hpp
** File description:
** header for SphereRendererInitializer.c
*/

#ifndef ENGINE_SPHERERENDERERINITIALIZER_HPP
#define ENGINE_SPHERERENDERERINITIALIZER_HPP

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class SphereRendererComponent;

    class SphereRendererInitializer
            : public AComponentInitializer<SphereRendererComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            SphereRendererInitializer(Config::XmlComponent &data,
                                      GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;

///////////////////////////--------------------------///////////////////////////
    };


}

#endif //ENGINE_SPHERERENDERERINITIALIZER_HPP
