/*
** EPITECH PROJECT, 2020
** SpriteAnimatorScript
** File description:
** header for SpriteAnimator.c
*/


#pragma once

#include "Polymorph/Components.hpp"
#include "Polymorph/Types.hpp"
#include "SpriteAnimation.hpp"

namespace Polymorph
{
    class SpriteAnimatorScript;

    using SpriteAnimator = safe_ptr<SpriteAnimatorScript>;
    using SpriteAnimatorBase = std::shared_ptr<SpriteAnimatorScript>;

    class SpriteAnimatorScript : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit SpriteAnimatorScript(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SpriteRenderer targetGraphics;
            std::vector<std::shared_ptr<SpriteAnimation>> animations;
            std::string currentAnimation;


        private:
            Timer _timer;
            std::shared_ptr<SpriteAnimation> _currentAnimation;
            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;
            
            void startAnimation(std::string animationName);
            void addAnimCallBack(MeshAnimation::AnimationCallBack callback, std::string animationName = "");
            void clearAnimationCallbacks(std::string name = "");
            void setAnimationFrameTime(std::string name, float frameTime);
            float getAnimationFrameTime(std::string name);
            
        private:

            //////////////////////--------------------------/////////////////////////

    };
}