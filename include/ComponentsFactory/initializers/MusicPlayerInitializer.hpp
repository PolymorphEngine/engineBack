/*
** EPITECH PROJECT, 2020
** MusicPlayerInitializer.hpp
** File description:
** header for MusicPlayerInitializer.c
*/


#pragma once

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{

    class MusicPlayerComponent;
    class MusicPlayerInitializer : public AComponentInitializer<MusicPlayerComponent>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MusicPlayerInitializer(Config::XmlComponent &data, GameObject entity);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void build() final;

            void reference() final {};

        private:


//////////////////////--------------------------/////////////////////////

    };
}
