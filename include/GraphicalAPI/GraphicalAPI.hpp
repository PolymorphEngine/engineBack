/*
** EPITECH PROJECT, 2020
** GraphicalAPI.hpp
** File description:
** header for GraphicalAPI.c
*/


#pragma once

#include <myxmlpp.hpp>
#include "Utilities/safe_ptr.hpp"
#include "DynamicLoader/DynamicLoader.hpp"

namespace arcade{class ISpriteModule; class ITextModule; class IDisplayModule;}

namespace Polymorph
{
    namespace Settings{class VideoSettings;}
    class SpriteModule;
    class TextModule;
    class DisplayModule;
    class Input;
    
    
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
            static inline Display CurrentDisplay = Display(nullptr);


        private:
            std::string _handlerPath;
            std::vector<SpriteBase> _sprites;
            std::vector<TextBase> _texts;
            std::vector<DisplayBase> _displays;
            static inline GraphicalAPI *_instance = nullptr;
        public:
            using TextLoader = arcade::ITextModule *(*)();
            using TextUnloader = void (*)(arcade::ITextModule *module);

            static inline TextLoader _c_text = nullptr;
            static inline TextUnloader _d_text = nullptr;

            using SpriteLoader = arcade::ISpriteModule *(*)();
            using SpriteUnloader = void (*)(arcade::ISpriteModule *module);

            static inline SpriteLoader _c_sprite = nullptr;
            static inline SpriteUnloader _d_sprite = nullptr;

            using DisplayLoader = arcade::IDisplayModule *(*)(unsigned int width, unsigned int height, std::string title);
            using DisplayUnloader = void (*)(arcade::IDisplayModule *module);

            static inline DisplayLoader _c_display = nullptr;
            static inline DisplayUnloader _d_display = nullptr;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
//            static Sprite createSprite(std::shared_ptr<myxmlpp::Node> &data);
//            static Sprite createSprite(const std::string& filePath);
//            static Text createText(std::shared_ptr<myxmlpp::Node> &data);
//            static Text createText(unsigned int size, const std::string& fontPath, const std::string& text = "");
            static Display createDisplay(std::shared_ptr<Settings::VideoSettings>& videoSettings, const std::string& title);

//            static void destroySprite(SpriteModule *sprite);
//            static void destroyText(TextModule *text);
            static void destroyDisplay(DisplayModule *display);

            static void reloadAPI(const std::string& newHandler);
            static void *getHandler();
            static std::string getHandlerPath();



        private:
//            static void _unloadModules();
//            static void _reloadModules();


            friend Input;
//////////////////////--------------------------/////////////////////////
        };

}



