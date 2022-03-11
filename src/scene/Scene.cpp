/*
** EPITECH PROJECT, 2020
** Scene.cpp.cc
** File description:
** header for Scene.c
*/

#include "XmlScene.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "Entity.hpp"
#include "Time.hpp"
#include "default/TransformComponent.hpp"

namespace Polymorph
{
   
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
                Erase(destroyHolder.second);
            else
                nmap.emplace(destroyHolder);
        }
        _destroyQueueList.clear();
        _destroyQueueList = nmap;
    }

    void Scene::Erase(Entity &entity)
    {
        return Erase(entity.getId());
    }

    void Scene::Erase(std::string &id)
    {
        auto pos = 0;
        auto nullreturn = Polymorph::Entity();
        for (auto entity = _entities.begin(); entity != _entities.end(); ++entity)
        {
            if ((**entity) == id)
                _entities.erase(entity, entity + countChildren(entity, (*entity)->getId()) + 1);
            pos++;
        }
    }

    int Scene::countChildren(std::vector<std::shared_ptr<Entity>>::iterator &entity, std::string &parent_id)
    {
        auto count = (*entity)->transform->children.size();
        
        ++entity;
        for (; entity != _entities.end() && (*entity)->getId() != parent_id;)
        {
            if (!(*entity)->transform->children.empty())
                count += countChildren(entity, (*entity)->getId());
            else
                ++entity;
        }
        return count;
    }

    GameObject Scene::find(const std::string &name)
    {
        for (auto &e : _entities)
        {
            if (e->name == name)
                return GameObject(e);
        }
        return GameObject(nullptr);
    }

    void Scene::Destroy(Entity &entity)
    {
        Destroy(entity, 0);
    }

    void Scene::Destroy(Entity &entity, float delayInSeconds)
    {
        std::shared_ptr<Timer> timer (new Timer(delayInSeconds));
        
        _destroyQueueList.emplace(timer, entity);
        
    }

    Scene::Scene(std::shared_ptr<Config::XmlScene> &data, std::shared_ptr<Engine> &game): _config_data(data), _game(game), _id(data->getId())
    {
    }

    void Scene::loadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();

        _entities = _config_data->getEntities();

        for (auto &e : _entities)
            e->Awake();
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

}
