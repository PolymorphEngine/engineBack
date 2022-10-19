/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#pragma once

#include "Core/Component/base/ACollider3d.hpp"
#include "GraphicalAPI/modules/BoxModule.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"
#include "GraphicalAPI/modules/MeshModule.hpp"

namespace Polymorph
{
    class BoxColliderComponent;

    using BoxCollider = safe_ptr<BoxColliderComponent>;
    using BoxColliderBase = std::shared_ptr<BoxColliderComponent>;

    class BoxColliderComponent : public ACollider3dComponent
    {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            explicit BoxColliderComponent(GameObject entity);

///////////////////////////--------------------------///////////////////////////

///////////////////////////////// Properties ///////////////////////////////////

        public:
            BoxRenderer renderer;
            std::shared_ptr<BoxModule> box;
            std::shared_ptr<TextureModule> DebugTexture;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            void setColliderPosition() override;

            bool checkCollision(ACollider3dComponent &other) override;

            void debugDraw() override;

///////////////////////////--------------------------///////////////////////////

    };
}