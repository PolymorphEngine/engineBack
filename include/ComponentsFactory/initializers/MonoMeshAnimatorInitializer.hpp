/*
** EPITECH PROJECT, 2020
** MonoMeshAnimatorInitializer.hpp
** File description:
** header for MonoMeshAnimatorInitializer.c
*/


#pragma once

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class MonoMeshAnimatorComponent;

    class MonoMeshAnimatorInitializer
            : public AComponentInitializer<MonoMeshAnimatorComponent>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MonoMeshAnimatorInitializer(Config::XmlComponent &data,
                                        GameObject entity);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void build() final;

            void reference() final;


        private:


//////////////////////--------------------------/////////////////////////

    };
}

