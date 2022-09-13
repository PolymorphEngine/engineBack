/*
** EPITECH PROJECT, 2020
** SphereRendererComponent.hpp
** File description:
** header for SphereRendererComponent.c
*/


#pragma once

#include "Core/component/base/ADrawable3dComponent.hpp"
#include "GraphicalAPI/modules/SphereModule.hpp"

namespace Polymorph
{
    class SphereModule;
    using Sphere = safe_ptr<SphereModule>;
    class SphereRendererComponent;
    using SphereRenderer = safe_ptr<SphereRendererComponent>;
    using SphereRendererBase = std::shared_ptr<SphereRendererComponent>;

    class SphereRendererComponent : public ADrawable3dComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit SphereRendererComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::shared_ptr<SphereModule> sphere;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void draw() override;

        private:


//////////////////////--------------------------/////////////////////////

    };
}
