/*
** EPITECH PROJECT, 2020
** ButtonScript
** File description:
** header for ButtonDebug.cpp
*/

#pragma once

#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"
#include "Core/component/builtins/drawables/SpriteRendererComponent.hpp"

namespace Polymorph
{
    class ButtonComponent;

    using Button = safe_ptr<ButtonComponent>;
    using ButtonBase = std::shared_ptr<ButtonComponent>;

    class ButtonComponent : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ButtonComponent(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SpriteRenderer Target;
            std::shared_ptr<TextureModule> HoverTexture;
            std::shared_ptr<TextureModule> ClickTexture;
            GameObject onClickHandler;
            GameObject onReleaseHandler;
            GameObject onHoldHandler;
            // Here add properties you want to initialize with configuration values in the initializer

        private:
            std::shared_ptr<TextureModule> _defaultTexture;
            Timer _delayTimer = Timer(0.5);

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}