/*
** EPITECH PROJECT, 2022
** CameraModule.cpp
** File description:
** CameraModule.cpp
*/

#include "GraphicalAPI/modules/CameraModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::CameraModule::CameraModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
        : _fov(45)
{
    _loadModule();
    manager.setSubProperty("_up", data, _up);
    manager.setSubProperty("_position", data, _position);
    manager.setSubProperty("_target", data, _target);
    manager.setSubProperty("_fov", data, _fov);
    _camera = std::unique_ptr<Polymorph::ICameraModule>(_c_camera());
    _camera->setUp(_up.x, _up.y, _up.z);
    _camera->setPosition(_position.x, _position.y, _position.z);
    _camera->setTarget(_target.x, _target.y, _target.z);
    _camera->setFOV(_fov);
}

void Polymorph::CameraModule::setTarget(Vector3 target)
{
    _target = target;
    _camera->setTarget(_target.x, _target.y, _target.z);
}

void Polymorph::CameraModule::setPosition(Vector3 pos)
{
    _position = pos;
    _camera->setPosition(_position.x, _position.y, _position.z);
}

void Polymorph::CameraModule::move(Vector3 pos)
{
    _position = pos;
    _camera->move(pos.x, pos.y, pos.z);
}

void Polymorph::CameraModule::setUp(Vector3 up)
{
    _up = up;
    _camera->setUp(up.x, up.y, up.z);
}

void Polymorph::CameraModule::setFOV(float fov)
{
    _fov = fov;
    _camera->setFOV(_fov);
}

void Polymorph::CameraModule::begin3DMode()
{
    //TODO: warning 3D mode disabled
    //_camera->begin3DMode();
}

void Polymorph::CameraModule::end3DMode()
{
    //TODO: warning 3D mode disabled
    //_camera->end3DMode();
}

float Polymorph::CameraModule::getFov() const
{
    return _fov;
}

Polymorph::Vector3 Polymorph::CameraModule::getUp() const
{
    return _up;
}

void Polymorph::CameraModule::_loadModule()
{
    if (_c_camera)
        return;
    _c_camera = GraphicalAPI::loadSymbol<CameraModuleLoader, GraphicalAPI>("createCameraModule");
}
