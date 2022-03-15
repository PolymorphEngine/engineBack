/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.h
** File description:
** header for TransformInitializer.c
*/

#ifndef ENGINE_TRANSFORMINITIALIZER_HPP
#define ENGINE_TRANSFORMINITIALIZER_HPP

#include "factory/ComponentInitializer.hpp"

namespace Polymorph
{
    class TransformInitializer : public AComponentInitializer
    {
        public:

            TransformInitializer(Config::XmlComponent &data, Entity &entity);

            std::shared_ptr<Component> &build() final;
            
            void reference() final;

    };
}

#endif //ENGINE_TRANSFORMINITIALIZER_HPP
