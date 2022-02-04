/*
** EPITECH PROJECT, 2020
** Polymorph.cpp.cc
** File description:
** header for Polymorph.c
*/

#include "Engine.hpp"
#include "Scene.hpp"
#include "IPolymorphDisplay.hpp"
#include "IPolymorphEvent.hpp"

void Polymorph::Engine::run()
{
    while (_display.isRunning())
    {
        //TODO: design gameloop
        _event.storeEvents();

        _actual.updateComponents();

        _display.clearDisplay();
        _display.draw();
    }
}
