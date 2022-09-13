/*
** EPITECH PROJECT, 2020
** MeshAnimator.hpp
** File description:
** header for MeshAnimator.c
*/

#include <unordered_map>
#include "GraphicalAPI/modules/MeshModule.hpp"
#include "MeshAnimation.hpp"

#pragma once

namespace Polymorph
{

    class MeshAnimatorComponent;
    using MeshAnimator = safe_ptr<MeshAnimatorComponent>;
    using MeshAnimatorBase = std::shared_ptr<MeshAnimatorComponent>;

    class MeshAnimatorComponent : public Component
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MeshAnimatorComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            MeshRenderer target;
            std::string currentAnimationName;
            std::vector<std::shared_ptr<MeshAnimation>> _animations;


        private:
            std::vector<std::shared_ptr<MeshFrame>>::iterator _currentFrame;
            Timer _timer;
            std::shared_ptr<MeshAnimation> _currentAnimation;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;
            void start() override;
            void addMesh(float time, std::shared_ptr<Polymorph::MeshModule> mesh, std::string &animationName);
            void setAnimation(std::string animationName);
            void addAnimCallBack(MeshAnimation::AnimationCallBack callback, std::string animationName = "");


        private:


//////////////////////--------------------------/////////////////////////

    };

}
