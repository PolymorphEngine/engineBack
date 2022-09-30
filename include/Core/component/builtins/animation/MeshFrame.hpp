/*
** EPITECH PROJECT, 2020
** MeshFrame.hpp
** File description:
** header for MeshFrame.c
*/


#pragma once

#include <unordered_map>
#include "GraphicalAPI/modules/MeshModule.hpp"
#include "Core/component/builtins/drawables/MeshRendererComponent.hpp"

namespace Polymorph
{

    class MeshFrame
    {
        public:
            MeshFrame(std::shared_ptr<myxmlpp::Node> &data,
                      Config::XmlComponent &manager);

            explicit MeshFrame() = default;

        public:
            float frameTime;
            std::shared_ptr<TextureModule> texture;
            std::shared_ptr<MeshModule> model;
    };
}