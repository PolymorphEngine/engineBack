/*
** EPITECH PROJECT, 2020
** XmlScene.cpp.cc
** File description:
** header for XmlScene.c
*/

#include "config/XmlScene.hpp"
#include "factory/ComponentInitializer.hpp"

namespace Polymorph
{
    std::vector<std::shared_ptr<Entity>> Polymorph::Config::XmlScene::getEntities()
    {
        std::vector<std::shared_ptr<Entity>> entities;
        for (auto &i: _entities)
            entities.push_back(i->makeInstance());
        bind_references(entities, _engine);
        return entities;
    }


    void Config::XmlScene::bind_references(std::vector<std::shared_ptr<Entity>> &entities, Engine &game)
    {
        for (auto &e: entities)
        {
            for (auto &c: e->getComponents())
                c->reference();
        }
    }
}
