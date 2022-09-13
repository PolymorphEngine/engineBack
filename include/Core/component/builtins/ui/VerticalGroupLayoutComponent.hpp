/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutScript
** File description:
** header for VerticalGroupLayoutDebug.cpp
*/

#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"

namespace Polymorph
{
    class VerticalGroupLayoutComponent;

    using VerticalGroupLayout = safe_ptr<VerticalGroupLayoutComponent>;
    using VerticalGroupLayoutBase = std::shared_ptr<VerticalGroupLayoutComponent>;

    class VerticalGroupLayoutComponent : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit VerticalGroupLayoutComponent(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SpriteRenderer ViewPort;
            bool ScaleViewPortHeight;

            float Spacing;
            float LeftPadding;
            float RightPadding;
            float TopPadding;
            float DownPadding;

            bool ControlChildWidth;
            bool ControlChildHeight;
            // Here add properties you want to initialize with configuration values in the initializer

        private:

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}