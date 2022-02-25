/*
** EPITECH PROJECT, 2020
** Entity.cpp.cc
** File description:
** header for Entity.c
*/

#include "factory/ComponentFactory.hpp"
#include "Entity.hpp"

Polymorph::Entity::Entity(const Polymorph::Config::XmlEntity &data,
Polymorph::Engine &game) : _game(game)
{

}

void Polymorph::Entity::addComponent(std::string &component,
Polymorph::Config::XmlComponent &config)
{
    if (componentExist(component))
        return;
    //TODO : throw ?
    ComponentFactory::Initializer i = ComponentFactory::create(component, config, *this);
    i->build();
    _components.push_back(i);
}

template<typename T>
std::shared_ptr<T> &Polymorph::Entity::AddComponent()
{
    std::unique_ptr<T> component;
    ComponentFactory::Initializer c = nullptr;
    try
    {
        component = std::make_unique<T>(new T(*this));
    }
    catch (std::exception &e)
    {
        //TODO: Log error "Unknow component to add"
    }

    Config::XmlComponent config;
    //TODO fetch default Config for component

    if (std::is_same_v<T, Component>)
    {
        std::string t = component->getType();
        if (componentExist(t))
            return nullptr;
        //TODO: maybe throw ?
        c = ComponentFactory::create(t, config, *this);
        c->build();
        c->reference();
        _components.push_back(c);
        return *c;
    }
    //TODO: Log error "Unknow component to add"
    return nullptr;
}

bool Polymorph::Entity::componentExist(const std::string &type) const
{
    for (auto &c : _components)
    {
        if (c->getType() == type)
            return true;
    }
    return false;
}

template<typename T>
std::shared_ptr<T> &Polymorph::Entity::GetComponent()
{
    std::unique_ptr<T> component;
    try
    {
        component = std::make_unique<T>(new T(*this));
    }
    catch (std::exception &e)
    {
        return nullptr;
    }

    Config::XmlComponent config;
    if (std::is_same_v<T, Component>)
    {
        std::string t = dynamic_cast<Component>(component).getType();
        for (auto &c: _components)
        {
            if (c->getType() == t)
                return *c;
        }
    }
    return nullptr;
}

std::vector<Polymorph::ComponentFactory::Initializer> &Polymorph::Entity::getComponents()
{
    return _components;
}
