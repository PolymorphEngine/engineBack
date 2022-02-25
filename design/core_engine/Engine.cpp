/*
** EPITECH PROJECT, 2020
** Polymorph.cpp.cc
** File description:
** header for Polymorph.c
*/

#include "Engine.hpp"
#include "Scene.hpp"
#include "IPolymorphDisplay.hpp"

void Polymorph::Engine::run()
{
    while (_display.isRunning())
    {
        _display.clearDisplay();
        _actual.updateComponents();
        _display.draw();
    }
}
