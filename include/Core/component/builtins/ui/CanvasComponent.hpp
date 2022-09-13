/*
** EPITECH PROJECT, 2020
** CanvasScript
** File description:
** header for CanvasDebug.cpp
*/

#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"

namespace Polymorph
{
    class CanvasComponent;

    using Canvas = safe_ptr<CanvasComponent>;
    using CanvasBase = std::shared_ptr<CanvasComponent>;

    class CanvasComponent : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit CanvasComponent(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Camera Target;
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