/*
** EPITECH PROJECT, 2020
** Display.cpp
** File description:
** Display.cpp
*/

#include "GraphicalAPI/GraphicalAPI.hpp"
#include "GraphicalAPI/ArcadeInterfaces/IDisplayModule.hpp"
#include "GraphicalAPI/DisplayModule.hpp"

#include "GraphicalAPI/ArcadeInterfaces/ISpriteModule.hpp"
#include "DynamicLoader/DynamicLoader.hpp"
#include "GraphicalAPI/SpriteModule.hpp"
#include "settings/VideoSettings.hpp"
#include "GraphicalException.hpp"

namespace Polymorph
{

    DisplayModule::DisplayModule(const std::shared_ptr<Settings::VideoSettings> &settings,
                                 std::string title)
    {
        _settings = settings;
        _title = title;
     }
     
    void DisplayModule::draw(SpriteModule &sprite)
    {
        if (!_displayModule || !sprite.getSprite())
            return;
        _displayModule->draw(sprite.getSprite());
    }

    DisplayModule::~DisplayModule()
    {
        GraphicalAPI::destroyDisplay(this);
    }

    void DisplayModule::clearWindow()
    {
        if (!_displayModule)
            return;
        _displayModule->clearWindow();
    }

    void DisplayModule::displayWindow()
    {
        if (!_displayModule)
            return;
        _displayModule->displayWindow();
    }

    void DisplayModule::close()
    {
        if (!_displayModule)
            return;
        _displayModule->closeWindow();
    }

    bool DisplayModule::isOpen()
    {

        if (!_displayModule)
            return true;
        return _displayModule->isOpen();
    }

    void DisplayModule::fetchEvents()
    {
        if (!_displayModule)
            return;
        _displayModule->fetchInputs();
    }

    void DisplayModule::setResolution(Vector2 newResolution)
    {
        _settings->setResolution(newResolution);
        if (!_displayModule)
            return;
        _displayModule->setResolution(newResolution.x, newResolution.y);
    }

    Vector2 DisplayModule::getResolution()
    {
        if (!_displayModule)
            return{-1, -1};
        return {static_cast<float>(_displayModule->getWindowWidth()),
                static_cast<float>(_displayModule->getWindowHeight())};
    }

    void DisplayModule::setMaxFps(int fps)
    {
        _settings->setMaxFps(fps);
        if (!_displayModule)
            return;
        _displayModule->setFps(fps);
    }

    void DisplayModule::setFullScreen(bool fullScreen)
    {
        _settings->setFullscreen(fullScreen);
        _displayModule->setFullScreen(fullScreen);
    }

    bool DisplayModule::isTextMode()
    {
        if (!_displayModule)
            return true;
        return _displayModule->isTextMode();
    }

    void DisplayModule::draw(TextModule &sprite)
    {
        if (!_displayModule || !sprite.getText())
            return;
        _displayModule->draw(sprite.getText());
    }

    void DisplayModule::_loadModule()
    {
        auto res = _settings->getResolution();
        if (!_displayModule)
            return;
        
        _displayModule->setResolution(res.x, res.y);
        _displayModule->setWindowTitle(_title);
        _displayModule->setFps(_settings->getMaxFps());
        _displayModule->setFullScreen(_settings->getFullscreen());
        
    }
}