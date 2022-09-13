/*
** EPITECH PROJECT, 2022
** MeshModule.cpp
** File description:
** MeshModule.cpp
*/

#include "GraphicalAPI/modules/MeshModule.hpp"
#include "GraphicalAPI/modules/SphereModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::MeshModule::MeshModule(const std::string &path)
{
    _loadModule();
    _filepath = path;
    _model = std::unique_ptr<is::IModelModule>(_c_model(_filepath));
    _model->setPosition(0, 0, 0);
}

Polymorph::MeshModule::MeshModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_filepath", data, _filepath);
    _filepath = "./Game/Assets/" + _filepath;
    _model = std::unique_ptr<is::IModelModule>(_c_model(_filepath));
    _model->setPosition(0, 0, 0);
    setColor(Color(255, 255, 255, 255));
    manager.setSubProperty("_color", data, _color);
    manager.setSubProperty("_rotationAngle", data, _rotationAngle);
    setColor(_color);
    setScale(Vector3(3, 3, 3));
    setRotationAngle(_rotationAngle);
}

void Polymorph::MeshModule::setPosition(Polymorph::Vector3 position)
{
	_model->setPosition(position.x, position.y, position.z);
}

void Polymorph::MeshModule::setScale(Polymorph::Vector3 scale)
{
	_model->setScale(scale.x, scale.y, scale.z);
}

void Polymorph::MeshModule::setRotationAxis(Polymorph::Vector3 rotationAxis)
{
	_model->setRotationAxis(rotationAxis.x, rotationAxis.y, rotationAxis.z);
}

void Polymorph::MeshModule::setRotationAngle(float rotationAngle)
{
	_model->setRotationAngle(rotationAngle);
	_rotationAngle = rotationAngle;
}

void Polymorph::MeshModule::setColor(Polymorph::Color color)
{
	_model->setColor(color.r, color.g, color.b, color.a);
	_color = color;
}

void Polymorph::MeshModule::draw()
{
	_model->draw();
}

Polymorph::Color Polymorph::MeshModule::getColor() const
{
	return _color;
}

void Polymorph::MeshModule::_loadModule()
{
    if (_c_model)
        return;
    _c_model = GraphicalAPI::loadSymbol<MeshModuleLoader, GraphicalAPI>("createModelModule");
}

float Polymorph::MeshModule::getRotationAngle() const
{
    return _rotationAngle;
}

bool
Polymorph::MeshModule::collideWithBox(const Polymorph::BoxModule &box) const
{
    return _model->collideWithBox(box.getBox());
}

bool Polymorph::MeshModule::collideWithSphere(const Polymorph::SphereModule &sphere) const
{
    return _model->collideWithSphere(sphere.getSphere());
}

bool
Polymorph::MeshModule::colliderWithMesh(const Polymorph::MeshModule &mesh) const
{
    return _model->collideWithModel(*mesh._model);
}

is::IModelModule &Polymorph::MeshModule::getMesh() const
{
    return *_model;
}

Polymorph::BoxModule Polymorph::MeshModule::getBoundingBox() const
{
    return BoxModule(*this);
}

void Polymorph::MeshModule::setTexture(const std::shared_ptr<TextureModule> &texture)
{
    _internalTexture = texture;
    _model->setTexture(texture->getTexture());
}
