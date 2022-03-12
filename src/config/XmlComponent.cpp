/*
** EPITECH PROJECT, 2020
** XmlComponent.cpp.cc
** File description:
** header for XmlComponent.c
*/

#include "XmlEntityRef.hpp"
#include "XmlComponentRef.hpp"
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
    throw std::runtime_error("XmlComponent::getVector3Property(): Not yet implemented");
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
    throw std::runtime_error("XmlComponent::getVector2Property(): Not yet implemented");
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
    throw std::runtime_error("XmlComponent::getRectProperty(): Not yet implemented");
}

std::string Polymorph::Config::XmlComponent::getStringProperty(std::string name)
{
    /*
    XmlNode *str = node->getChildWithNameAttr(name);

    return str->getAttrValue("value");
     */
    throw std::runtime_error("XmlComponent::getStringProperty(): Not yet implemented");
}

int Polymorph::Config::XmlComponent::getIntProperty(std::string name)
{
    /*
    XmlNode *integer = node->getChildWithNameAttr(name);

    return integer->getIntAtrr("value"); */
    throw std::runtime_error("XmlComponent::getIntProperty(): Not yet implemented");
}

float Polymorph::Config::XmlComponent::getFloatProperty(std::string name)
{
/* XmlNode *floating = node->getChildWithNameAttr(name);

    return floating->getFloatAtrr("value") ; */
    throw std::runtime_error("XmlComponent::getFloatProperty(): Not yet implemented");
}

bool Polymorph::Config::XmlComponent::getBoolProperty(std::string name)
{
/*    XmlNode *boolean = node->getChildWithNameAttr(name);

    return boolean->getBoolAtrr("value"); */
    throw std::runtime_error("XmlComponent::getBoolProperty(): Not yet implemented");
}

template<typename T>
T Polymorph::Config::XmlComponent::getTemplatedProperty(std::string name)
{
    /*
    return ; */
    throw std::runtime_error("XmlComponent::getTemplatedProperty(): Not yet implemented");
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
    throw std::runtime_error("XmlComponent::getListOfTemplatedProperty(): Not yet implemented");

}

std::string Polymorph::Config::XmlComponent::getType()
{
    return type;
}

bool Polymorph::Config::XmlComponent::isEnabled()
{
    //TODO: fetch enabled state from conf
    throw std::runtime_error("XmlComponent::isEnabled(): Not yet implemented");
}

Polymorph::safe_ptr<Polymorph::Entity>
Polymorph::Config::XmlComponent::getEntityReferenceProperty(std::string name)
{
    XmlEntityRef ref = XmlEntityRef(*node);
    
    return ref.getReference();
}

std::vector<Polymorph::GameObject>
Polymorph::Config::XmlComponent::getEntityReferencePropertylList(std::string
name)
{
    //TODO : search list property
    throw std::runtime_error("XmlComponent::getEntityReferencePropertyList(): Not yet implemented");
}

template<typename T>
Polymorph::safe_ptr<T>
Polymorph::Config::XmlComponent::getComponentReferenceProperty(std::string name)
{
    XmlComponentRef<T> ref = XmlComponentRef<T>(*node);
    
    return ref.getComponentReference();
}

Polymorph::Config::XmlComponent::XmlComponent(std::shared_ptr<XmlNode> node)
{
    this->node = node;
}

