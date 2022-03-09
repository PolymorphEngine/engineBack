/*
** EPITECH PROJECT, 2020
** Polymorph.cpp.cc
** File description:
** header for Polymorph.c
*/

#include "SceneManager.hpp"
#include "Application.hpp"
#include "Engine.hpp"
#include "Scene.hpp"

int Polymorph::Engine::run()
{
    SceneManager::Current->loadScene();

    while (_exit)
        SceneManager::Current->updateComponents();
    return _exitCode;
}

void Polymorph::Engine::Exit(ExitCode code = 0)
{
    _exitCode = code;
    _exit = true;
}

Polymorph::Engine::Engine(const std::string &filepath)
{
    std::shared_ptr<Engine>game = std::shared_ptr<Engine>(this);
    //TODO: create Xml Interfaces

    //TODO: set current scene
    SceneManager::Current = *_scenes.begin();
    SceneManager::Game = game;
    Application::Game = game;
}
