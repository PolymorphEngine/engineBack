/*
** EPITECH PROJECT, 2020
** SpriteRenderComponent.hpp
** File description:
** header for SpriteRenderComponent.c
*/

#ifndef ENGINE_SPRITERENDERERCOMPONENT_HPP
#define ENGINE_SPRITERENDERERCOMPONENT_HPP


#include "Core/component/base/ADrawableComponent.hpp"

namespace Polymorph
{
    class SpriteModule;
    using Sprite = safe_ptr<SpriteModule>;
    class SpriteRendererComponent;
    using SpriteRenderer = safe_ptr<SpriteRendererComponent>;
    using SpriteRendererBase = std::shared_ptr<SpriteRendererComponent>;

    class SpriteRendererComponent : public ADrawableComponent
    {
        public:
            explicit SpriteRendererComponent(GameObject gameObject);


        public:
            Sprite sprite;



        public:
            void draw() override;

    };
}

#endif //ENGINE_SPRITERENDERERCOMPONENT_HPP
