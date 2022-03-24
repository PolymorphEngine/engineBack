/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Components.hpp>


std::shared_ptr<Polymorph::AComponentInitializer>
Polymorph::ComponentFactory::create(std::string &type,
                                    Config::XmlComponent &data,
                                    Entity &entity)
{
    if (!_buildables.contains(type))
        return nullptr;
    return _buildables.find(type)->second(data, entity);
}