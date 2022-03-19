/*
** EPITECH PROJECT, 2020
** Display.hpp
** File description:
** header for Display.c
*/

#ifndef ENGINE_DISPLAY_HPP
#define ENGINE_DISPLAY_HPP


#include <iostream>
#include <memory>
#include <vector>

#include "ArcadeInterfaces/IDisplayModule.hpp"
#include "Vector.hpp"

namespace Polymorph
{
    namespace Settings{class VideoSettings;}
    class Sprite;
    
    class Display
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            Display(const std::shared_ptr<Settings::VideoSettings> &settings, std::string title);
            ~Display();
            
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:

        private:
            std::string _title;
            arcade::IDisplayModule *_displayModule;
            std::shared_ptr<Settings::VideoSettings> _settings;
            static inline Display * _instance = nullptr;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            void clearWindow();
            void displayWindow();
            void close();
            bool isOpen();
            void fetchEvents();
            
            static void setResolution(Vector2 newResolution);
            static Vector2 getResolution();
            static void setMaxFps(int fps);
            static void setFullScreen(bool fullScreen);
            static bool isTextMode();

            static void draw(Sprite &sprite);

            static void loadModule();
            static void unloadModule();
            
        private:
            void _loadModule();
            void _unloadModule();
            using loader = arcade::IDisplayModule *(*)();
            using unloader = void (*)(arcade::IDisplayModule *module);
            static inline loader create = nullptr;
            static inline unloader destroy = nullptr;
///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_DISPLAY_HPP
