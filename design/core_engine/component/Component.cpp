/*
** EPITECH PROJECT, 2020
** Component.cpp.cc
** File description:
** header for Component.c
*/


#include "Component.hpp"
#include "Entity.hpp"


template<typename T>
Polymorph::safe_ptr<T> Polymorph::Component::GetComponent()
{
    return gameObject.GetComponent<T>();
}

template<typename T>
Polymorph::safe_ptr<T> Polymorph::Component::AddComponent()
{
    return gameObject.AddComponent<T>();
}

Polymorph::Component::Component(Polymorph::Entity &game_object)
: _type("Component"), gameObject(game_object), transform(*game_object.transform), name(game_object.name)
{}

Polymorph::Component::Component(const std::string &type, Entity &game_object)
        : _type(type), gameObject(game_object), transform(*game_object.transform), name(game_object.name)
{}

template<typename T>
bool Polymorph::Component::DeleteComponent()
{
    return gameObject.DeleteComponent<T>();
}

template<typename T>
bool Polymorph::Component::ComponentExist()
{
    return gameObject.componentExist<T>();
}

void Polymorph::Component::OnAwake()
{

}

void Polymorph::Component::Update()
{

}

void Polymorph::Component::Start()
{

}

void Polymorph::Component::Draw()
{

}
