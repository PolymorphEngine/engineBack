/*
** EPITECH PROJECT, 2020
** Scene.cpp.cc
** File description:
** header for Scene.c
*/

#include "XmlScene.hpp"
#include "Scene.hpp"

#include <utility>
#include "Engine.hpp"
#include "Entity.hpp"
#include "Time.hpp"
#include "default/TransformComponent.hpp"
#include "uuid.hpp"

namespace Polymorph
{

    Scene::Scene(std::shared_ptr<myxmlpp::Node> &data, Engine &game)
            : _game(game)
    {
        _config_data = std::make_shared<Config::XmlScene>(data, game);

        id = _config_data->getId();
        name = _config_data->getName();
    }

    Scene::Scene(std::string sceneName, Engine &game) : _game(game)
    {
        name = std::move(sceneName);
        id = Polymorph::uuid::uuid();
    }

    void Scene::updateComponents()
    {

        for (auto &e: _entities)
        {
            e->Update();
        }

        //TODO : sort ?
        for (auto &e: _entities)
        {
            e->Draw();
        }
        updateDestroyQueueList();
    }

    void Scene::updateDestroyQueueList()
    {
        std::map<std::shared_ptr<Timer>, Entity &> nmap;

        for (auto &destroyHolder : _destroyQueueList)
        {
            // Delay system : you can add a delay in seconds before destroying a component
            destroyHolder.first->tick();
            if (destroyHolder.first->timeIsUp())
                erase(destroyHolder.second);
            else
                nmap.emplace(destroyHolder);
        }
        _destroyQueueList.clear();
        _destroyQueueList = nmap;
    }

    std::vector<GameObject> Scene::getAll() const noexcept
    {
        std::vector<GameObject> toRet;

        for (auto &e: _entities) {
            toRet.emplace_back(e);
        }
        return toRet;
    }

    void Scene::addEntity(const std::shared_ptr<Entity>& entity) {
        _entities.push_back(entity);
    }

    void Scene::erase(Entity &entity)
    {
        return erase(entity.getId());
    }

    void Scene::erase(std::string &id)
    {
        auto pos = 0;
        for (auto entity = _entities.begin(); entity != _entities.end(); ++entity)
        {
            if ((**entity) == id)
                _entities.erase(entity, entity +
                        _countChildren(entity, (*entity)->getId()) + 1);
            pos++;
        }
    }

    int Scene::_countChildren(
            std::vector<std::shared_ptr<Entity>>::iterator &entity,
            std::string &parent_id)
    {
        auto count = (*entity)->transform->children.size();

        ++entity;
        for (; entity != _entities.end() && (*entity)->getId() != parent_id;)
        {
            if (!(*entity)->transform->children.empty())
                count += _countChildren(entity, (*entity)->getId());
            else
                ++entity;
        }
        return count;
    }

    GameObject Scene::find(const std::string &needle)
    {
        for (auto &e : _entities)
        {
            if (e->name == needle)
                return GameObject(e);
        }
        return GameObject(nullptr);
    }

    std::vector<GameObject> Scene::findAll(const std::string &needle)
    {
        std::vector<GameObject> toRet;

        for (auto &e : _entities)
        {
            if (e->name == needle)
                toRet.emplace_back(e);
        }
        return toRet;
    }

    void Scene::destroy(Entity &entity)
    {
        destroy(entity, 0);
    }

    void Scene::destroy(Entity &entity, float delayInSeconds)
    {
        std::shared_ptr<Timer> timer (new Timer(delayInSeconds));

        _destroyQueueList.emplace(timer, entity);
    }

    void Scene::loadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();

        _entities = _config_data->getEntities();

        for (auto &e : _entities)
            e->Awake();
        for (auto &e: _entities)
            e->start();
    }

    void Scene::unloadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();
    }

    GameObject Scene::findById(const std::string &id)
    {
        for (auto &e : _entities)
        {
            if (e->getId() == id)
                return GameObject(e);
        }
        return GameObject(nullptr);
    }

    GameObject Scene::findByTag(const std::string &tag) {
        for (auto &e: _entities) {
            if (e->hasTag(tag))
                return GameObject(e);
        }
        return GameObject(nullptr);
    }

    std::vector<GameObject> Scene::findAllByTag(const std::string &tag) {
        std::vector<GameObject> toRet;

        for (auto &e : _entities) {
            if (e->hasTag(tag))
                toRet.emplace_back(e);
        }
        return toRet;
    }

}
