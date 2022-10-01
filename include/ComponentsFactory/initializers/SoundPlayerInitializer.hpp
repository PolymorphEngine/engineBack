/*
** EPITECH PROJECT, 2020
** SoundPlayerInitializer.hpp
** File description:
** header for SoundPlayerInitializer.c
*/


#pragma once

#include "ComponentsFactory/AComponentInitializer.hpp"

namespace Polymorph
{

    class SoundPlayerComponent;

    class SoundPlayerInitializer
            : public AComponentInitializer<SoundPlayerComponent>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SoundPlayerInitializer(Config::XmlComponent &data,
                                   GameObject entity);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void build() final;

            void reference() final
            {};

        private:


//////////////////////--------------------------/////////////////////////

    };
}
