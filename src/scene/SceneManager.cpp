/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** SceneManager.cpp
*/

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

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
Polymorph::SceneManager::instantiate(Polymorph::GameObject& gameObject)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance();
    
    nEntity->Awake();
    Current->addEntity(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     const Polymorph::Vector3& position)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance();

    nEntity->Awake();
    //TODO maybe call transform method
    nEntity->transform->position = position;
    Current->addEntity(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     Polymorph::Transform parent)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance();

    nEntity->Awake();
    nEntity->transform->SetParent(*parent);
    Current->addEntity(nEntity);
    return GameObject(nEntity);
}

Polymorph::GameObject
Polymorph::SceneManager::instantiate(Polymorph::GameObject gameObject,
                                     Polymorph::Transform parent,
                                     Polymorph::Vector3 offset)
{
    auto xml = gameObject->getXmlConfig();
    auto nEntity = xml.makeInstance();

    nEntity->Awake();
    nEntity->transform->SetParent(*parent);
    nEntity->transform->position = parent->position + offset;
    Current->addEntity(nEntity);
    return GameObject(nEntity);
}

void Polymorph::SceneManager::loadScene(std::string name)
{
    auto scene = Game->findSceneByName(name);

    Current->unloadScene();
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
    KeepOnLoad.push_back(gameObject.lock());
}






