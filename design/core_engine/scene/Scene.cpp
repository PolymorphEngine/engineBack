/*
** EPITECH PROJECT, 2020
** Scene.cpp.cc
** File description:
** header for Scene.c
*/

#include "XmlScene.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

namespace Polymorph
{

    void Scene::updateComponents()
    {
        for (auto &it : _execMap)
        {
            for (auto &component : it.second) {
                if (!(**component)->IsAwaked())
                    (**component)->OnAwake();
                if (!(**component)->enabled)
                    return;
                if (!(**component)->IsStarted())
                    (**component)->Start();
                (**component)->Update();
            }
        updateDestroyQueueList();
        }
    }

    void Scene::loadScene()
    {
        _entities.clear();
        _execMap.clear();
        _destroyQueueList.clear();

        _entities = _data.getEntities();
        _execMap = generateExecMap();
    }

    void Scene::updateDestroyQueueList()
    {
        std::map<std::shared_ptr<Timer>, Entity &> nmap;

        for (auto &destroyHolder : _destroyQueueList)
        {
            // Delay system : you can add a delay in seconds before destroying a component
            destroyHolder.first->tick();
            if (destroyHolder.first->timeIsUp())
            {
                Entity &it = Pop(destroyHolder.second);
                if (it != Entity::Empty)
                {
                    it.Destroy();
                    _destroyQueueList.erase(destroyHolder.first);
                }
            }
            else
                nmap.emplace(destroyHolder);
        }
        _destroyQueueList.clear();
        _destroyQueueList = nmap;
    }

    Entity &Scene::find(const Entity &entity)
    {
        return findId(entity.getId());
    }


    Entity &Scene::findId(const std::string &id)
    {
        for (auto & entity : _entities) {
            if (entity->getId() == id)
                return *entity;
            for (auto &child : *(entity->transform))
            {
                if ((*child).gameObject.getId() == id)
                    return (*child).gameObject;
            }
        }
    }

    Entity &Scene::Pop(const Entity &entity)
    {
        return Pop(entity.getId());
    }

    Entity &Scene::Pop(const std::string &id)
    {
        auto pos = 0;
        for (auto & entity : _entities)
        {
            if (entity->getId() == id)
            {
                _entities.erase(_entities.begin() + pos);
                return *entity;
            }
            pos++;
        }
        return Entity::Empty;
    }

    std::unordered_map<std::string, std::vector<ComponentFactory::Initializer>>
    Scene::generateExecMap()
    {

        auto types = _game.getExexOrder();
        _execMap.clear();

        for (auto & type : types) {
            std::pair<std::string, std::vector<ComponentFactory::Initializer>> p;
            p.first = type;
            _execMap.insert(p);
        }

        for (auto &entity : _entities)
            addToExecMap(entity->getComponents());

    }

    void Scene::addToExecMap(const std::vector<ComponentFactory::Initializer> &components)
    {
        for (auto &component: components)
        {
            std::string type = component->getType();
            if (!_execMap.contains(type))
                type = "Default";
            auto &p = _execMap[type];
            p.emplace_back(component);
        }
    }
}
