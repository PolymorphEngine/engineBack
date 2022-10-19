/*
** EPITECH PROJECT, 2020
** MeshRenderer.hpp
** File description:
** header for MeshRenderer.c
*/

#pragma once

#include "Core/component/base/ADrawable3dComponent.hpp"
#include "GraphicalAPI/modules/MeshModule.hpp"

namespace Polymorph
{
    class TextModule;

    using Mesh = safe_ptr<MeshModule>;

    class MeshRendererComponent;

    using MeshRenderer = safe_ptr<MeshRendererComponent>;
    using MehRendererBase = std::shared_ptr<MeshRendererComponent>;

    class MeshRendererComponent : public ADrawable3dComponent
    {
        public:
            explicit MeshRendererComponent(GameObject gameObject);


        public:
            std::shared_ptr<MeshModule> mesh;
            std::shared_ptr<TextureModule> texture;


        public:
            void start() override;

            void draw() override;

            void setTexture(const std::shared_ptr<TextureModule> &texture);
    };
}