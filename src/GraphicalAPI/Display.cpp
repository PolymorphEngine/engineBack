/*
** EPITECH PROJECT, 2020
** Display.cpp
** File description:
** Display.cpp
*/

#include "GraphicalAPI/Display.hpp"
#include "GraphicalAPI/ArcadeInterfaces/IDisplayModule.hpp"
#include "GraphicalAPI/ArcadeInterfaces/ISpriteModule.hpp"
#include "GraphicalAPI/DynamicLoader.hpp"
#include "GraphicalAPI/Sprite.hpp"
#include "settings/VideoSettings.hpp"
#include "GraphicalException.hpp"

namespace Polymorph
{

    Display::Display(const std::shared_ptr<Settings::VideoSettings> &settings,
    std::string title)
    {
        _settings = settings;
        _title = title;
        _instance = this;
        try {
            create = DynamicLibLoader::loadSymbol<loader>("createDisplay");
            destroy = DynamicLibLoader::loadSymbol<unloader>("destroyDisplay");
        } catch(const std::exception &e) {
            e.what();
            throw GraphicalException("Error loading Display module symbols", Logger::MINOR);
        }
        _displayModule = create();
        auto res = settings->getResolution();
        _displayModule->setResolution(res.x, res.y);
        _displayModule->setWindowTitle(_title);
        _displayModule->setFps(settings->getMaxFps());
        _displayModule->setFullScreen(settings->getFullscreen());
    }




    void Display::_loadModule()
    {
        _displayModule = create();
    }

    void Display::_unloadModule()
    {
        destroy(_displayModule);
    }
    
    
    
    
    
    //STATICS:
    void Display::loadModule()
    {
        if (!create || !destroy)
        {
            try {
                create = DynamicLibLoader::loadSymbol<loader>("createSprite");
                destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
            } catch(const GraphicalException &e) {
                e.what();
                throw GraphicalException("Error loading sprite module symbols", Logger::MAJOR);
            }
        }
        _instance->_loadModule();
    }

    void Display::unloadModule()
    {
        _instance->_unloadModule();
        create = nullptr;
        destroy = nullptr;
        
    }

    void Display::draw(Sprite &sprite)
    {
        if (!_instance->_displayModule || !sprite.getSprite())
            return;
        _instance->_displayModule->draw(sprite.getSprite());
    }

    Display::~Display()
    {
        if (_displayModule && destroy)
            destroy(_displayModule);
    }

    void Display::clearWindow()
    {
        if (!_displayModule)
            return;
        _displayModule->clearWindow();
    }

    void Display::displayWindow()
    {
        if (!_displayModule)
            return;
        _displayModule->displayWindow();
    }

    void Display::close()
    {
        if (!_displayModule)
            return;
        _displayModule->closeWindow();
    }

    bool Display::isOpen()
    {

        if (!_displayModule)
            return true;
        return _displayModule->isOpen();
    }

    void Display::fetchEvents()
    {
        if (!_displayModule)
            return;
        _displayModule->fetchInputs();
    }

    void Display::setResolution(Vector2 newResolution)
    {
        _instance->_settings->setResolution(newResolution);
        _instance->_displayModule->setResolution(newResolution.x, newResolution.y);
    }

    Vector2 Display::getResolution()
    {
        return {static_cast<float>(_instance->_displayModule->getWindowWidth()),
                static_cast<float>(_instance->_displayModule->getWindowHeight())};
    }

    void Display::setMaxFps(int fps)
    {
        _instance->_settings->setMaxFps(fps);
        _instance->_displayModule->setFps(fps);
    }

    void Display::setFullScreen(bool fullScreen)
    {
        _instance->_settings->setFullscreen(fullScreen);
        _instance->_displayModule->setFullScreen(fullScreen);
    }

    bool Display::isTextMode()
    {
        return _instance->_displayModule->isTextMode();
    }
}