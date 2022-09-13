/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Components.hpp>
#include <utility>


std::shared_ptr<Polymorph::IComponentInitializer>
Polymorph::ComponentFactory::create(std::string &type,
                                    Config::XmlComponent &data,
                                    GameObject entity)
{
    if (!_buildables.contains(type))
        return nullptr;
    return _buildables.find(type)->second(data, std::move(entity));
}