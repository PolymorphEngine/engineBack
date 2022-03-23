/*
** EPITECH PROJECT, 2020
** TextRendererComponent.hpp
** File description:
** header for TextRendererComponent.c
*/

#ifndef ENGINE_TEXTRENDERERCOMPONENT_HPP
#define ENGINE_TEXTRENDERERCOMPONENT_HPP

#include "Component.hpp"
#include "ADrawableComponent.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

namespace Polymorph
{
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
