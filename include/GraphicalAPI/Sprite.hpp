/*
** EPITECH PROJECT, 2020
** Sprite.hpp
** File description:
** header for Sprite.c
*/

#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "ArcadeInterfaces/ISpriteModule.hpp"
#include "Vector.hpp"
#include "Rect.hpp"
#include "Color.hpp"

namespace Polymorph
{
    class Sprite
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            Sprite();
            explicit Sprite(std::string filePath);
            explicit Sprite(const myxmlpp::Node &data);
            ~Sprite();
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            std::string filePath;
            Rect crop;
            Color color;
            
        private:
            arcade::ISpriteModule *_spriteModule;

            static inline std::vector<Sprite *> _sprites;
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            arcade::ISpriteModule *getSprite();
            void setSprite(std::string newFilePath);
            void setPosition(Vector2 position);
            void moveSprite(Vector2 move);
            void setCrop(Rect crop);
            void setColor(Color color);
            
            
            static void loadModules();
            static void unloadModules();
            
            
        private:
            void _loadModule();
            void _unloadModule();
            using loader = arcade::ISpriteModule *(*)();
            using unloader = void (*)(arcade::ISpriteModule *module);
            static inline loader create = nullptr;
            static inline unloader destroy = nullptr;
///////////////////////////--------------------------///////////////////////////

            
    };
}

#endif //ENGINE_SPRITE_HPP
