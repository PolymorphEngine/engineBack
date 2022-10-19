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
    manager.setSubProperty("reversed", data, reversed);
    manager.setSubProperty("animationName", data, animationName);
    manager.setSubProperty("frameTime", data, frameTime);
    manager.setSubProperty("yOffset", data, yOffset);

    _width = sprite->getTextureWidth() / static_cast<float>(nbFrames);
    _height = sprite->getTextureHeight();
    if (reversed)
        _currentFrame = {_width * (nbFrames - 1), yOffset, _width , _height};
    else
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
    if (reversed) {
        if (currentFrame > 0) {
            _currentFrame.x -= _width;
            sprite->setCrop(_currentFrame);
            currentFrame--;
        } else {
            _currentFrame.x = _width * (nbFrames - 1);
            sprite->setCrop(_currentFrame);
            invokeCallBacks();
            currentFrame = nbFrames - 1;
        }
    } else {
        if (currentFrame < nbFrames) {
            _currentFrame.x += _width;
            sprite->setCrop(_currentFrame);
            currentFrame++;
        } else {
            _currentFrame.x = 0;
            sprite->setCrop(_currentFrame);
            invokeCallBacks();
            currentFrame = 0;
        }
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
