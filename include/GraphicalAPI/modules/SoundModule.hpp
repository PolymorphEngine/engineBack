/*
** EPITECH PROJECT, 2020
** SoundModule.hpp
** File description:
** header for SoundModule.c
*/


#pragma once

#include <string>
#include <memory>
#include <myxmlpp.hpp>
#include "GraphicalAPI/GraphicalInterfaces/ISoundModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{
    class SoundModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit SoundModule(std::shared_ptr<myxmlpp::Node> &data,
                                 Config::XmlComponent &manager);

            ~SoundModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using SoundModuleLoader = Polymorph::ISoundModule *(*)(
                    const std::string &filepath);
            static inline SoundModuleLoader _c_sound = nullptr;

            float _volume;
            std::string _filePath;
            std::unique_ptr<Polymorph::ISoundModule> _sound;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void play();

            void pause();

            void resume();

            void stop();

            void setVolume(float volume);

            float getVolume() const;

            std::string getFilePath() const;

            bool isSoundPlaying() const;

            void playMulti();

        private:
            void _loadModule();

        private:


//////////////////////--------------------------/////////////////////////

    };
}
