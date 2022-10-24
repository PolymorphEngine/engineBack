/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** SceneManager.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Config.hpp>


std::vector<Polymorph::GameObject> Polymorph::SceneManager::getAll()
{
    return Current->getAll();
}

Polymorph::GameObject Polymorph::SceneManager::find(const std::string& name)
{
    return Current->find(name);
}

std::vector<Polymorph::GameObject>
Polymorph::SceneManager::findAll(const std::string& name)
{
    return Current->findAll(name);
}

Polymorph::GameObject Polymorph::SceneManager::findById(const std::string& id)
{
    if (Current == nullptr)
        return GameObject(nullptr);
    return Current->findById(id);
}

Polymorph::GameObject Polymorph::SceneManager::findByTag(const std::string& tag)
{
    return Current->findByTag(tag);
}

std::vector<Polymorph::GameObject>
Polymorph::SceneManager::findAllByTag(const std::string& tag)
{
    return Current->findAllByTag(tag);
}

void Polymorph::SceneManager::destroy(Polymorph::GameObject& gameObject)
{
    Current->destroy(**gameObject);
}

void Polymorph::SceneManager::destroy(Polymorph::GameObject gameObject,
                                      float delay)
{
    Current->destroy(**gameObject, delay);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject& gameObject, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->awake();
    Current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     const Polymorph::Vector3& position, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->awake();
    //TODO maybe call transform method
    nEntity->transform->setPosition(position);
    Current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     Polymorph::Transform parent, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->transform->setParent(parent);
    nEntity->awake();
    Current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     Polymorph::Transform parent,
                                     Polymorph::Vector3 offset, bool isParent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance(gameObject->isPrefab() || gameObject->wasPrefab());
    auto nId = uuid::uuid();

    nEntity->setId(nId);
    nEntity->transform->setParent(parent);
    nEntity->awake();
    nEntity->transform->setPosition(parent->getPosition() + offset);
    Current->addEntityToAddQueue(nEntity);
    return GameObject(nEntity);
}

void Polymorph::SceneManager::loadScene(std::string name)
{
    auto scene = Game->findSceneByName(name);

    if (!scene)
        throw ExceptionLogger("Failed to find scene to load called: " + name, Logger::MAJOR);

    Current->unloadScene();
    _sceneLoading = true;
    Current = scene;
    Current->loadScene();
    for (auto &e: KeepOnLoad)
        Current->addEntity(e);
}



void Polymorph::SceneManager::createScene(std::string name)
{
    Game->addScene(std::make_shared<Scene>(name, *Game));
}

void
Polymorph::SceneManager::dontDestroyOnLoad(Polymorph::GameObject gameObject)
{
    KeepOnLoad.emplace_back(gameObject.lock());
}

void Polymorph::SceneManager::setAtFront(Polymorph::GameObject gameObject)
{
    auto it = Current->findItById(gameObject->getId());
    auto entity = Current->pop(it);

    Current->addEntityAtIdx(entity, 0);
}

void Polymorph::SceneManager::setAtIdx(Polymorph::GameObject gameObject,
                                       std::size_t idx)
{
    auto it = Current->findItById(gameObject->getId());
    auto entity = Current->pop(it);

    Current->addEntityAtIdx(entity, idx);
}

void Polymorph::SceneManager::setAtBack(Polymorph::GameObject gameObject)
{
    auto it = Current->findItById(gameObject->getId());
    auto entity = Current->pop(it);
    auto nb = Current->countParents();

    Current->addEntityAtIdx(entity, nb);
}

bool Polymorph::SceneManager::isSceneUnloaded()
{
    return _sceneLoading;
}

void Polymorph::SceneManager::resetLoading()
{
    _sceneLoading = false;
}