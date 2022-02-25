/*
** EPITECH PROJECT, 2020
** PolymorphXml.cpp.cc
** File description:
** header for PolymorphXml.c
*/

#include "PolymorphXml.hpp"

namespace Polymorph::Config
{

    template<typename T>
    XmlProperty<T>::XmlProperty(XmlNode *node)
    {
        this->node = node;
    }

}
