/*
** EPITECH PROJECT, 2020
** XmlComponentRef.cpp
** File description:
** XmlComponentRef.cpp
*/

#include "XmlComponentRef.hpp"

namespace Polymorph::Config
{

    template<typename T>
    XmlComponentRef<T>::XmlComponentRef(XmlNode &node, Scene &scene)
            :XmlEntityRef(node, scene)
    {
        throw std::runtime_error("XmlComponentRef::Constructor(): Not yet implemented");
    }

    template<typename T>
    safe_ptr<T> XmlComponentRef<T>::getComponentReference()
    {
        GameObject entity = getReference();
        if (!entity)
            return safe_ptr<T>(nullptr);
        return (*entity)->GetComponent<T>();
    }

}