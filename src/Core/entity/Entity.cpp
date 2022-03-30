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

Polymorph::Entity::Entity(Config::XmlEntity &data,
Engine &game) : _game(game), _xml_config(data), _stringId(data.getId())
{
    name = data.getName();
    _active = data.isActive();
    _tags = data.getTags();
    _order = _game.getExecOrder();
    for (auto &type: _order)
        _components[type];
    _isPrefab = false;
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
            if (!(**c)->isAwaked()) {
                (**c)->onAwake();
                (**c)->setAsAwaked();
            }
            if (!(**c)->enabled)
                continue;
            if (!(**c)->isStarted()) {
                (**c)->start();
                (**c)->setAsStarted();
            }
            if ((**c)->enabled)
                (**c)->update();
        }
}

void Polymorph::Entity::draw()
{
    //TODO :Add an option to draw child independently of parent ?

    Drawable c = getComponent<ADrawableComponent>();

    if (!!c && c->enabled)
        c->draw();
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
    if (!!transform->parent())
        transform->parent()->removeChild(transform);
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
            (**c)->onAwake();
            (**c)->setAsAwaked();
        }
}

Polymorph::Config::XmlEntity &Polymorph::Entity::getXmlConfig() const noexcept {
    return _xml_config;
}

void Polymorph::Entity::start()
{
    for (auto &cl :_components)
        for (auto &c : cl.second) {
            (**c)->start();
            (**c)->setAsStarted();
        }
}

bool Polymorph::Entity::isActive() const
{
    return _active;
}
