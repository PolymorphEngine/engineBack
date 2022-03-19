/*
** EPITECH PROJECT, 2020
** Component.cpp.cc
** File description:
** header for Component.c
*/


#include "Component.hpp"
#include "Entity.hpp"

Polymorph::Component::Component(Polymorph::Entity &game_object)
: _type("Component"), gameObject(game_object), transform(*game_object.transform), name(game_object.name)
{}

Polymorph::Component::Component(const std::string &type, Entity &game_object)
        : _type(type), gameObject(game_object), transform(*game_object.transform), name(game_object.name)
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