/*
** EPITECH PROJECT, 2020
** MeshAnimation.hpp
** File description:
** header for MeshAnimation.c
*/


#pragma once

#include <unordered_map>
#include <functional>
#include "GraphicalAPI/modules/MeshModule.hpp"
#include "Core/Component/builtins/drawables/MeshRendererComponent.hpp"


namespace Polymorph
{
    class MeshFrame;

    class MeshAnimation
    {
        public:

            MeshAnimation(std::shared_ptr<myxmlpp::Node> &data,
                          Config::XmlComponent &manager);

            explicit MeshAnimation() = default;

            using AnimationCallBack = std::function<void(void)>;


        public:
            std::vector<std::shared_ptr<MeshFrame>> frames;
            std::string animationName;

        private:
            std::vector<AnimationCallBack> _callBacks;


        public:
            void addEndAnimCallBack(AnimationCallBack callback);

            void invokeCallBacks();

    };
}