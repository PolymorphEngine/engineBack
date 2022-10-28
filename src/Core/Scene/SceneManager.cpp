/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** SceneManager.cpp
*/

#include <polymorph/Core.hpp>
#include <polymorph/Config.hpp>
#include "Core/Scene/SceneManager.hpp"


std::vector<polymorph::engine::GameObject> polymorph::engine::SceneManager::getAll()
{
    return _current->getAll();
}

polymorph::engine::GameObject polymorph::engine::SceneManager::find(const std::string& name)
{
    return _current->find(name);
}

std::vector<polymorph::engine::GameObject>
polymorph::engine::SceneManager::findAll(const std::string& name)
{
    return _current->findAll(name);
}

polymorph::engine::GameObject polymorph::engine::SceneManager::findById(const std::string& id)
{
    if (_current == nullptr)
        return GameObject(nullptr);
    return _current->findById(id);
}

polymorph::engine::GameObject polymorph::engine::SceneManager::findByTag(const std::string& tag)
{
    return _current->findByTag(tag);
}

std::vector<polymorph::engine::GameObject>
polymorph::engine::SceneManager::findAllByTag(const std::string& tag)
{
    return _current->findAllByTag(tag);
}

void polymorph::engine::SceneManager::destroy(polymorph::engine::GameObject& gameObject)
{
    _current->destroy(**gameObject);
}

void polymorph::engine::SceneManager::destroy(polymorph::engine::GameObject gameObject,
                                      float delay)
{
    _current->destroy(**gameObject, delay);
}

polymorph::engine::GameObject
polymorph::engine::SceneManager::instantiate(polymorph::engine::GameObject& gameObject, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->awake();
    _current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

polymorph::engine::GameObject
polymorph::engine::SceneManager::instantiate(polymorph::engine::GameObject gameObject,
                                     const polymorph::engine::Vector3& position, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->awake();
    //TODO maybe call transform method
    nEntity->transform->setPosition(position);
    _current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

polymorph::engine::GameObject
polymorph::engine::SceneManager::instantiate(polymorph::engine::GameObject gameObject,
                                     polymorph::engine::Transform parent, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->transform->setParent(parent);
    nEntity->awake();
    _current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

polymorph::engine::GameObject
polymorph::engine::SceneManager::instantiate(polymorph::engine::GameObject gameObject,
                                     polymorph::engine::Transform parent,
                                     polymorph::engine::Vector3 offset, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->transform->setParent(parent);
    nEntity->awake();
    nEntity->transform->setPosition(parent->getPosition() + offset);
    _current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

void polymorph::engine::SceneManager::loadScene(std::string name)
{
    auto scene = _game.findSceneByName(name);

    if (!scene)
        throw ExceptionLogger("Failed to find scene to load called: " + name, Logger::MAJOR);

    _current->unloadScene();
    _sceneLoading = true;
    _current = scene;
    _current->loadScene();
    for (auto &e: KeepOnLoad)
        _current->addEntity(e);
}



void polymorph::engine::SceneManager::createScene(std::string name)
{
    _game.addScene(std::make_shared<Scene>(name, _game));
}

void
polymorph::engine::SceneManager::dontDestroyOnLoad(polymorph::engine::GameObject gameObject)
{
    KeepOnLoad.emplace_back(gameObject.lock());
}

void polymorph::engine::SceneManager::setAtFront(polymorph::engine::GameObject gameObject)
{
    auto it = _current->findItById(gameObject->getId());
    auto entity = _current->pop(it);

    _current->addEntityAtIdx(entity, 0);
}

void polymorph::engine::SceneManager::setAtIdx(polymorph::engine::GameObject gameObject,
                                       std::size_t idx)
{
    auto it = _current->findItById(gameObject->getId());
    auto entity = _current->pop(it);

    _current->addEntityAtIdx(entity, idx);
}

void polymorph::engine::SceneManager::setAtBack(polymorph::engine::GameObject gameObject)
{
    auto it = _current->findItById(gameObject->getId());
    auto entity = _current->pop(it);
    auto nb = _current->countParents();

    _current->addEntityAtIdx(entity, nb);
}

bool polymorph::engine::SceneManager::isSceneUnloaded() const
{
    return _sceneLoading;
}

void polymorph::engine::SceneManager::resetLoading()
{
    _sceneLoading = false;
}

polymorph::engine::SceneManager::SceneManager(polymorph::engine::Engine &game) : _game(game)
{
    
}

polymorph::engine::SceneManager::SceneManager(polymorph::engine::Engine &game,
std::shared_ptr<Scene> current) : _current(current), _game(game)
{
}

std::shared_ptr<polymorph::engine::Scene> polymorph::engine::SceneManager::getCurrentScene() const
{
    return _current;
}

void polymorph::engine::SceneManager::setCurrentScene(std::shared_ptr<Scene> scene)
{
    _current = scene;
}
