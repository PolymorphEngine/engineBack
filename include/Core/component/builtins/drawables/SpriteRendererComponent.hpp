/*
** EPITECH PROJECT, 2020
** SpriteRenderComponent.hpp
** File description:
** header for SpriteRenderComponent.c
*/

#ifndef ENGINE_SPRITERENDERERCOMPONENT_HPP
#define ENGINE_SPRITERENDERERCOMPONENT_HPP


#include "Core/component/base/ADrawable2dComponent.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"
#include "GraphicalAPI/modules/MeshModule.hpp"

namespace Polymorph
{
    class TextureModule;

    class SpriteRendererComponent;

    using SpriteRenderer = safe_ptr<SpriteRendererComponent>;
    using SpriteRendererBase = std::shared_ptr<SpriteRendererComponent>;

    class SpriteRendererComponent : public ADrawable2dComponent
    {
        public:
            explicit SpriteRendererComponent(GameObject gameObject);


        public:
            std::shared_ptr<TextureModule> sprite;


        public:
            void draw(Canvas canvas = Canvas(nullptr)) override;

    };
}

#endif //ENGINE_SPRITERENDERERCOMPONENT_HPP
