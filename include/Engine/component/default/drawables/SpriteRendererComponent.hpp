/*
** EPITECH PROJECT, 2020
** SpriteRenderComponent.hpp
** File description:
** header for SpriteRenderComponent.c
*/

#ifndef ENGINE_SPRITERENDERERCOMPONENT_HPP
#define ENGINE_SPRITERENDERERCOMPONENT_HPP


#include "DrawableComponent.hpp"

namespace Polymorph
{
    class Sprite;
    
    class SpriteRendererComponent;
    using SpriteRenderer = safe_ptr<SpriteRendererComponent>;
    
    class SpriteRendererComponent : public DrawableComponent
    {
        public:
            SpriteRendererComponent(Entity &gameObject);
            
            
        public:
            std::shared_ptr<Sprite> sprite = nullptr;
            
            
            
        public:
            void draw() override;
    
    };
}

#endif //ENGINE_SPRITERENDERERCOMPONENT_HPP
