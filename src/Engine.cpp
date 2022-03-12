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
#include "Log/Logger.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"
#include "Exceptions/configuration/MissingAttribute.hpp"

Polymorph::Engine::Engine(const std::string &filepath, const std::string &projectName)
{
    std::shared_ptr<Engine>game = std::shared_ptr<Engine>(this);
    _projectPath = filepath;
    _projectName = projectName;

    Logger::SetLogDir(filepath);
    //TODO: create Xml Interfaces
    _openProject();


    //TODO: set current scene
    if (_scenes.empty())
        throw std::runtime_error("No scenes built");
    SceneManager::Current = *_scenes.begin();
    SceneManager::Game = game;
    Application::Game = game;
}

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



void Polymorph::Engine::_openProject()
{
    try
    {
        _projectConfig = std::make_unique<myxmlpp::Doc>(_projectPath + "/" + _projectName);
        std::shared_ptr<myxmlpp::Node> n = _projectConfig->getRoot();
        std::shared_ptr<myxmlpp::Node> settings = n->findChild("EngineSettings");
        std::shared_ptr<myxmlpp::Node> scenes = n->findChild("Scenes");
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}

void Polymorph::Engine::_initExectutionOrder()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");
    
    try 
    {
        bool foundDefault = false;
        auto execOrder =settings->findChild("ComponentExecutionOrder");
        
        for (auto &type : *execOrder)
        {
            auto t = type->findAttribute("value")->getValue();
            if (t == "Default")
                foundDefault = true;
            _execOrder.push_back(t);
        }
        if (!foundDefault)
            throw MissingAttribute("Default", "ComponentExecLayer", Logger::MAJOR);
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initLayers()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try
    {
        auto execOrder = settings->findChild("Layers");

        for (auto &type : *execOrder)
        {
            auto t = type->findAttribute("value")->getValue();
            _layers.push_back(t);
        }
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MAJOR);
    }
}


void Polymorph::Engine::_initDebugSettings()
{
    auto settings = _projectConfig->getRoot()->findChild("EngineSettings");

    try
    {
        auto debug = settings->findChild("Debug");
        
        if (debug->findAttribute("enabled")->getValueBool())
            Logger::InitLogInstance(Logger::DEBUG_MODE);
    }
    catch (myxmlpp::Exception &e) {
        throw ConfigurationException(e.what(), Logger::MINOR);
    }
}

void Polymorph::Engine::_initGameData()
{
    std::shared_ptr<myxmlpp::Node> scenes = _projectConfig->getRoot()->findChild("Scenes");
    
    if (scenes->empty())
        throw ConfigurationException("No scenes found to build", Logger::MAJOR);
    
    for (auto &scene : *scenes)
        _scenes.push_back(std::make_shared<Polymorph::Scene>(scene, *this));
    
}

std::string Polymorph::Engine::getProjectPath()
{
    return _projectPath;
}
