/*
** EPITECH PROJECT, 2020
** Text.hpp
** File description:
** header for Text.c
*/


#pragma once


#include <string>
#include "myxmlpp.hpp"
#include "GraphicalAPI/ArcadeInterfaces/ITextModule.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "Rect.hpp"

namespace Polymorph
{
    class Text
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit Text(std::string fontPath, std::string text);

            explicit Text(std::shared_ptr<myxmlpp::Node> &data);

            ~Text();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            arcade::ITextModule *_textModule;
            Color _color;
            std::string _filepath;
            std::string _str;
            int _fontSize = -1;

            static inline std::vector<Text *> _texts;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            arcade::ITextModule *getText();
            void setFont(std::string newFilePath);
            void setFontSize(int size);
            void setPosition(Vector2 position);
            void move(Vector2 move);
            void setString(std::string newString);
            void setColor(Color color);


            static void loadModules();
            static void unloadModules();

        private:
            void _loadModule();
            void _unloadModule();
            using loader = arcade::ITextModule *(*)();
            using unloader = void (*)(arcade::ITextModule *module);
            static inline loader create = nullptr;
            static inline unloader destroy = nullptr;

//////////////////////--------------------------/////////////////////////

    };
}