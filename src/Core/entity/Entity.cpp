/*
** EPITECH PROJECT, 2020
** Entity.cpp.cc
** File description:
** header for Entity.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>
#include "ScriptingAPI/ScriptingApi.hpp"
#include "Entity.hpp"


Polymorph::Entity::Entity(Config::XmlEntity &data,
Engine &game) : _game(game), _xml_config(data), _stringId(data.getId())
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
    ComponentFactory::Initializer i = ComponentFactory::create(component, config, _this);

    if (i == nullptr)
        i = ScriptingApi::create(component, config, _this);

    if (i == nullptr) {
        Logger::log(
                "Unknown component to load at initialisation: '" + component +
                "'", Logger::DEBUG);
        return;
    }
    i->build();
    _components[i->getType()].push_back(i);
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
                c->onAwake();
                c->setAsAwaked();
            }
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
            if (!c->isEnabled())
                continue;
            if (!c->isStarted()) {
                c->start();
                c->setAsStarted();
            }
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
            if (c->isEnabled())
                c->update();
            if (Engine::isExiting() || SceneManager::isSceneUnloaded())
                return;
        }
    for (auto &c : **transform)
    {
        if (Engine::isExiting() || SceneManager::isSceneUnloaded())
            return;
        c->gameObject->update();
    }
}

void Polymorph::Entity::draw()
{
    if (!_active)
        return;
    Drawable c = getComponent<ADrawableComponent>();

    if (!!c && c->enabled)
        c->draw();
    for (auto &c : **transform)
        c->gameObject->draw();
}

void Polymorph::Entity::drawChildren(Polymorph::TransformComponent &trm)
{

    for (auto &child : trm) {
        //TODO: check independence before drawing ?
        Drawable drawable = child->gameObject->getComponent<ADrawableComponent>();
        if (!!drawable && drawable->enabled)
            drawable->draw();
        drawChildren(**child);
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
    if (!hasTag(tag))
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

void Polymorph::Entity::awake()
{
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            c->reference();
        }
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            c->onAwake();
            c->setAsAwaked();
        }
}

Polymorph::Config::XmlEntity &Polymorph::Entity::getXmlConfig() const noexcept {
    return _xml_config;
}

void Polymorph::Entity::start()
{
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            c->start();
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
}
