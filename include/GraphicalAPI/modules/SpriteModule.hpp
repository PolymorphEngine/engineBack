/*
** EPITECH PROJECT, 2020
** Sprite.hpp
** File description:
** header for Sprite.c
*/

#ifndef ENGINE_SPRITEMODULE_HPP
#define ENGINE_SPRITEMODULE_HPP

#include <iostream>
#include <memory>
#include <vector>

#include <myxmlpp.hpp>
#include "Rect.hpp"
#include "Color.hpp"

namespace arcade{class ISpriteModule;}
namespace Polymorph
{
    class Vector2;
    class GraphicalAPI;

    class SpriteModule
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            SpriteModule() = default;
            explicit SpriteModule(std::string filePath);
            explicit SpriteModule(std::shared_ptr<myxmlpp::Node> &data);
            ~SpriteModule();
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        private:
            std::string _filePath;
            Rect _crop = {-1, -1, -1, -1};
            Color _color {0, 0, 0};

            arcade::ISpriteModule *_spriteModule = nullptr;

            static inline std::vector<SpriteModule *> _sprites;
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            arcade::ISpriteModule *getSprite();
            void setSprite(const std::string& newFilePath);
            void setPosition(Vector2 position);
            void moveSprite(Vector2 move);
            void setCrop(const Rect& crop);
            void setColor(Color color);




        private:
            void _loadModule();
///////////////////////////--------------------------///////////////////////////

        friend GraphicalAPI;

    };
}

#endif //ENGINE_SPRITEMODULE_HPP