/*
** EPITECH PROJECT, 2020
** MonoMeshAnimator.hpp
** File description:
** header for MonoMeshAnimator.c
*/

#include <unordered_map>
#include "GraphicalAPI/modules/MeshModule.hpp"
#include "MeshAnimation.hpp"
#include "GraphicalAPI/modules/MeshAnimationModule.hpp"

#pragma once

namespace Polymorph
{
    class ColliderMesh3dComponent;

    using ColliderMesh3d = safe_ptr<ColliderMesh3dComponent>;

    class MonoMeshAnimatorComponent;

    using MonoMeshAnimator = safe_ptr<MonoMeshAnimatorComponent>;
    using MonoMeshAnimatorBase = std::shared_ptr<MonoMeshAnimatorComponent>;

    class MonoMeshAnimatorComponent : public Component
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MonoMeshAnimatorComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            MeshRenderer target;
            bool animEnabled;
            std::string currentAnimationName;
            std::vector<std::shared_ptr<MeshAnimationModule>> anims;

        private:
            std::shared_ptr<MeshAnimationModule> _currentAnimation;
            ColliderMesh3d _collider;
            //bool _changedAnim = false;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;

            void start() override;

            void
            addAnimCallBack(const MeshAnimation::AnimationCallBack &callback);

            void setAnimation(const std::string &animationName);

        private:


//////////////////////--------------------------/////////////////////////

    };

}
