/*
** EPITECH PROJECT, 2020
** XmlEntityRef.cpp
** File description:
** XmlEntityRef.cpp
*/

#include "XmlEntityRef.hpp"
#include "Scene.hpp"

namespace Polymorph::Config
{

    GameObject XmlEntityRef::getReference()
    {
        GameObject ref = reinterpret_cast<safe_ptr <Entity> &>(_scene.findId(
                _id));
        return ref;
    }

    XmlEntityRef::XmlEntityRef(XmlNode &node, Scene &scene) : _scene(scene)
    {
        
    }

}