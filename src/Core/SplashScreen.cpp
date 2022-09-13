/*
** EPITECH PROJECT, 2022
** SplashScreen.cpp
** File description:
** SplashScreen.cpp
*/


#include "Core/SplashScreen.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"
#include "GraphicalAPI/modules/TextModule.hpp"
#include "GraphicalAPI/modules/DisplayModule.hpp"

Polymorph::SplashScreen::SplashScreen()
{
    _icon = std::make_unique<TextureModule>("./Engine/PolymorphEngineIcon.png");
    _label = std::make_unique<TextModule>("Made with PolymorphEngine", 40);
    _icon->setPosition(Vector2(0.42f * GraphicalAPI::CurrentDisplay->getResolution().x,
                               0.35f * GraphicalAPI::CurrentDisplay->getResolution().y));
    _label->setPosition(Vector2(0.35f * GraphicalAPI::CurrentDisplay->getResolution().x,
                                0.65f * GraphicalAPI::CurrentDisplay->getResolution().y));

    GraphicalAPI::CurrentDisplay->clearWindow();
    GraphicalAPI::CurrentDisplay->beginDrawing();
    _icon->draw();
    _label->draw();
    GraphicalAPI::CurrentDisplay->endDrawing();
}

bool Polymorph::SplashScreen::isFinished()
{
    return _done;
}

void Polymorph::SplashScreen::update()
{
    _fadeOutTimer.tick();
    if (!_fadeOutTimer.timeIsUp(true))
        return;
    if (_currentAlpha <= 0)
    {
        _done = true;
        return;
    }
    _currentAlpha -= 1;
    GraphicalAPI::CurrentDisplay->clearWindow();
    _icon->setColor(Color(255, 255, 255, _currentAlpha));
    _label->setColor(Color(255, 255, 255, _currentAlpha));
    GraphicalAPI::CurrentDisplay->beginDrawing();
    _icon->draw();
    _label->draw();
    GraphicalAPI::CurrentDisplay->endDrawing();
}
