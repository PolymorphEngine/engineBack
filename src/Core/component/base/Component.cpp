/*
** EPITECH PROJECT, 2020
** Component.cpp.cc
** File description:
** header for Component.c
*/


#include <Polymorph/Core.hpp>

Polymorph::Component::Component(const std::string &type, GameObject game_object)
        : _type(type), gameObject(game_object), transform(game_object->transform), name(game_object->name)
{}

void Polymorph::Component::onAwake()
{

}

void Polymorph::Component::update()
{

}

void Polymorph::Component::start()
{

}