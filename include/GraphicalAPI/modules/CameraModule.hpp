/*
** EPITECH PROJECT, 2020
** CameraModule.hpp
** File description:
** header for CameraModule.c
*/


#pragma once

#include "myxmlpp.hpp"
#include "Polymorph/Types.hpp"
#include "isModules/interfaces/ICameraModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{
    class CameraModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit CameraModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager);
            ~CameraModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using CameraModuleLoader = is::ICameraModule *(*)();
            static inline CameraModuleLoader _c_camera = nullptr;

            std::unique_ptr<is::ICameraModule> _camera;
            float _fov;
            Vector3 _up;
            Vector3 _position;
            Vector3 _target;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setTarget(Vector3 target);
            void setPosition(Vector3 pos);
            void move(Vector3 pos);
            Vector3 getUp() const;
            void setUp(Vector3 up);
            float getFov() const;
            void setFOV(float fov);
            void begin3DMode();
            void end3DMode();

        private:
            void _loadModule();


//////////////////////--------------------------/////////////////////////

};
}
