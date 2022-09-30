/*
** EPITECH PROJECT, 2020
** BoxRendererComponent.hpp
** File description:
** header for BoxRendererComponent.c
*/

#pragma once

#include "Core/component/base/ADrawable3dComponent.hpp"
#include "GraphicalAPI/modules/BoxModule.hpp"

namespace Polymorph
{
    class TextureModule;

    class BoxRendererComponent;

    using BoxRenderer = safe_ptr<BoxRendererComponent>;
    using BoxRendererBase = std::shared_ptr<BoxRendererComponent>;

    class BoxRendererComponent : public ADrawable3dComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit BoxRendererComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::shared_ptr<BoxModule> box;
            std::shared_ptr<TextureModule> texture;


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void setTexture(const std::shared_ptr<TextureModule> &texture);


        private:
            void draw() override;

//////////////////////--------------------------/////////////////////////

    };

}
