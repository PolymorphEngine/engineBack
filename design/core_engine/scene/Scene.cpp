/*
** EPITECH PROJECT, 2020
** Scene.cpp.cc
** File description:
** header for Scene.c
*/

#include "Scene.hpp"

void Polymorph::Scene::updateComponents()
{
    // TODO: determine if an order is needed to update Components
    for (auto &c: _components)
    {
        if (c->gameObject->isActive() && c->enabled)
            c->update();
    }
}

void Polymorph::Scene::initScene()
{
    // TODO: determine if an order is needed to start Components
    for (auto &c: _components)
    {
        if (c->gameObject->isActive() && c->enabled)
            c->start();
    }
}

void Polymorph::Scene::loadScene()
{

}
