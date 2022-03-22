/*
** EPITECH PROJECT, 2020
** Display.hpp
** File description:
** header for Display.c
*/

#ifndef ENGINE_DISPLAYMODULE_HPP
#define ENGINE_DISPLAYMODULE_HPP


#include <iostream>
#include <memory>
#include <vector>

#include "ArcadeInterfaces/IDisplayModule.hpp"
#include "Vector.hpp"

namespace Polymorph
{
    namespace Settings{class VideoSettings;}
    class SpriteModule;
    class TextModule;
    class GraphicalAPI;
    
    class DisplayModule
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            DisplayModule(const std::shared_ptr<Settings::VideoSettings> &settings, std::string title);
            ~DisplayModule();
            
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:

        private:
            std::string _title;
            arcade::IDisplayModule *_displayModule;
            std::shared_ptr<Settings::VideoSettings> _settings;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            void clearWindow();
            void displayWindow();
            void close();
            bool isOpen();
            void fetchEvents();
            
            void setResolution(Vector2 newResolution);
            Vector2 getResolution();
            void setMaxFps(int fps);
            void setFullScreen(bool fullScreen);
            bool isTextMode();

            void draw(SpriteModule &sprite);
            void draw(TextModule &sprite);

            
        private:
            void _loadModule();

///////////////////////////--------------------------///////////////////////////
        friend GraphicalAPI;
    };
}

#endif //ENGINE_DISPLAYMODULE_HPP
