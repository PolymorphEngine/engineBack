/*
** EPITECH PROJECT, 2022
** SphereModule.cpp
** File description:
** SphereModule.cpp
*/

#include "GraphicalAPI/modules/SphereModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::SphereModule::SphereModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_center", data, _center);
    manager.setSubProperty("_color", data, _color);
    manager.setSubProperty("_radius", data, _radius);
    _sphere = std::unique_ptr<is::ISphereModule>(_c_sphere(_center.x, _center.y, _center.z, _radius));
    setColor(_color);
}

void Polymorph::SphereModule::setCenter(Polymorph::Vector3 center)
{
    _center = center;
    _sphere->setCenter(center.x, center.y, center.z);
}

void Polymorph::SphereModule::setRadius(float radius)
{
    _radius = radius;
    _sphere->setRadius(radius);
}

void Polymorph::SphereModule::setColor(Color color)
{
    _color = Polymorph::Color(color.r, color.g, color.b, color.a);
    _sphere->setColor(color.r, color.g, color.b, color.a);
}

is::ISphereModule &Polymorph::SphereModule::getSphere() const
{
    return *_sphere;
}

bool Polymorph::SphereModule::collideWithBox(const BoxModule &box) const
{
    return _sphere->collideWithBox(box.getBox());
}

bool Polymorph::SphereModule::collideWithSphere(const SphereModule &sphere) const
{
    return _sphere->collideWithSphere(sphere.getSphere());
}

void Polymorph::SphereModule::draw()
{
    _sphere->draw();
}

Polymorph::Vector3 Polymorph::SphereModule::getCenter() const
{
    return _center;
}

float Polymorph::SphereModule::getRadius() const
{
    return _radius;
}

Polymorph::Color Polymorph::SphereModule::getColor() const
{
    return _color;
}

void Polymorph::SphereModule::_loadModule()
{
    if (_c_sphere)
        return;
    _c_sphere = GraphicalAPI::loadSymbol<SphereModuleLoader, GraphicalAPI>("createSphereModule");
}

Polymorph::SphereModule::SphereModule(): _sphere(nullptr), _center(0, 0, 0), _radius(0), _color(0, 0, 0, 0)
{
}
