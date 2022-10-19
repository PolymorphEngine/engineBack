/*
** EPITECH PROJECT, 2020
** TextRendererComponent.hpp
** File description:
** header for TextRendererComponent.c
*/

#ifndef ENGINE_TEXTRENDERERCOMPONENT_HPP
#define ENGINE_TEXTRENDERERCOMPONENT_HPP

#include "Core/Component/base/ADrawable2dComponent.hpp"
#include "GraphicalAPI/modules/TextModule.hpp"

namespace Polymorph
{
    class TextModule;

    using Text = safe_ptr<TextModule>;

    class TextRendererComponent;

    using TextRenderer = safe_ptr<TextRendererComponent>;
    using TextRendererBase = std::shared_ptr<TextRendererComponent>;

    class TextRendererComponent : public ADrawable2dComponent
    {
        public:
            explicit TextRendererComponent(GameObject gameObject);


        public:
            std::shared_ptr<TextModule> text;


        public:
            void draw(Canvas canvas = Canvas(nullptr)) override;
    };
}

#endif //ENGINE_TEXTRENDERERCOMPONENT_HPP
