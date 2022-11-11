/*
** EPITECH PROJECT, 2020
** Component.cpp.cc
** File description:
** header for Component.c
*/


#include <polymorph/Core.hpp>

polymorph::engine::Component::Component(const std::string &type, GameObject game_object)
: _type(type), gameObject(game_object), transform(game_object->transform), name(game_object->name),
Game(game_object->Game), Debug(game_object->Debug), Scene(game_object->Scene), Asset(game_object->Asset), Plugin(game_object->Plugin),
time(game_object->time)
{}

void polymorph::engine::Component::onAwake()
{

}

void polymorph::engine::Component::update()
{

}

void polymorph::engine::Component::start()
{

}