/*
** EPITECH PROJECT, 2020
** SoundPlayerComponent.hpp
** File description:
** header for SoundPlayerComponent.c
*/


#pragma once

#include "Core/component/base/Component.hpp"
#include "GraphicalAPI/modules/SoundModule.hpp"

namespace Polymorph
{
    class SoundModule;
    using Sound = safe_ptr<SoundModule>;
    class SoundPlayerComponent;
    using SoundPlayer = safe_ptr<SoundPlayerComponent>;
    using SoundPlayerBase = std::shared_ptr<SoundPlayerComponent>;

    class SoundPlayerComponent : public Component
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit SoundPlayerComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::shared_ptr<SoundModule> sound;


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;
            void play();
            void stop();
            void pause();
            void resume();
            void setVolume(float volume);
            float getVolume();
            void changeAndPlay(std::shared_ptr<SoundModule> sound);

        private:


//////////////////////--------------------------/////////////////////////

    };
}
