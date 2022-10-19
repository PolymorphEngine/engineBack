/*
** EPITECH PROJECT, 2020
** ISoundModule.hpp
** File description:
** header for ISoundModule.c
*/

#pragma once

namespace Polymorph
{
    class ISoundModule
    {
        public:
            virtual ~ISoundModule(void) = default;

            virtual void play(void) = 0;

            virtual void playMulti(void) = 0;

            virtual void pause(void) = 0;

            virtual void stop(void) = 0;

            virtual void resume(void) = 0;

            virtual void setVolume(float volume) = 0;

            virtual bool isSoundPlaying(void) = 0;
    };
}
