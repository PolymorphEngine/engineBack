/*
** EPITECH PROJECT, 2020
** ColliderSphere3d.hpp
** File description:
** header for ColliderSphere3d.c
*/


#pragma once

#include <memory>
#include "Core/Component/base/ACollider3d.hpp"
#include "GraphicalAPI/modules/SphereModule.hpp"

namespace Polymorph
{
    class ColliderSphere3dComponent;

    using ColliderSphere3d = safe_ptr<ColliderSphere3dComponent>;
    using ColliderSphere3dBase = std::shared_ptr<ColliderSphere3dComponent>;

    class ColliderSphere3dComponent : public ACollider3dComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit ColliderSphere3dComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SphereRenderer renderer;
            std::shared_ptr<SphereModule> sphere;


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:


        private:
            void setColliderPosition() override;

            bool checkCollision(ACollider3dComponent &other) override;

            void debugDraw() override;


//////////////////////--------------------------/////////////////////////

    };
}
