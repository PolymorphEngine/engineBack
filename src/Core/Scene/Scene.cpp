/*
** EPITECH PROJECT, 2020
** Scene.cpp.cc
** File description:
** header for Scene.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Config.hpp>

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
            if (e->isActive() && !e->transform->parent())
                e->update();
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }
        if (!_entitiesToAdd.empty()) {
            _entities.insert(_entities.end(), _entitiesToAdd.begin(), _entitiesToAdd.end());
            _entitiesToAdd.clear();
        }
        updateDestroyQueueList();
    }

    void Scene::updateDestroyQueueList()
    {
        std::map<std::shared_ptr<Timer>, Entity &> nmap;

        for (auto &destroyHolder : _destroyQueueList) {
            // Delay system : you can add a delay in seconds before destroying a component
            destroyHolder.first->tick();
            if (destroyHolder.first->timeIsUp()) {
                if (!!destroyHolder.second.transform->parent())
                    destroyHolder.second.transform->parent()->removeChild(destroyHolder.second.transform);
                _eraseChildren(destroyHolder.second);
                _erase(destroyHolder.second);
            }
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

    void Scene::addEntity(const std::shared_ptr<Entity>& entity)
    {
        _entities.push_back(entity);
    }

    void Scene::_erase(Entity &entity)
    {
        return _erase(entity.getId());
    }

    void Scene::_erase(std::string &id)
    {
        auto pos = 0;
        for (auto entity = _entities.begin(); entity != _entities.end(); ++entity) {
            if ((**entity) == id) {
                _entities.erase(entity);
                return;
            }
            pos++;
        }
    }


    GameObject Scene::find(const std::string &needle)
    {
        for (auto &e : _entities) {
            if (e->name == needle)
                return GameObject(e);
        }
        return GameObject(nullptr);
    }

    std::vector<GameObject> Scene::findAll(const std::string &needle)
    {
        std::vector<GameObject> toRet;

        for (auto &e : _entities) {
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
        auto e = std::find_if(_destroyQueueList.begin(),
        _destroyQueueList.end(), [&entity](std::pair<std::shared_ptr<Timer>, Entity&> p) {
            return p.second == entity;
        });
        if (e == _destroyQueueList.end())
        {
            entity.setActive(false);
            std::shared_ptr<Timer> timer (new Timer(delayInSeconds));
            _destroyQueueList.emplace(timer, entity);
        }
    }

    void Scene::loadScene()
    {
        _destroyQueueList.clear();
        _entities.clear();

        _entities = _config_data->getEntities();

        for (auto &e : _entities)
            e->awake();
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
        for (auto &e : _entities) {
            if (e->getId() == id)
                return GameObject(e);
        }
        for (auto &e: _game.getPrefabs()) {
            if (e->getId() == id || e->getPrefabId() == id)
                return GameObject(e);
        }
        return GameObject(PluginManager::getPrefab(id));
    }

    EntityIterator Scene::findItById(const std::string &id)
    {
        for (auto it = _entities.begin(); it != _entities.end(); ++it) {
            if ((*it)->getId() == id)
                return it;
        }
        return _entities.end();
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

    std::shared_ptr<Entity> Scene::pop(EntityIterator it)
    {
        auto entity = *it;

        _entities.erase(it);
        return entity;
    }

    std::size_t Scene::countParents()
    {
        std::size_t toRet = 0;

        for (auto &e : _entities) {
            if (!(e->transform->parent()))
                ++toRet;
        }
        return toRet;
    }

    void Scene::addEntityAtIdx(const std::shared_ptr<Entity> &entity,
                               std::size_t idx)
    {
        _entities.insert(_entities.begin() + (int)idx, entity);
    }

    void Scene::addEntityToAddQueue(const std::shared_ptr<Entity> &entity)
    {
        _entitiesToAdd.push_back(entity);
    }

    void Scene::_eraseChildren(Entity &entity)
    {
        for (auto &child: **entity.transform) {
            _eraseChildren(**child->gameObject);
            _erase(**child->gameObject);
        }
    }

}
