/*
** EPITECH PROJECT, 2020
** XmlComponent.cpp.cc
** File description:
** header for XmlComponent.c
*/


#include "XmlComponent.hpp"
#include "Log/Logger.hpp"
#include "Vector.hpp"
#include "Rect.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"
#include "SceneManager.hpp"
#include <myxmlpp.hpp>


std::string Polymorph::Config::XmlComponent::getType()
{
    try
    {
        type = node->findAttribute("type")->getValue();
        return type;
    }
    catch(myxmlpp::Exception &e)
    {
        throw ConfigurationException("No Component type found in configuration !\n"+e.baseWhat(), Logger::MAJOR);
    }
}

bool Polymorph::Config::XmlComponent::isEnabled()
{
    try
    {
        return node->findAttribute("enabled")->getValueBool();
    }
    catch(myxmlpp::Exception &e)
    {
        Logger::Log("No state property found for component '"+type+"': set to false by default", Logger::DEBUG);
        return false;
    }
}



Polymorph::Config::XmlComponent::XmlComponent(std::shared_ptr<XmlNode> node)
{
    this->node = node;
}

std::shared_ptr<myxmlpp::Node> Polymorph::Config::XmlComponent::findProperty(std::string name)
{
    for (auto &property: *node)
    {
        try
        {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        }
        catch (...) {}
    }
    Logger::Log("Property name '"+name+"': not found.", Logger::DEBUG);
    return nullptr;
}



template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, int &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try
    {
        toSet = propNode->findAttribute("value")->getValueInt();
    } catch (...) {
        Logger::Log("Property named '" +propertyName+ "': has no value", Logger::DEBUG);
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, float &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try
    {
        toSet = propNode->findAttribute("value")->getValueFloat();
    } catch (...) {
        Logger::Log("Property named '" +propertyName+ "': has no value", Logger::DEBUG);
    }
}


template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, bool &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try
    {
        toSet = propNode->findAttribute("value")->getValueBool();
    } catch (...) {
        Logger::Log("Property named '" +propertyName+ "': has no value", Logger::DEBUG);
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::string &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try
    {
        toSet = propNode->findAttribute("value")->getValue();
    } catch (...) {
        Logger::Log("Property named '" +propertyName+ "': has no value", Logger::DEBUG);
    }
}




template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector3 &toSet)
{
    std::shared_ptr<XmlNode> vectorProp = findProperty(propertyName);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        Logger::Log("Incomplete Vector2 property named '" +propertyName + "': not found", Logger::DEBUG);
    }
    
    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::Log("x value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
    
    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::Log("y value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
    
    try {
        toSet.z = vector->findAttribute("z")->getValueFloat();
    } catch (...) {
        Logger::Log("z value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
}



template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector2 &toSet)
{
    std::shared_ptr<XmlNode> vectorProp = findProperty(propertyName);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;
    
    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        Logger::Log("Incomplete Vector2 property named '" +propertyName + "': not found", Logger::DEBUG);
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::Log("x value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::Log("y value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
}




template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Rect &toSet)
{
    std::shared_ptr<XmlNode> rectProp = findProperty(propertyName);
    std::shared_ptr<XmlNode> rect;

    if (rectProp == nullptr)
        return;

    try {
        rect = rectProp->findChild("Rect");
    } catch (...) {
        Logger::Log("Incomplete Rect property named '" +propertyName + "': not found", Logger::DEBUG);
        return;
    }

    try {
        toSet.x = rect->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::Log("x value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
    
    try
    {
        toSet.y = rect->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::Log("y value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
    
    try {
        toSet.width = rect->findAttribute("width")->getValueFloat();
    } catch (...) {
        Logger::Log("width value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
    
    try {
        toSet.height = rect->findAttribute("height")->getValueFloat();
    } catch (...) {
        Logger::Log("height value of vector property named '" +propertyName+ "': not found", Logger::DEBUG);
    }
}


template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<int> &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueInt());
        } catch (...) {
            Logger::Log("Property Int List named '" + propertyName + "': has no value", Logger::DEBUG);
        }
    }
}



template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<float> &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueFloat());
        } catch (...) {
            Logger::Log("Property Float List named '" + propertyName + "': has no value", Logger::DEBUG);
        }
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<bool> &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueBool());
        } catch (...) {
            Logger::Log("Property Bool List named '" + propertyName + "': has no value", Logger::DEBUG);
        }
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<std::string> &toSet)
{
    auto propNode = findProperty(propertyName);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValue());
        } catch (...) {
            Logger::Log("Property String List named '" + propertyName + "': has no value", Logger::DEBUG);
        }
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<Vector3> &toSet)
{
    auto vectorProp = findProperty(propertyName);
    std::shared_ptr<XmlNode> vector;
    size_t count = 0;
    Vector3 tmp;
    
    if (vectorProp == nullptr)
        return;

    for (auto &element : *vectorProp) {
        tmp = Vector3();
        try {
            vector = element->findChild("Vector");
        } catch (...) {
            Logger::Log("Incomplete Vector3 property named '" + propertyName + "' at index" + std::to_string(count) + ": not found", Logger::DEBUG);
            continue;
        }

        try {
            tmp.x = vector->findAttribute("x")->getValueFloat();
        } catch (...) {
            Logger::Log("x value of vector property named '" + propertyName + "' at index" + std::to_string(count) + ": not found", Logger::DEBUG);
        }

        try {
            tmp.y = vector->findAttribute("y")->getValueFloat();
        } catch (...) {
            Logger::Log("y value of vector property named '" + propertyName + "' at index" + std::to_string(count) + ": not found", Logger::DEBUG);
        }

        try {
            tmp.z = vector->findAttribute("z")->getValueFloat();
        } catch (...) {
            Logger::Log("z value of vector property named '" + propertyName + "' at index" + std::to_string(count) + ": not found", Logger::DEBUG);
        }
        
        toSet[count] = tmp;
        count += 1;
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, GameObject &toSet)
{
    auto refProp = findProperty(propertyName);

    if (refProp == nullptr)
        return;

    try
    {
        auto id = refProp->findAttribute("id")->getValue();
        //TODO: CALL SCENE MANAGER
//        toSet = SceneManager::FindById(id);
    }
    catch (...)
    {
        Logger::Log("Property gameObject ref named '" +propertyName+ "': has no value", Logger::DEBUG);
    }
}

template<>
void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<GameObject> &toSet)
{
    auto refProp = findProperty(propertyName);
    auto i = 0;
    
    if (refProp == nullptr)
        return;

    for (auto &elem : *refProp)
    {
        try
        {
            auto id = refProp->findAttribute("id")->getValue();
            //TODO: CALL SCENE MANAGER
            /*auto gameObject = SceneManager::FindById(id);

            if (!gameObject)
                throw;
            toSet.push_back(gameObject); */
        }
        catch (...)
        {
            Logger::Log("Property gameObject ref nb: "+std::to_string(i)+", in list named '" +propertyName+ "': has no value", Logger::DEBUG);
        }
        ++i;
    }
}
