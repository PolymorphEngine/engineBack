/*
** EPITECH PROJECT, 2022
** MeshAnimator.cpp
** File description:
** MeshAnimator.cpp
*/

#include "Core/Component/builtins/animation/MeshAnimatorComponent.hpp"
#include "Core/Component/builtins/animation/MeshFrame.hpp"
#include "Core/Component/builtins/animation/MeshAnimatorComponent.hpp"


Polymorph::MeshAnimatorComponent::MeshAnimatorComponent(GameObject gameObject):
Component("MeshAnimator", gameObject)
{
}

void Polymorph::MeshAnimatorComponent::start()
{
    _currentAnimation = *std::find_if(_animations.begin(), _animations.end(),
         [this](std::shared_ptr<MeshAnimation> &animation) {
             return (animation->animationName == currentAnimationName);
         });
    _currentFrame = _currentAnimation->frames.begin();
    _timer = Timer((*_currentFrame)->frameTime);
}

void Polymorph::MeshAnimatorComponent::update()
{
    _timer.tick();
    if (_timer.timeIsUp()) {
        _currentFrame++;
        if (_currentFrame == _currentAnimation->frames.end())
        {
            _currentFrame = _currentAnimation->frames.begin();
            _currentAnimation->invokeCallBacks();
        }
        target->mesh = (*_currentFrame)->model;
        target->texture = (*_currentFrame)->texture;
        _timer = Timer((*_currentFrame)->frameTime);
    }
}

void Polymorph::MeshAnimatorComponent::setAnimation(std::string animationName)
{
    currentAnimationName = animationName;
    _currentAnimation = *std::find_if(_animations.begin(), _animations.end(),
          [this](std::shared_ptr<MeshAnimation> &animation) {
              return (animation->animationName == currentAnimationName);
          });
    _currentFrame = _currentAnimation->frames.begin();
    _timer = Timer((*_currentFrame)->frameTime);
}

void Polymorph::MeshAnimatorComponent::addMesh(float time, std::shared_ptr<Polymorph::MeshModule> mesh,
                                               std::string &animationName)
{
    throw ExceptionLogger("MeshAnimator::addMesh : Not Implemented Yet");
}

void Polymorph::MeshAnimatorComponent::addAnimCallBack(
        Polymorph::MeshAnimation::AnimationCallBack callback,
        std::string animationName)
{
    auto animIt = std::find_if(_animations.begin(), _animations.end(),
    [&animationName](std::shared_ptr<MeshAnimation> &animation) {
      return (animation->animationName == animationName);
    });
    if (animIt == _animations.end())
        throw ExceptionLogger("MeshAnimator::addAnimCallBack : Animation not found", Logger::MAJOR);
    auto anim = *animIt;
    if (animationName == "" && !_animations.empty())
        anim = _animations[0];
    if (anim == nullptr)
        return;
    anim->addEndAnimCallBack(callback);
}
