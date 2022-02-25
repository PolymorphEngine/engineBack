/*
** EPITECH PROJECT, 2020
** XmlComponent.cpp.cc
** File description:
** header for XmlComponent.c
*/

#include "XmlComponent.hpp"

Polymorph::Vector3
Polymorph::Config::XmlComponent::getVector3Property(std::string name)
{
    /*
    XmlNode *vectorProp = node->getChildWithNameAttr(name);
    XmlNode *vector = vectorProp->getChild("Vector");

    return  Polymorph::Vector3(vector->getFloatAttr("x"),
                               vector->getFloatAttr("y"),
                               vector->getFloatAttr("z")
                               );
   */
}

Polymorph::Vector2
Polymorph::Config::XmlComponent::getVector2Property(std::string name)
{
    /*
    XmlNode *vectorProp = node->getChildWithNameAttr(name);
    XmlNode *vector = vectorProp->getChild("Vector");


    return  Polymorph::Vector2(vector->getFloatAttr("x"),
                            vector->getFloatAttr("y"));
    */
}

Polymorph::Rect
Polymorph::Config::XmlComponent::getRectProperty(std::string name)
{
    /*
    XmlNode *rect = node->getChildWithNameAttr(name);

    return  Polymorph::Rect(rect->getFloatAttr("x"),
                            rect->getFloatAttr("y"),
                            rect->getFloatAttr("width"),
                            rect->getFloatAttr("height"));
    */
}

std::string Polymorph::Config::XmlComponent::getStringProperty(std::string name)
{
    /*
    XmlNode *str = node->getChildWithNameAttr(name);

    return str->getAttrValue("value");
     */
}

int Polymorph::Config::XmlComponent::getIntProperty(std::string name)
{
    /*
    XmlNode *integer = node->getChildWithNameAttr(name);

    return integer->getIntAtrr("value"); */
}

float Polymorph::Config::XmlComponent::getFloatProperty(std::string name)
{
/* XmlNode *floating = node->getChildWithNameAttr(name);

    return floating->getFloatAtrr("value") ; */
}

bool Polymorph::Config::XmlComponent::getBoolProperty(std::string name)
{
/*    XmlNode *boolean = node->getChildWithNameAttr(name);

    return boolean->getBoolAtrr("value"); */
}

template<typename T>
T Polymorph::Config::XmlComponent::getTemplatedProperty(std::string name)
{
    /*
    return ; */
}

template<typename T>
T Polymorph::Config::XmlComponent::getTemplatedProperty(XmlNode *node)
{
    /*
    T prop(node);
    return prop; */
}

template<typename T>
std::vector<T>
Polymorph::Config::XmlComponent::getListOfTemplatedProperty(std::string name)
{
    /*
    XmlNode *list = node->getChildWithNameAttr(name);

    std::vector<T> listProperty;
    for (auto &elem: list)
        listProperty.push_back(getTemplatedProperty<T>(elem));
    return listProperty;
     */
}

