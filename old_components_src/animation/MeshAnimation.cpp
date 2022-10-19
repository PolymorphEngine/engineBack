/*
** EPITECH PROJECT, 2022
** MeshAnimation.cpp
** File description:
** MeshAnimation.cpp
*/

#include "Core/component/builtins/animation/MeshAnimation.hpp"
#include "Core/component/builtins/animation/MeshFrame.hpp"

Polymorph::MeshAnimation::MeshAnimation(std::shared_ptr<myxmlpp::Node> &data,
                                        Config::XmlComponent &manager)
{
    manager.setSubProperty("frames", data, frames);
    manager.setSubProperty("animationName", data, animationName);
}

void Polymorph::MeshAnimation::addEndAnimCallBack(
        Polymorph::MeshAnimation::AnimationCallBack callback)
{
    _callBacks.emplace_back(callback);
}

void Polymorph::MeshAnimation::invokeCallBacks()
{
    for (auto &c : _callBacks)
        c();
}
