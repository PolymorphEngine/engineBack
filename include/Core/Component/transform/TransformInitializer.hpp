/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.h
** File description:
** header for TransformInitializer.c
*/

#ifndef ENGINE_TRANSFORMINITIALIZER_HPP
#define ENGINE_TRANSFORMINITIALIZER_HPP

#include "../initializer/AComponentInitializer.hpp"

namespace polymorph::engine
{
    class TransformInitializer
            : public AComponentInitializer<TransformComponent>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            TransformInitializer(Config::XmlComponent &data, GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}

#endif //ENGINE_TRANSFORMINITIALIZER_HPP
