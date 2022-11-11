/*
** EPITECH PROJECT, 2020
** GraphicalAPI.hpp
** File description:
** header for GraphicalAPI.c
*/


#pragma once

#include <myxmlpp.hpp>
#include <GraphicalAPI/modules/TextureModule.hpp>

#include "Utilities/safe_ptr.hpp"
#include "DynamicLoader/DynamicLoader.hpp"

namespace arcade{class ISpriteModule; class ITextModule; class IDisplayModule;}

namespace Polymorph
{
    namespace Settings{class VideoSettings;}
    class DisplayModule;


    using Display = safe_ptr<DisplayModule>;
    using DisplayBase = std::shared_ptr<DisplayModule>;

    class GraphicalAPI : public DynamicLibLoader
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit GraphicalAPI(std::string handlerPath);

            ~GraphicalAPI();

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline Display CurrentDisplay = Display(nullptr);


        private:
            std::string _handlerPath;
            std::vector<DisplayBase> _displays;
            static inline GraphicalAPI *_instance = nullptr;
        public:

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static Display createDisplay(std::shared_ptr<Settings::VideoSettings>& videoSettings, const std::string& title);

            static void reloadAPI(const std::string& newHandler);

#ifdef _WIN32
            static HINSTANCE getHandler();
#else
            
            static void *getHandler();
#endif



        private:

        };

}



