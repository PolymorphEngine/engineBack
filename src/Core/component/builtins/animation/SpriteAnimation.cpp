/*
** EPITECH PROJECT, 2022
** SpriteAnimation.cpp
** File description:
** SpriteAnimation.cpp
*/


#include "Core/component/builtins/animation/SpriteAnimation.hpp"

Polymorph::SpriteAnimation::SpriteAnimation(
        std::shared_ptr<myxmlpp::Node> &data,
        Polymorph::Config::XmlComponent &manager)
{
    manager.setSubProperty("sprite", data, sprite);
    manager.setSubProperty("nbFrames", data, nbFrames);
    manager.setSubProperty("frameTime", data, frameTime);
    manager.setSubProperty("yOffset", data, yOffset);
    
    _width = sprite->getTextureWidth() / static_cast<float>(nbFrames);
    _height = sprite->getTextureHeight();
    _currentFrame = {0, yOffset, _width , _height};
    sprite->setCrop(_currentFrame);
}

Polymorph::SpriteAnimation::~SpriteAnimation()
{
    sprite.reset();
}

void Polymorph::SpriteAnimation::addEndAnimCallBack(
        Polymorph::SpriteAnimation::AnimationCallBack callback)
{
    _callBacks.push_back(callback);
}

void Polymorph::SpriteAnimation::invokeCallBacks()
{
    for (auto &c : _callBacks)
        c();
}

void Polymorph::SpriteAnimation::nextFrame()
{
    if (currentFrame < nbFrames)
    {
        _currentFrame.x += _width;
        sprite->setCrop(_currentFrame);
    }
    else
    {
        _currentFrame.x = 0;
        sprite->setCrop(_currentFrame);
        invokeCallBacks();
    }
}

void Polymorph::SpriteAnimation::clear()
{
    _callBacks.clear();
}

void Polymorph::SpriteAnimation::setAnimationFrameTime(float frameTime)
{
    this->frameTime = frameTime;
}
