/*
** EPITECH PROJECT, 2020
** Entity.cpp.cc
** File description:
** header for Entity.c
*/

#include "factory/ComponentFactory.hpp"
#include "Entity.hpp"
#include "Engine.hpp"
#include "XmlEntity.hpp"
#include "Component.hpp"

Polymorph::Entity::Entity(Config::XmlEntity &data,
Engine &game) : _game(game), _stringId(data.getId())
{
    name = data.getName();
    _active = data.isActive();
    _order = _game.getExecOrder();
    for (auto &type: _order)
        _components[type];
    _isPrefab = false;
}



void Polymorph::Entity::addComponent(std::string &component,
Polymorph::Config::XmlComponent &config)
{
    if (componentExist(component))
        return;
    //TODO : throw ?
    ComponentFactory::Initializer i = ComponentFactory::create(component, config, *this);
    i->build();
    _components[i->getType()].push_back(i);
    AddComponent<TransformComponent>();
}

template<typename T>
Polymorph::safe_ptr<T> Polymorph::Entity::AddComponent()
{
    std::shared_ptr<T> component(new T(*this));

    Config::XmlComponent config;
    //TODO fetch default Config for component
    std::string t = component->getType();
    component.reset();
    if (componentExist(t))
        return safe_ptr<T>();
        //TODO: maybe throw ?
    ComponentFactory::Initializer c = ComponentFactory::create(t, config, *this);
    c->build();
    c->reference();
    _components[c->getType()].push_back(c);
    (**c)->Start();
    return safe_ptr<T>(std::dynamic_pointer_cast<T>((*c).get()));
}

template <typename T>
bool Polymorph::Entity::componentExist() const
{
    std::shared_ptr<T> component(new T(*this));
    std::string type = component->getType();
    std::string def("Default");
    if (!_components.contains(type))
    {
        for (auto &c :  _components.find(def)->second)
        {
            if (c->getType() == type)
                return true;
        }
    }
    else if (!_components.find(type)->second.empty())
        return true;
    return false;
}

template<typename T>
Polymorph::safe_ptr<T> Polymorph::Entity::GetComponent()
{
    std::shared_ptr<T> component (new T(*this));

    std::string t = component->getType();
    component.reset();
    if (!componentExist(t))
        return safe_ptr<T>(nullptr);
    if (!_components.contains(t))
    {
        for (auto &c : _components.find("Default")->second)
            if (c->getType() == t)
                return safe_ptr<T>(std::dynamic_pointer_cast<T>((*c).get()));
    }
    else
        return safe_ptr<T>(std::dynamic_pointer_cast<T>( (*_components[t].begin())->get() ) );
    return safe_ptr<T>();
}

void Polymorph::Entity::Update()
{
    if (!_active)
        return;
    for (auto &cl :_components)
        for (auto &c : cl.second)
        {
            if (!(**c)->IsAwaked())
            {
                (**c)->OnAwake();
                (**c)->SetAsAwaked();
            }
            if (!(**c)->enabled)
                continue;
            if (!(**c)->IsStarted())
            {
                (**c)->Start();
                (**c)->SetAsStarted();
            }
            (**c)->Update();
        }
}

void Polymorph::Entity::Draw()
{
    using DrawableComponent = Component;
    //TODO :Add an option to draw child independently of parent ?
    if (!_active || transform->parent != nullptr)
        return;
    
    //TODO : Draw drawables (only one drawable per entity ??)
    safe_ptr<DrawableComponent> c = GetComponent<DrawableComponent>();
    if (!!c && c->enabled)
        c->Draw();
    DrawChildren(*transform);
}

void Polymorph::Entity::DrawChildren(Polymorph::TransformComponent &trm)
{
    using DrawableComponent = TransformComponent;
    using Drawable = safe_ptr<DrawableComponent>;
    for (auto &child : trm)
    {
        //TODO: check independence before drawing ?
        Drawable drawable = child->gameObject.GetComponent<DrawableComponent>();
        if (!!drawable && drawable->enabled)
            drawable->Draw();
        DrawChildren(*child);
    }
}

void Polymorph::Entity::setActive(bool active)
{
    if (this->_active != active)
    {
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
    for (auto _tag = _tags.begin(); _tag  != _tags.end(); ++ _tag )
    {
        if (tag == *_tag)
        {
            _tags.erase(_tag);
            return;
        }
    }
}

template<typename T>
bool Polymorph::Entity::DeleteComponent()
{
    std::shared_ptr<T> component (new T(*this));

    std::string t = component->getType();
    component.reset();
    if (!componentExist(t))
        return false;
    if (!_components.contains(t))
    {
        auto i = 0;
        auto & defaultList =_components.find("Default")->second;
        for (auto &c : defaultList)
        {
            if (c->getType() == t)
            {
                defaultList.erase(defaultList.begin() + i);
                return false;
            }
            ++i;
        }
    }
    else
    {
        _components[t].clear();
        return true;
    }
    return false;
}

Polymorph::Entity::~Entity()
{
    if (transform->parent != nullptr)
        transform->parent->RemoveChild(*transform);
    
}

bool Polymorph::Entity::componentExist(std::string &type)
{
    std::string def("Default");
    if (!_components.contains(type))
    {
        for (auto &c :  _components.find(def)->second)
        {
            if (c->getType() == type)
                return true;
        }
    }
    else if (!_components.find(type)->second.empty())
        return true;
    return false;
}

void Polymorph::Entity::Awake()
{
    for (auto &cl :_components)
        for (auto &c : cl.second)
        {
            c->reference();
            (**c)->OnAwake();
            (**c)->SetAsAwaked();
        }
}
