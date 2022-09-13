/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutScript
** File description:
** header for HorizontalGroupLayoutDebug.cpp
*/

#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"

namespace Polymorph
{
    class HorizontalGroupLayoutComponent;

    using HorizontalGroupLayout = safe_ptr<HorizontalGroupLayoutComponent>;
    using HorizontalGroupLayoutBase = std::shared_ptr<HorizontalGroupLayoutComponent>;

    class HorizontalGroupLayoutComponent : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit HorizontalGroupLayoutComponent(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SpriteRenderer ViewPort;
            bool ScaleViewPortWidth;

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