/*
** EPITECH PROJECT, 2020
** Component.cpp.cc
** File description:
** header for Component.c
*/


#include "Component.hpp"

void Polymorph::Component::setActive(bool active)
{
    gameObject.setActive(active);
}

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

