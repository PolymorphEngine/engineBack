/*
** EPITECH PROJECT, 2020
** ColliderMesh3d.hpp
** File description:
** header for ColliderMesh3d.c
*/


#pragma once

#include <memory>
#include "Core/component/base/ACollider3d.hpp"
#include "GraphicalAPI/modules/MeshModule.hpp"

namespace Polymorph
{
    class ColliderMesh3dComponent;
    using ColliderMesh3d = safe_ptr<ColliderMesh3dComponent>;
    using ColliderMesh3dBase = std::shared_ptr<ColliderMesh3dComponent>;

    class ColliderMesh3dComponent : public ACollider3dComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit ColliderMesh3dComponent(GameObject gameObject);

        private:
            void debugDraw() override;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            MeshRenderer renderer;
            std::shared_ptr<TextureModule> DebugTexture;



        private:
            std::shared_ptr<BoxModule> _box = nullptr;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            std::shared_ptr<BoxModule> getBox();
            std::shared_ptr<BoxModule> regenBox();

            void onAwake() override;


        private:
            void setColliderPosition() override;

            bool checkCollision(ACollider3dComponent &other) override;


//////////////////////--------------------------/////////////////////////

    };
}
