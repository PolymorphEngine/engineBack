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
#include "GraphicalAPI.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "Rect.hpp"

namespace Polymorph
{
    class TextModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit TextModule(std::string fontPath, std::string , unsigned int size);

            explicit TextModule(std::shared_ptr<myxmlpp::Node> &data);

            ~TextModule();
            TextModule &operator=(const std::string &newText);
            TextModule &operator+=(const std::string &newText);
            std::string operator+(const std::string &newText);

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            arcade::ITextModule *_textModule;
            Color _color;
            std::string _filepath;
            std::string _str;
            int _fontSize = -1;

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



        private:
            void _loadModule();


//////////////////////--------------------------/////////////////////////
        friend GraphicalAPI;
    };
}