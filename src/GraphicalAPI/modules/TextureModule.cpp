/*
** EPITECH PROJECT, 2022
** MeshModule.cpp
** File description:
** MeshModule.cpp
*/


#include "GraphicalAPI/modules/TextureModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"
#include "Polymorph/Types.hpp"

Polymorph::TextureModule::TextureModule(const std::string &path)
{
    _loadModules();
    _filepath = path;
    _texture = std::unique_ptr<Polymorph::ITextureModule>(_c_texture(_filepath));
    _color = Color{255, 255, 255, 255};
    _crop = {0, 0, 256, 256};
    _image = nullptr;
}

Polymorph::TextureModule::TextureModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModules();
    manager.setSubProperty("_filepath", data, _filepath);
    manager.setSubProperty("_color", data, _color);
    _filepath = "./Game/Assets/" + _filepath;
    _texture = std::unique_ptr<Polymorph::ITextureModule>(_c_texture(_filepath));
    _image = std::unique_ptr<Polymorph::IImageModule>(_c_image(_filepath));
    manager.setSubProperty("_crop", data, _crop);
    if (_color.r == 0 && _color.g == 0 && _color.b == 0 && _color.a == 0)
        setColor(Color{255, 255, 255, 255});
    if (_crop.width == 0 && _crop.height == 0)
        _crop = {_crop.x, _crop.y, _image->getWCrop(), _image->getHCrop()};
    else
        setCrop(_crop);
    _image = nullptr;
}

void Polymorph::TextureModule::setPosition(Vector2 position)
{
	_texture->setPosition(position.x, position.y);
}

void Polymorph::TextureModule::setScale(Vector2 scale)
{
    this->scale = scale;
	_flipTextureToImage();
	_image->setScale(scale.x, scale.y);
	_flipImageToTexture();
}

void Polymorph::TextureModule::setCrop(Rect crop)
{
    if (crop.width == 0 || crop.height == 0)
        return;
	//_flipTextureToImage();
    _crop = crop;
	//_image->crop(crop.x, crop.y, crop.width, crop.height);
	//_flipImageToTexture();
    _texture->setTextureRect(crop.x, crop.y, crop.width, crop.height);
}

Polymorph::Rect Polymorph::TextureModule::getCrop()
{
    /*
    _flipTextureToImage();
    auto r = Rect(_crop.x, _crop.y, _image->getWCrop(), _image->getHCrop());
    _flipImageToTexture(); */
    return _crop;
}

void Polymorph::TextureModule::draw()
{
    _texture->draw(_color.r, _color.g, _color.b, _color.a);
}

void Polymorph::TextureModule::_flipTextureToImage()
{
	_image = std::unique_ptr<Polymorph::IImageModule>(_c_image_from_texture(*_texture));
    _texture = nullptr;
}

void Polymorph::TextureModule::_flipImageToTexture()
{
    _texture = std::unique_ptr<Polymorph::ITextureModule>(_c_texture_from_image(*_image));
    _image = nullptr;
}

Polymorph::Color Polymorph::TextureModule::getColor() const
{
    return _color;
}

void Polymorph::TextureModule::setColor(Polymorph::Color color)
{
    _color = color;
}

void Polymorph::TextureModule::_loadModules()
{
    if (_c_texture && _c_image)
        return;
    _c_texture = GraphicalAPI::loadSymbol<TextureModuleLoader, GraphicalAPI>("createTextureModule");
    _c_texture_from_image = GraphicalAPI::loadSymbol<TextureModuleFromImageLoader, GraphicalAPI>("createTextureModuleFromImage");
    _c_image = GraphicalAPI::loadSymbol<ImageModuleLoader, GraphicalAPI>("createImageModule");
    _c_image_from_texture = GraphicalAPI::loadSymbol<ImageModuleFromTextureLoader, GraphicalAPI>("createImageModuleFromTexture");
}

Polymorph::ITextureModule &Polymorph::TextureModule::getTexture() const
{
    return *_texture;
}

float Polymorph::TextureModule::getTextureWidth()
{
    return _texture->getTextureWidth();
}

float Polymorph::TextureModule::getTextureHeight()
{
    return _texture->getTextureHeight();
}
/*
Polymorph::Vector2 Polymorph::TextureModule::getSize()
{
    return {_crop.width * _scale.x, _crop.height * _scale.y};
}
*/