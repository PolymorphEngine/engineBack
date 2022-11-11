/*
** EPITECH PROJECT, 2022
** MeshAnimationModule.cpp
** File description:
** MeshAnimationModule.cpp
*/

#include "GraphicalAPI/modules/MeshAnimationModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::MeshAnimationModule::MeshAnimationModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_filePath", data, _filePath);
    manager.setSubProperty("name", data, name);
    manager.setSubProperty("frameTimes", data, frameTimes);
    _filePath = "./Game/Assets/" + _filePath;
    _meshAnimation = std::unique_ptr<Polymorph::IModelAnimationModule>(_c_MeshAnimation(_filePath));
}

void Polymorph::MeshAnimationModule::begin()
{
    _currentFrameTime = frameTimes.begin();
    if (_currentFrameTime == frameTimes.end())
        throw ExceptionLogger("No frame time set in configuration");
    _timer = Timer(*_currentFrameTime);
    _currentFrameCounter = 0;
}

void Polymorph::MeshAnimationModule::update(const std::shared_ptr<Polymorph::MeshModule> &mesh)
{
    if (_currentFrameTime == frameTimes.end())
        throw ExceptionLogger("No frame time set in configuration");
    _timer.tick();
    if (_timer.timeIsUp()) {
        _currentFrameTime++;
        _currentFrameCounter++;
        if (_currentFrameCounter == _meshAnimation->getNbFrames()) {
            _currentFrameCounter = 0;
            _currentFrameTime = frameTimes.begin();
            _invokeCallBacks();
        }
        _meshAnimation->tick();
        _meshAnimation->update(mesh->getMesh());
        if (_currentFrameTime == frameTimes.end()) {
            Logger::log("Not enough frame times set in the configuration", Logger::MINOR);
            _currentFrameTime = frameTimes.begin();
        }
        _timer = Timer(*_currentFrameTime);
    }
}

void Polymorph::MeshAnimationModule::addAnimCallBack(
        const Polymorph::MeshAnimation::AnimationCallBack& callback)
{
    _callbacks.emplace_back(callback);
}

void Polymorph::MeshAnimationModule::_loadModule()
{
    if (_c_MeshAnimation)
        return;
    _c_MeshAnimation = GraphicalAPI::loadSymbol<MeshAnimationModuleLoader, GraphicalAPI>("createModelAnimationModule");
}

void Polymorph::MeshAnimationModule::_invokeCallBacks()
{
    for (auto &c : _callbacks)
        c();
}