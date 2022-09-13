/*
** EPITECH PROJECT, 2022
** BoxModule.cpp
** File description:
** BoxModule.cpp
*/


#include "GraphicalAPI/GraphicalAPI.hpp"
#include "GraphicalAPI/modules/BoxModule.hpp"
#include "GraphicalAPI/modules/MeshModule.hpp"
#include "GraphicalAPI/modules/SphereModule.hpp"

Polymorph::BoxModule::BoxModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_size", data, _size);
    manager.setSubProperty("_origin", data, _origin);
    _box = std::unique_ptr<is::IBoxModule>(_c_box(_size.x, _size.y, _size.z));
    setSize(_size);
    setOrigin(_origin);
}

Polymorph::BoxModule::BoxModule(const MeshModule &meshModule)
{
    _loadModule();
    _box = std::unique_ptr<is::IBoxModule>(_c_box_from_model(meshModule.getMesh()));
    setSize({_box->getXSize(), _box->getYSize(), _box->getZSize()});
    setOrigin({_box->getXOrigin(), _box->getYOrigin(), _box->getZOrigin()});
}

void Polymorph::BoxModule::setSize(Polymorph::Vector3 size)
{
    _size = size;
    _box->setSize(size.x, size.y, size.z);
}

Polymorph::Vector3 Polymorph::BoxModule::getSize() const
{
    return _size;
}

void Polymorph::BoxModule::setOrigin(Polymorph::Vector3 origin)
{
    _origin = origin;
    _box->setOrigin(origin.x, origin.y, origin.z);
}

is::IBoxModule &Polymorph::BoxModule::getBox() const
{
    return *_box;
}

bool Polymorph::BoxModule::collideWithBox(const Polymorph::BoxModule &box) const
{
    return _box->collideWithBox(box.getBox());
}

bool Polymorph::BoxModule::collideWithSphere(const Polymorph::SphereModule &sphere) const
{
    return _box->collideWithSphere(sphere.getSphere());
}

void Polymorph::BoxModule::setTexture(const std::shared_ptr<TextureModule>& texture)
{
    _texture = texture;
    _box->setTexture(texture->getTexture());
}

std::shared_ptr<Polymorph::TextureModule> Polymorph::BoxModule::getTexture() const
{
    return _texture;
}

void Polymorph::BoxModule::draw()
{
    _box->draw();
}

void Polymorph::BoxModule::drawWires()
{
    _box->drawWires();
}

void Polymorph::BoxModule::_loadModule()
{
    if (_c_box)
        return;
    _c_box = GraphicalAPI::loadSymbol<BoxModuleLoader, GraphicalAPI>("createBoxModule");
    _c_box_from_model = GraphicalAPI::loadSymbol<BoxModuleFromMeshLoader, GraphicalAPI>("createBoxModuleFromModel");
}
