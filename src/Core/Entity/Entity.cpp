/*
** EPITECH PROJECT, 2020
** Entity.cpp.cc
** File description:
** header for Entity.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Config.hpp>
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Core/Component/transform/TransformInitializer.hpp"


Polymorph::Entity::Entity(Config::XmlEntity &data,
Engine &game) : _game(game), _xml_config(data), _stringId(data.getId()),
_prefabId(data.getPrefabId()), _wasPrefab(data.wasPrefab())
{
    name = data.getName();
    _active = data.isActive();
    _tags = data.getTags();
    _order = _game.getExecOrder();
    _isPrefab = data.isPrefab();
    for (auto &type: _order)
        _components[type];
}



void Polymorph::Entity::addComponent(std::string &component,
Polymorph::Config::XmlComponent &config, GameObject _this)
{
    if (componentExist(component))
        return;
    //TODO : throw ?
    std::shared_ptr<IComponentInitializer> i;
    if (component == "Transform")
        i = std::make_shared<TransformInitializer>(config, _this);
    if (i == nullptr)
        i = ScriptingApi::create(component, config, _this);
    if (i == nullptr)
        i = _game.getPluginManager()->tryCreateComponent(component, config, _this);
    if (i == nullptr) {
        Logger::log(
        "Unknown component to load at initialisation: '" + component +
        "'", Logger::MINOR);
        return;
    }

    _components[i->getType()].push_back(i);
    if (component == "Transform")
        (**i)->transform = getComponent<TransformComponent>();
    i->build();
}


void Polymorph::Entity::update()
{
    if (!_active)
        return;

    for (auto &cl :_components)
        for (auto &c : cl.second) {
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
            if (!c->isAwaked()) {
                try {
                    c->onAwake();
                } catch (ExceptionLogger &e) {
                    e.what();
                } catch (std::exception &e) {
                    if (std::string(e.what()) == "Object reference not set to an instance")
                        Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                                    " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
                    else
                        Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
                }
                c->setAsAwaked();
            }
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
            if (!c->isEnabled())
                continue;
            if (!c->isStarted()) {
                try {
                    c->start();
                } catch (ExceptionLogger &e) {
                    e.what();
                } catch (std::exception &e) {
                    if (std::string(e.what()) == "Object reference not set to an instance")
                        Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                                    " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
                    else
                        Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
                }
                c->setAsStarted();
            }
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
            if (c->isEnabled())
                try {
                    c->update();
                } catch (ExceptionLogger &e) {
                    e.what();
                } catch (std::exception &e) {
                    if (std::string(e.what()) == "Object reference not set to an instance")
                        Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                                    " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
                    else
                        Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
                }
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }
    for (auto &c : **transform)
    {
        if (Engine::isExiting() || SceneManager::isSceneUnloaded())
            return;
        try {
            c->gameObject->update();
        } catch (ExceptionLogger &e) {
            e.what();
        } catch (std::exception &e) {
            if (std::string(e.what()) == "Object reference not set to an instance")
                Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                            " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
            else
                Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
        }
        if (Engine::isExiting() || SceneManager::isSceneUnloaded())
            return;
    }
}



void Polymorph::Entity::setActive(bool active)
{
    if (this->_active != active) {
        //TODO : change children state
    }
    this->_active = active;

}

bool Polymorph::Entity::hasTag(const std::string &tag) const
{
    for (auto const &_tag : _tags)
        if (_tag == tag)
            return true;
    return false;
}

void Polymorph::Entity::addTag(const std::string &tag)
{
    if (hasTag(tag))
        return;
    _tags.push_back(tag);
}

void Polymorph::Entity::deleteTag(const std::string &tag)
{
    for (auto _tag = _tags.begin(); _tag  != _tags.end(); ++ _tag ) {
        if (tag == *_tag) {
            _tags.erase(_tag);
            return;
        }
    }
}

template<typename T>
bool Polymorph::Entity::deleteComponent()
{
    std::shared_ptr<T> component (new T(*this));

    std::string t = component->getType();
    component.reset();
    if (!componentExist(t))
        return false;
    if (!_components.contains(t)) {
        auto i = 0;
        auto & defaultList =_components.find("Default")->second;
        for (auto &c : defaultList) {
            if (c->getType() == t) {
                defaultList.erase(defaultList.begin() + i);
                return false;
            }
            ++i;
        }
    } else {
        _components[t].clear();
        return true;
    }
    return false;
}

Polymorph::Entity::~Entity()
{
}

bool Polymorph::Entity::componentExist(std::string &type)
{
    std::string def("Default");
    if (!_components.contains(type)) {
        for (auto &c :  _components.find(def)->second) {
            if (c->getType() == type)
                return true;
        }
    }
    else if (!_components.find(type)->second.empty())
        return true;
    return false;
}

void Polymorph::Entity::awake(bool recurse)
{
    if (!_asBeenInit) {
        initTransform();
        for (auto &cl: _components)
            for (auto &c: cl.second)
                if (c->getType() != "Transform")
                    c->reference();
        _asBeenInit = true;
    }
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            try {
                if (!c->isAwaked())
                    c->onAwake();
            } catch (ExceptionLogger &e) {
                e.what();
            } catch (std::exception &e) {
                if (std::string(e.what()) == "Object reference not set to an instance")
                    Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                                " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
                else
                    Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
            }
            c->setAsAwaked();
        }
    if (recurse)
    {
        for (auto &child: **transform)
            child->gameObject->awake(true);
    }
    _asBeenInit = true;
}

Polymorph::Config::XmlEntity &Polymorph::Entity::getXmlConfig() const noexcept {
    return _xml_config;
}

void Polymorph::Entity::start()
{
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            try {
                if (!c->isStarted())
                    c->start();
            } catch (ExceptionLogger &e) {
                e.what();
            } catch (std::exception &e) {
                if (std::string(e.what()) == "Object reference not set to an instance")
                    Logger::log("[Polymorph Engine] Object reference not set to an instance:"
                                " this maybe occurs because you need to set a reference in configuration or in interface.", Logger::MAJOR);
                else
                    Logger::log("[Unknown Exception] : " + std::string(e.what()), Logger::MAJOR);
            }
            c->setAsStarted();
        }
}

bool Polymorph::Entity::isActive() const
{
    return _active;
}

bool Polymorph::Entity::isPrefab() const
{
    return _isPrefab;
}

Polymorph::safe_ptr<Polymorph::Entity>
Polymorph::Entity::find(const std::string &nameToFind)
{
    for (auto &child : **transform) {
        if (child->gameObject->name == nameToFind)
            return child->gameObject;
    }
    for (auto &child : **transform) {
        auto found = child->gameObject->find(nameToFind);
        if (!!found)
            return found;
    }
    return GameObject(nullptr);
}

Polymorph::safe_ptr<Polymorph::Entity>
Polymorph::Entity::childAt(std::size_t idx)
{
    if (idx > transform->nbChildren())
        return GameObject(nullptr);
    for (auto &child : **transform) {
        if (idx == 0)
            return child->gameObject;
        --idx;
    }
    return GameObject(nullptr);
}

bool Polymorph::Entity::wasPrefab() const
{
    return _wasPrefab;
}

Polymorph::safe_ptr<Polymorph::Entity>
Polymorph::Entity::findByPrefabId(const std::string &nameToFind, bool _firstCall)
{
    for (auto &child : **transform) {
        if (child->gameObject->_prefabId == nameToFind)
            return child->gameObject;
    }
    for (auto &child : **transform) {
        auto found = child->gameObject->findByPrefabId(nameToFind, false);
        if (!!found)
            return found;
    }
    auto parent = transform->parent();
    if (!!parent && (parent->gameObject->getId() == nameToFind
    || parent->gameObject->getPrefabId() == nameToFind))
        return parent->gameObject;
    if (_firstCall && !!transform->parent())
        return transform->parent()->gameObject->findByPrefabId(nameToFind);
    return GameObject(nullptr);
}

void Polymorph::Entity::setIsPrefab(bool value)
{
    _isPrefab = value;
}

void Polymorph::Entity::setWasPrefab(bool value)
{
    _wasPrefab = value;
}

void Polymorph::Entity::initTransform()
{
    if (_transformInitialized)
        return;
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            if (c->getType() == "Transform")
            {
                c->reference();
                break;
            }
        }
    _transformInitialized = true;
}

std::vector<std::string>
Polymorph::Entity::getTagsStartingWith(const std::string &begin) const
{
    std::vector<std::string> tags;

    for (auto &tag : _tags) {
        if (tag.starts_with(begin))
            tags.push_back(tag);
    }
    return tags;
}
