/*
** EPITECH PROJECT, 2020
** XmlEntityRef.cpp
** File description:
** XmlEntityRef.cpp
*/

#include "XmlEntityRef.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

namespace Polymorph::Config
{

    GameObject XmlEntityRef::getReference()
    {
        return SceneManager::FindById(_id);
    }

    XmlEntityRef::XmlEntityRef(XmlNode &node)
    {
        _id = node.findAttribute("id")->getValue();
    }

}