/*
** EPITECH PROJECT, 2020
** XmlScene.cpp.cc
** File description:
** header for XmlScene.c
*/

#include "config/XmlScene.hpp"
#include "config/XmlEntity.hpp"
#include "factory/ComponentInitializer.hpp"
#include "Entity.hpp"

namespace Polymorph
{
    std::vector<std::shared_ptr<Entity>> Config::XmlScene::getEntities()
    {
        std::vector<std::shared_ptr<Entity>> entities;
        for (auto &i: _entities)
            entities.push_back(i->makeInstance());
        return entities;
    }

    std::string &Config::XmlScene::getId()
    {
        throw std::runtime_error("No yet implemented");
    }
}
