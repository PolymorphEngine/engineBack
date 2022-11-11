/*
** EPITECH PROJECT, 2022
** MeshFrame.cpp
** File description:
** MeshFrame.cpp
*/
#include "animation/MeshFrame.hpp"

Polymorph::MeshFrame::MeshFrame(std::shared_ptr<myxmlpp::Node> &data,
                                Config::XmlComponent &manager)
{
    manager.setSubProperty("frameTime", data, frameTime);
    manager.setSubProperty("texture", data, texture);
    manager.setSubProperty("model", data, model);
}

