/*
** EPITECH PROJECT, 2020
** SpriteAnimation.hpp
** File description:
** header for SpriteAnimation.c
*/


#pragma once

#include "Core/component/base/ADrawable2dComponent.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"

namespace Polymorph
{

    class SpriteAnimation
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SpriteAnimation(std::shared_ptr<myxmlpp::Node> &data,
                            Config::XmlComponent &manager);

            ~SpriteAnimation();

            using AnimationCallBack = std::function<void(void)>;


            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::string animationName;
            std::shared_ptr<TextureModule> sprite;
            int nbFrames;
            float yOffset;
            float frameTime;


        private:
            Rect _currentFrame;
            float _width;
            float _height;
            int currentFrame = 1;
            std::vector<AnimationCallBack> _callBacks;


            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void addEndAnimCallBack(AnimationCallBack callback);

            void invokeCallBacks();

            void nextFrame();

            void clear();

            void setAnimationFrameTime(float frameTime);

        private:


            //////////////////////--------------------------/////////////////////////

    };
}
