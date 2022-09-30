/*
** EPITECH PROJECT, 2020
** SpriteAnimatorScript
** File description:
** header for SpriteAnimator.c
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include "Core/component/builtins/animation/SpriteAnimatorScript.hpp"

namespace Polymorph
{
    SpriteAnimatorScript::SpriteAnimatorScript(GameObject gameObject)
            : Component("SpriteAnimator", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void SpriteAnimatorScript::start()
    {
        startAnimation(currentAnimation);
    }

    // Called every frame by the engine
    void SpriteAnimatorScript::update()
    {
        if (animations.empty() || !_currentAnimation)
            return;
        if (_timer.timeIsUp(true))
            _currentAnimation->nextFrame();
    }

    void SpriteAnimatorScript::startAnimation(std::string animationName)
    {
        if (!animationName.empty())
            _currentAnimation = std::find_if(animations.begin(), animations.end(), [animationName](const std::shared_ptr<SpriteAnimation> x){
                return x->animationName == animationName;
            }).operator*();
        else _currentAnimation = animations.front();
        currentAnimation = animationName;
        _timer = Timer(_currentAnimation->frameTime);
        targetGraphics->sprite = _currentAnimation->sprite;
    }

    void SpriteAnimatorScript::addAnimCallBack(
            MeshAnimation::AnimationCallBack callback,
            std::string animationName)
    {
        if (!animationName.empty())
            std::find_if(animations.begin(), animations.end(), [animationName](const std::shared_ptr<SpriteAnimation> x){
                return x->animationName == animationName;
            }).operator*()->addEndAnimCallBack(callback);
    }

    void SpriteAnimatorScript::clearAnimationCallbacks(std::string name)
    {
        if (!name.empty())
            std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
                return x->animationName == name;
            }).operator*()->clear();
        else for (auto &a : animations)
            a->clear();
    }

    void SpriteAnimatorScript::setAnimationFrameTime(std::string name,
                                                     float frameTime)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
            return x->animationName == name;
        }).operator*();
        a->frameTime = frameTime;
        if (name == currentAnimation)
            _timer.delay = frameTime;
    }

    float SpriteAnimatorScript::getAnimationFrameTime(std::string name)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const std::shared_ptr<SpriteAnimation> x){
            return x->animationName == name;
        }).operator*();
        return a->frameTime;
    }

}