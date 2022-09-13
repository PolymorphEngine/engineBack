/*
** EPITECH PROJECT, 2020
** MusicModule.hpp
** File description:
** header for MusicModule.c
*/

#pragma once

#include <string>
#include <memory>
#include <myxmlpp.hpp>
#include "isModules/interfaces/IMusicModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{
    class MusicModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MusicModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager);
            ~MusicModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using MusicModuleLoader = is::IMusicModule *(*)(const std::string &filepath);
            static inline MusicModuleLoader _c_music = nullptr;

            float _volume;
            float _pitch;
            std::string _filePath;
            std::unique_ptr<is::IMusicModule> _music;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void play();
            void stop();
            void pause();
            void resume();
            void update();
            void setVolume(float volume);
            void setPitch(float pitch);
            float getVolume() const;
            float getPitch() const;
            void setLoop(bool loop);
            std::string getFilePath() const;

        private:
            void _loadModule();

//////////////////////--------------------------/////////////////////////

    };
}
