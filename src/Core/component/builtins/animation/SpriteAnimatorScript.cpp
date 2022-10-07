/*
** EPITECH PROJECT, 2020
** SpriteAnimatorComponent
** File description:
** header for SpriteAnimator.c
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include "Core/component/builtins/animation/SpriteAnimatorScript.hpp"

namespace Polymorph
{
    SpriteAnimatorComponent::SpriteAnimatorComponent(GameObject gameObject)
            : Component("SpriteAnimator", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void SpriteAnimatorComponent::start()
    {
        startAnimation(currentAnimation);
    }

    // Called every frame by the engine
    void SpriteAnimatorComponent::update()
    {
        if (animations.empty() || !_currentAnimation)
            return;
        if (_timer.timeIsUp(true))
            _currentAnimation->nextFrame();
    }

    void SpriteAnimatorComponent::startAnimation(std::string animationName)
    {
        if (animations.empty())
            return;
        //TODO(ERR): possible failure
        if (!animationName.empty() && animations.size() > 1)
            _currentAnimation = std::find_if(animations.begin(), animations.end(), [&animationName](std::shared_ptr<SpriteAnimation> x){
                return x->animationName == animationName;
            }).operator*();
        else _currentAnimation = animations.front();
        currentAnimation = animationName;
        _timer = Timer(_currentAnimation->frameTime);
        targetGraphics->sprite = _currentAnimation->sprite;
    }

    void SpriteAnimatorComponent::addAnimCallBack(
            MeshAnimation::AnimationCallBack callback,
            std::string animationName)
    {
        if (!animationName.empty())
            std::find_if(animations.begin(), animations.end(), [animationName](const std::shared_ptr<SpriteAnimation> x){
                return x->animationName == animationName;
            }).operator*()->addEndAnimCallBack(callback);
    }

    void SpriteAnimatorComponent::clearAnimationCallbacks(std::string name)
    {
        if (!name.empty())
            std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
                return x->animationName == name;
            }).operator*()->clear();
        else for (auto &a : animations)
            a->clear();
    }

    void SpriteAnimatorComponent::setAnimationFrameTime(std::string name,
                                                     float frameTime)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
            return x->animationName == name;
        }).operator*();
        a->frameTime = frameTime;
        if (name == currentAnimation)
            _timer.delay = frameTime;
    }

    float SpriteAnimatorComponent::getAnimationFrameTime(std::string name)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
            return x->animationName == name;
        }).operator*();
        return a->frameTime;
    }

}