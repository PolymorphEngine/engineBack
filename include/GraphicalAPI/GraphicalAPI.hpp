/*
** EPITECH PROJECT, 2020
** GraphicalAPI.hpp
** File description:
** header for GraphicalAPI.c
*/


#pragma once

#include "safe_ptr.hpp"
#include "DynamicLoader/DynamicLoader.hpp"
#include "GraphicalAPI/SpriteModule.hpp"
#include "GraphicalAPI/TextModule.hpp"
#include "GraphicalAPI/DisplayModule.hpp"

namespace Polymorph
{
    using Sprite = safe_ptr<SpriteModule>;
    using SpriteBase = std::shared_ptr<SpriteModule>;
    
    using Text = safe_ptr<TextModule>;
    using TextBase = std::shared_ptr<TextModule>;
    
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
            static inline DisplayModule *CurrentDisplay = nullptr;
    
    
        private:
            std::string _handlerPath;
            std::vector<SpriteBase> _sprites;
            std::vector<TextBase> _texts;
            std::vector<DisplayBase> _displays;
            static inline GraphicalAPI *_instance = nullptr;

            using TextLoader = arcade::ITextModule *(*)();
            using TextUnloader = void (*)(arcade::ITextModule *module);

            TextLoader _c_text = nullptr;
            TextUnloader _d_text = nullptr;

            using SpriteLoader = arcade::ISpriteModule *(*)();
            using SpriteUnloader = void (*)(arcade::ISpriteModule *module);

            SpriteLoader _c_sprite = nullptr;
            SpriteUnloader _d_sprite = nullptr;

            using DisplayLoader = arcade::IDisplayModule *(*)();
            using DisplayUnloader = void (*)(arcade::IDisplayModule *module);

            DisplayLoader _c_display = nullptr;
            DisplayUnloader _d_display = nullptr;

//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            static Sprite createSprite(std::shared_ptr<myxmlpp::Node> &data);
            static Sprite createSprite(std::string filePath);
            static Text createText(std::shared_ptr<myxmlpp::Node> &data);
            static Text createText(unsigned int size, std::string fontPath, std::string text = "");
            static Display createDisplay(std::shared_ptr<Settings::VideoSettings> videoSettings, std::string title);
            
            static void destroySprite(SpriteModule *sprite);
            static void destroyText(TextModule *text);
            static void destroyDisplay(DisplayModule *display);
            
            static void reloadAPI(std::string newHandler);
            static void *getHandler();
            static std::string getHandlerPath() const;
            
        private:
            static void _unloadModules();
            static void _reloadModules();

//////////////////////--------------------------/////////////////////////
        };

}



