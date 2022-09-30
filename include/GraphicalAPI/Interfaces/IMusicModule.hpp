/*
** EPITECH PROJECT, 2020
** IMusicModule.hpp
** File description:
** header for IMusicModule.c
*/

#pragma once

namespace Polymorph
{
    class IMusicModule
    {
        public:
            virtual ~IMusicModule(void) = default;

            virtual void play(void) = 0;
            virtual void pause(void) = 0;
            virtual void update(void) = 0;
            virtual void resume(void) = 0;
            virtual void stop(void) = 0;
            virtual void setVolume(float volume) = 0;
            virtual void setPitch(float pitch) = 0;
            virtual void setLoop(bool loop) = 0;
    };
}
