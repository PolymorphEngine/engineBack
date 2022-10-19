/*
** EPITECH PROJECT, 2020
** InputFieldScript
** File description:
** header for InputFieldDebug.cpp
*/

#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "Core/component/builtins/drawables/TextRendererComponent.hpp"

namespace Polymorph
{
    class InputFieldComponent;

    using InputField = safe_ptr<InputFieldComponent>;
    using InputFieldBase = std::shared_ptr<InputFieldComponent>;

    class InputFieldComponent : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit InputFieldComponent(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            enum InputType : int
            {
                AlphaNumeric,
                Text_Only,
                Numbers_Only
            };
            // Here add properties you want to initialize with configuration values in the initializer
            SpriteRenderer PlaceHolder;
            TextRenderer Target;

            InputType Type;
            GameObject OnSubmit;
            GameObject OnValueChanged;
            GameObject OnExitFocus;


        private:
            bool _isFocused = false;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

            bool hasFocus();

        private:

            void _updateFocus();


            //////////////////////--------------------------/////////////////////////

    };
}