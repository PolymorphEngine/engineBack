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
                Pop(destroyHolder.second);
            else
                nmap.emplace(destroyHolder);
        }
        _destroyQueueList.clear();
        _destroyQueueList = nmap;
    }

    std::shared_ptr<Entity> &Scene::find(Entity &entity)
    {
        return findId(entity.getId());
    }

    std::shared_ptr<Entity> &Scene::findId(std::string &id)
    {
        std::shared_ptr<Entity> nullReturn = nullptr;
        for (auto & entity : _entities) {
            if (*entity == id)
                return entity;
        }
        return nullReturn;
    }

    Entity &Scene::Pop(Entity &entity)
    {
        return Pop(entity.getId());
    }

    Entity &Scene::Pop(std::string &id)
    {
        auto pos = 0;
        auto nullreturn = Polymorph::Entity();
        for (auto entity = _entities.begin(); entity != _entities.end(); ++entity)
        {
            if ((**entity) == id)
            {
                _entities.erase(entity, entity + countChildren(entity, (*entity)->getId()) + 1);
                return **entity;
            }
            pos++;
        }
        return nullreturn;
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

    Scene::Scene(Config::XmlScene &data, Engine &game): _data(data), _game(game), id(data.getId())
    {
    }

    void Scene::loadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();

        _entities = _data.getEntities();

        for (auto &e : _entities)
            e->Awake();
    }

    void Scene::unloadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();
    }

}
