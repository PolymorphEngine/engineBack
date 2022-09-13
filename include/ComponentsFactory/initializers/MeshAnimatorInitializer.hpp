/*
** EPITECH PROJECT, 2020
** MeshAnimatorInitializer.hpp
** File description:
** header for MeshAnimatorInitializer.c
*/


#pragma once

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{
    class MeshAnimatorComponent;

    class MeshAnimatorInitializer : public AComponentInitializer<MeshAnimatorComponent>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MeshAnimatorInitializer(Config::XmlComponent &data, GameObject entity);


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

