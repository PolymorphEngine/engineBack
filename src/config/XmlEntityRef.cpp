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
        return _scene.findById(_id);
    }

    XmlEntityRef::XmlEntityRef(XmlNode &node, Scene &scene) : _scene(scene)
    {
        //TODO: fetch ID of the reference
        throw std::runtime_error("XmlEntityRef::Constructor: Not yet implemented");
    }

}