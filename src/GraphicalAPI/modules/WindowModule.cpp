/*
** EPITECH PROJECT, 2022
** WindowModule.cpp
** File description:
** WindowModule.cpp
*/

#include "GraphicalAPI/modules/DisplayModule.hpp"
#include "DynamicLoader/DynamicLoader.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"
#include "GraphicalAPI/modules/Input.hpp"

Polymorph::DisplayModule::DisplayModule(std::shared_ptr<Settings::VideoSettings> &settings, std::string title):
        _settings(std::move(settings)), _title(std::move(title))
{
    _loadModule();
    _windowModule = std::unique_ptr<is::IWindowModule>(_c_window(_settings->getResolution().x,
                                                                 _settings->getResolution().y, _title));
    _drawingModule = std::unique_ptr<is::IDrawingModule>(_c_drawing());
    setFullscreen(_settings->getFullscreen());
    setTitle(_title);
    Input::init();
}

Polymorph::DisplayModule::~DisplayModule()
{
    if (isOpen())
        close();
}

void Polymorph::DisplayModule::close()
{
    if (isOpen())
        _windowModule->close();
}

bool Polymorph::DisplayModule::isOpen()
{
    return _windowModule->isOpen();
}

bool Polymorph::DisplayModule::isFullscreen()
{
    return _windowModule->isFullscreen();
}

void Polymorph::DisplayModule::setFullscreen(bool fullscreen)
{
    return _windowModule->setFullscreen(fullscreen);
}

void Polymorph::DisplayModule::setTitle(const std::string &title)
{
    _windowModule->setTitle(title);
}

Polymorph::Vector2 Polymorph::DisplayModule::getResolution() const
{
    return _settings->getResolution();
}

void Polymorph::DisplayModule::clearWindow(Polymorph::Color color)
{
    _drawingModule->clear(color.r, color.g, color.b, color.a);
}

void Polymorph::DisplayModule::clearWindow()
{
    _drawingModule->clear(0, 0, 0, 255);
}

void Polymorph::DisplayModule::beginDrawing()
{
    _drawingModule->beginDrawing();
}

void Polymorph::DisplayModule::endDrawing()
{
    _drawingModule->endDrawing();
}

void Polymorph::DisplayModule::_loadModule()
{
    if (_c_window)
        return;
    _c_window = GraphicalAPI::loadSymbol<WindowModuleLoader , GraphicalAPI>("createWindowModule");
    if (_c_drawing)
        return;
    _c_drawing = GraphicalAPI::loadSymbol<DrawingModuleLoader, GraphicalAPI>("createDrawingModule");
}

void Polymorph::DisplayModule::setLogLevel(int level)
{
    _windowModule->setLogLevel(level);
}
