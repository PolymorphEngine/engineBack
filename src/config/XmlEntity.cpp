/*
** EPITECH PROJECT, 2020
** XmlEntity.cpp.cc
** File description:
** header for XmlEntity.c
*/

#include "Engine/config/XmlEntity.hpp"
#include "Entity.hpp"

namespace Polymorph
{
    std::shared_ptr<Entity> Config::XmlEntity::makeInstance()
    {
        std::shared_ptr<Config::XmlEntity> conf = std::shared_ptr<Config::XmlEntity>(this);
        std::shared_ptr<Entity> e(new Entity(conf, this->_engine));

        for (auto &c: _components)
        {
            std::string t = c->getType();
            (*e).addComponent(t, *c);
        }
        return e;
    }

    Config::XmlEntity::XmlEntity(std::shared_ptr<XmlNode> &node,
    std::shared_ptr<Engine> &engine) 
    {
        _engine = engine;
        this->_node = node;
    }

    std::string &Config::XmlEntity::getName() const
    {
        //TODO: fetch name from conf
        throw std::runtime_error("XmlEntity::getName(): Not yet implemented");
    }

    bool Config::XmlEntity::isActive() const
    {
        //TODO: fetch active state from conf
        throw std::runtime_error("XmlEntity::isActive(): Not yet implemented");
    }

    std::string &Config::XmlEntity::getId() const
    {
        //TODO: fetch id from conf
        throw std::runtime_error("XmlEntity::getId(): Not yet implemented");
    }

    std::vector<std::string> Config::XmlEntity::getTags() const
    {
        //TODO: fetch tags from conf
        throw std::runtime_error("XmlEntity::getTags(): Not yet implemented");
    }

    std::string Config::XmlEntity::getLayer() const
    {
        //TODO: fetch layer from conf
        throw std::runtime_error("XmlEntity::getLayer(): Not yet implemented");
    }
}
