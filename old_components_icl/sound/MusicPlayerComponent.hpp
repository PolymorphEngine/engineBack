/*
** EPITECH PROJECT, 2020
** MusicPlayerComponent.hpp
** File description:
** header for MusicPlayerComponent.c
*/


#pragma once

#include "Core/component/base/Component.hpp"
#include "GraphicalAPI/modules/MusicModule.hpp"

namespace Polymorph
{
    class MusicModule;

    using Music = safe_ptr<MusicModule>;

    class MusicPlayerComponent;

    using MusicPlayer = safe_ptr<MusicPlayerComponent>;
    using MusicPlayerBase = std::shared_ptr<MusicPlayerComponent>;

    class MusicPlayerComponent : public Component
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MusicPlayerComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::shared_ptr<MusicModule> music;
            bool Looping;
            bool AutoStart;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;

            void start() override;

            void play();

            void stop();

            void pause();

            void resume();

            void setVolume(float volume);

            float getVolume();

            void setPitch(float pitch);

            float getPitch();

            void setLoop(bool loop);

        private:


//////////////////////--------------------------/////////////////////////

    };
}
