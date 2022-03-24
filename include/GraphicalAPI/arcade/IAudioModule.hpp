/*
** EPITECH PROJECT, 2020
** DynamicLoader.hpp
** File description:
** header for DynamicLoader.c
*/

#pragma once

#include <iostream>

namespace arcade
{
    class IAudioModule
    {
        public:

            virtual ~IAudioModule() = default;
            // ALL FILE TYPES MUST BE AT THE PATH SPECIFIED
            // MUST: loads and set an audio file 
            //ex SFML:
            // assetPath = ./Assets/Pacman/enemy/sound
            // real path = ./Assets/Pacman/enmey/font.ttf

            virtual void setSource(std::string source_path) = 0;

            // MUST play the audio source (maybe instantiate it here)
            virtual void play() = 0;

            // MUST pause the audio source
            virtual void pause() = 0;

            // MUST Stop the audio source (maybe destroy the instance here)
            virtual void stop() = 0;

            // Must set the volume
            virtual void setVolume() = 0;
    
    };
}