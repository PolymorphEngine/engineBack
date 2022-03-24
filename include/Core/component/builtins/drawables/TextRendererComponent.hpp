/*
** EPITECH PROJECT, 2020
** TextRendererComponent.hpp
** File description:
** header for TextRendererComponent.c
*/

#ifndef ENGINE_TEXTRENDERERCOMPONENT_HPP
#define ENGINE_TEXTRENDERERCOMPONENT_HPP

#include "component/base/ADrawableComponent.hpp"

namespace Polymorph
{
    class TextModule;
    using Text = safe_ptr<TextModule>;
    class TextRendererComponent;
    using TextRenderer = safe_ptr<TextRendererComponent>;
    using TextRendererBase = std::shared_ptr<TextRendererComponent>;
    
    class TextRendererComponent : public ADrawableComponent
    {
        public:
            explicit TextRendererComponent(Entity &gameObject);


        public:
            Text text;



        public:
            void draw() override;
    };
}

#endif //ENGINE_TEXTRENDERERCOMPONENT_HPP
