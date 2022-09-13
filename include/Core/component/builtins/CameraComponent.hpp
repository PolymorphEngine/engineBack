/*
** EPITECH PROJECT, 2020
** CameraComponent.hpp
** File description:
** header for CameraComponent.c
*/


#pragma once

#include <vector>
#include <functional>
#include "Core/component/base/Component.hpp"
#include "Utilities/safe_ptr.hpp"
#include "Utilities/types/Vector.hpp"
#include "Utilities/Time.hpp"
#include "GraphicalAPI/modules/CameraModule.hpp"

namespace Polymorph
{

    class CameraComponent;
    using Camera = safe_ptr<CameraComponent>;
    using CameraBase = std::shared_ptr<CameraComponent>;

    class CameraComponent : public Component
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit CameraComponent(GameObject gameObject);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            enum CameraTargetType : int
            {
                Point,
                Object,
            };
            CameraTargetType TargetType;
            GameObject ObjectTarget;
            Vector3 PointTarget;

            void update() override;

            void start() override;

            std::shared_ptr<CameraModule> camera;
            static inline CameraComponent *Current = nullptr;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            bool isTargetingObject();
            GameObject getTargetObject();
            void setTargetPosition(Vector3 targetPosition);
            void setTargetObject(GameObject object);
            void setUp(Vector3 up);
            void setFov(float fov);
            void begin3dMode();
            void end3dMode();
            

        private:


//////////////////////--------------------------/////////////////////////

    };

}
