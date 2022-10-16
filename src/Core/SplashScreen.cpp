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

Polymorph::Vector2 centerTexture(std::unique_ptr<Polymorph::TextureModule>& texture, Polymorph::Vector2 wantedPos)
{
    return Polymorph::Vector2(((Polymorph::GraphicalAPI::CurrentDisplay->getResolution().x / 2) - texture->getTextureWidth() / 2) + wantedPos.x,
                              ((Polymorph::GraphicalAPI::CurrentDisplay->getResolution().y / 2) - texture->getTextureHeight() / 2) + wantedPos.y);
}

Polymorph::Vector2 centerText(std::unique_ptr<Polymorph::TextModule>& text, Polymorph::Vector2 wantedPos, float correction)
{
    return Polymorph::Vector2(((Polymorph::GraphicalAPI::CurrentDisplay->getResolution().x / 2)  - (text->getString().size() * correction) * text->getFontSize()) + wantedPos.x,
                              (Polymorph::GraphicalAPI::CurrentDisplay->getResolution().y / 2) + wantedPos.y);
}

Polymorph::SplashScreen::SplashScreen(std::string path)
{
    if (path.ends_with("/Game/Assets"))
        path = path.substr(0, path.size() - std::string("/Game/Assets").size());
    if (path.ends_with(R"(\Game\Assets)"))
        path = path.substr(0, path.size() - std::string(R"(\Game\Assets)").size());

    _icon = std::make_unique<TextureModule>("./" + path + "/Engine/PolymorphEngineIcon.png");
    _label = std::make_unique<TextModule>("Made with Polymorph Engine", 40);
    _authors.push_back(std::make_unique<TextModule>("By:", 20));
    _authors.push_back(std::make_unique<TextModule>("Alexandre JUBLOT", 20));
    _authors.push_back(std::make_unique<TextModule>("Tristan GREMONT", 20));
    _authors.push_back(std::make_unique<TextModule>("Matéo VIEL", 20));
    _authors.push_back(std::make_unique<TextModule>("Vincent MARDIROSSIAN", 20));

    _icon->setPosition(centerTexture(_icon, Vector2(0, -128)));
    _label->setPosition(centerText(_label, Vector2(0, 32), .285f));

    Vector2 pos = Vector2(0, 112);
    for (auto &author : _authors) {
        author->setPosition(centerText(author, pos, .38f));
        pos.y += 32;
    }

    GraphicalAPI::CurrentDisplay->clearWindow();
    GraphicalAPI::CurrentDisplay->beginDrawing();
    _icon->draw();
    _label->draw();
    for (auto &author : _authors) {
        author->draw();
    }
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
    for (auto &author : _authors)
        author->setColor(Color(255, 255, 255, _currentAlpha));
    GraphicalAPI::CurrentDisplay->beginDrawing();
    _icon->draw();
    _label->draw();
    for (auto &author : _authors)
        author->draw();
    GraphicalAPI::CurrentDisplay->endDrawing();
}
