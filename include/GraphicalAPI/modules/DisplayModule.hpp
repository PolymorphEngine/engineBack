/*
** EPITECH PROJECT, 2020
** WindowModule.hpp
** File description:
** header for WindowModule.c
*/


#pragma once

#include "myxmlpp.hpp"
#include "isModules/interfaces/IWindowModule.hpp"
#include "isModules/interfaces/ICursorModule.hpp"
#include "isModules/interfaces/IDrawingModule.hpp"
#include "Polymorph/Types.hpp"
#include "Core/settings/VideoSettings.hpp"

namespace Polymorph
{

    class DisplayModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit DisplayModule(std::shared_ptr<Settings::VideoSettings> &settings, std::string title);

            ~DisplayModule();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:

        private:
            using WindowModuleLoader = is::IWindowModule *(*)(int width, int height, const std::string &title);
            static inline WindowModuleLoader _c_window = nullptr;

                    using DrawingModuleLoader = is::IDrawingModule *(*)();
            static inline DrawingModuleLoader _c_drawing = nullptr;

            const std::string &_title;
            std::unique_ptr<is::IWindowModule> _windowModule;
            std::unique_ptr<is::IDrawingModule> _drawingModule;
            std::shared_ptr<Settings::VideoSettings> _settings;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            // Window
            void close();
            bool isOpen();
            bool isFullscreen();
            void setFullscreen(bool fullscreen);
            void setTitle(const std::string &title);
            Vector2 getResolution() const;
            void setLogLevel(int level);

            // Drawing
            void clearWindow(Color color);
            void clearWindow();
            void beginDrawing();
            void endDrawing();

        private:
            static void _loadModule();

//////////////////////--------------------------/////////////////////////

    };

}
