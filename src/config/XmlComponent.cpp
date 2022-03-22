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
#include "Exceptions/ConfigurationException.hpp"
#include "SceneManager.hpp"
#include <myxmlpp.hpp>


std::string Polymorph::Config::XmlComponent::getType()
{
    try {
        type = node->findAttribute("type")->getValue();
        return type;
    } catch(myxmlpp::Exception &e) {
        throw ConfigurationException("No Component type found in configuration !\n"+e.baseWhat(), Logger::MAJOR);
    }
}

bool Polymorph::Config::XmlComponent::isEnabled()
{
    try {
        return node->findAttribute("enabled")->getValueBool();
    } catch(myxmlpp::Exception &e) {
        Logger::log("No state property found for component '" + type +
                    "': set to false by default", Logger::DEBUG);
        return false;
    }
}



Polymorph::Config::XmlComponent::XmlComponent(const std::shared_ptr<XmlNode> &node)
{
    this->node = node;
}

std::shared_ptr<myxmlpp::Node> Polymorph::Config::XmlComponent::_findProperty(std::string name, Logger::severity level)
{
    for (auto &property: *node) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR)
    {
        Logger::log("In component '"+node->findAttribute("type")->getValue()+"': property named '" + name + "': not found.", level);
        return nullptr;
    }
    throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': property named '" + name + "': not found.", Logger::MAJOR);
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, int &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueInt();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, float &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, bool &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueBool();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::string &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValue();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector3 &toSet, Logger::severity level)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName, level);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.z = vector->findAttribute("z")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector2 &toSet, Logger::severity level)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName, level);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Rect &toSet, Logger::severity level)
{
    std::shared_ptr<XmlNode> rectProp = _findProperty(propertyName, level);
    std::shared_ptr<XmlNode> rect;

    if (rectProp == nullptr)
        return;

    try {
        rect = rectProp->findChild("Rect");
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = rect->findAttribute("x")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = rect->findAttribute("y")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.width = rect->findAttribute("width")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.height = rect->findAttribute("height")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<int> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueInt());
        } catch (...) {
            Logger::log("Property Int List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<float> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueFloat());
        } catch (...) {
            Logger::log("Property Float List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<bool> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueBool());
        } catch (...) {
            Logger::log("Property Bool List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<std::string> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValue());
        } catch (...) {
            Logger::log("Property String List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<Vector3> &toSet, Logger::severity level)
{
    auto vectorProp = _findProperty(propertyName, level);
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
            Logger::log("Incomplete Vector3 property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
            continue;
        }

        try {
            tmp.x = vector->findAttribute("x")->getValueFloat();
        } catch (...) {
            Logger::log("x value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        try {
            tmp.y = vector->findAttribute("y")->getValueFloat();
        } catch (...) {
            Logger::log("y value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        try {
            tmp.z = vector->findAttribute("z")->getValueFloat();
        } catch (...) {
            Logger::log("z value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        toSet[count] = tmp;
        count += 1;
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Sprite &toSet, Logger::severity level)
{
    auto data = _findProperty(propertyName, level);
    
    try {
        toSet = GraphicalAPI::createSprite(data);
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Text &toSet, Logger::severity level)
{
    auto data = _findProperty(propertyName, level);
    
    try {
        toSet = GraphicalAPI::createText(data);
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, GameObject &toSet, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, level);

    if (refProp == nullptr)
        return;

    try {
        auto id = refProp->findAttribute("id")->getValue();
        toSet = SceneManager::findById(id);
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Property gameObject ref named '" + propertyName +
                    "': has no value", level);
        else
            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Property gameObject ref named '" + propertyName +
                                        "': has no value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<GameObject> &toSet, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, level);
    auto i = 0;

    if (refProp == nullptr)
        return;

    for (auto &elem : *refProp) {
        try {
            auto id = elem->findAttribute("id")->getValue();
            auto gameObject = SceneManager::findById(id);

            if (!gameObject) {
                Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                            ", in list named '" + propertyName + "': not found",
                            Logger::DEBUG);
                throw;
            }
            toSet.push_back(gameObject);
        } catch (myxmlpp::Exception &e) {
            Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                        ", in list named '" + propertyName + "': has no value" +
                        e.baseWhat(), Logger::DEBUG);
        }
        ++i;
    }
}



// STATICS
std::shared_ptr<myxmlpp::Node>
Polymorph::Config::XmlComponent::_findProperty(std::string name,
                                               std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    for (auto &property: *data) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR)
    {
        Logger::log("In property'"+data->getTag()+"': sub-property named '" + name + "': not found.", level);
        return nullptr;
    }
    throw ConfigurationException("In property '"+data->getTag()+"': sub-property named '" + name + "': not found.", Logger::MAJOR);
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, int &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueInt();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
            "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, float &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();
    
    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, bool &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueBool();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::string &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();
    
    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValue();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector3 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName, data, level);
    std::shared_ptr<XmlNode> vector;
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.z = vector->findAttribute("z")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector2 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName, data, level);
    std::shared_ptr<XmlNode> vector;
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();
    
    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {

        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {

        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {

        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Rect &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    std::shared_ptr<XmlNode> rectProp = _findProperty(propertyName, data, level);
    std::shared_ptr<XmlNode> rect;
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (rectProp == nullptr)
        return;

    try {
        rect = rectProp->findChild("Rect");
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
        return;
    }

    try {
        toSet.x = rect->findAttribute("x")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.y = rect->findAttribute("y")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.width = rect->findAttribute("width")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }

    try {
        toSet.height = rect->findAttribute("height")->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<int> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueInt());
        } catch (...) {
            Logger::log("Property Int List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<float> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueFloat());
        } catch (...) {
            Logger::log("Property Float List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<bool> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueBool());
        } catch (...) {
            Logger::log("Property Bool List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<std::string> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValue());
        } catch (...) {
            Logger::log("Property String List named '" + propertyName +
                        "': has no value", Logger::DEBUG);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<Vector3> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto vectorProp = _findProperty(propertyName, data, level);
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
            Logger::log("Incomplete Vector3 property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
            continue;
        }

        try {
            tmp.x = vector->findAttribute("x")->getValueFloat();
        } catch (...) {
            Logger::log("x value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        try {
            tmp.y = vector->findAttribute("y")->getValueFloat();
        } catch (...) {
            Logger::log("y value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        try {
            tmp.z = vector->findAttribute("z")->getValueFloat();
        } catch (...) {
            Logger::log("z value of vector property named '" + propertyName +
                        "' at index" + std::to_string(count) + ": not found",
                        Logger::DEBUG);
        }

        toSet[count] = tmp;
        count += 1;
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, GameObject &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (refProp == nullptr)
        return;

    try {
        auto id = refProp->findAttribute("id")->getValue();
        toSet = SceneManager::findById(id);
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<GameObject> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, data, level);
    auto i = 0;

    if (refProp == nullptr)
        return;

    for (auto &elem : *refProp) {
        try {
            auto id = elem->findAttribute("id")->getValue();
            auto gameObject = SceneManager::findById(id);

            if (!gameObject) {
                Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                            ", in list named '" + propertyName + "': not found",
                            Logger::DEBUG);
                throw;
            }
            toSet.push_back(gameObject);
        } catch (myxmlpp::Exception &e) {
            Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                        ", in list named '" + propertyName + "': has no value" +
                        e.baseWhat(), Logger::DEBUG);
        }
        ++i;
    }
}


void Polymorph::Config::XmlComponent::setPropertyFromAttr(std::string propertyName, int &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto &propNode = data;


    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute(propertyName)->getValueInt();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setPropertyFromAttr(std::string propertyName, float &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto &propNode = data;

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute(propertyName)->getValueFloat();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}


void Polymorph::Config::XmlComponent::setPropertyFromAttr(std::string propertyName, bool &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto &propNode = data;

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute(propertyName)->getValueBool();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}

void Polymorph::Config::XmlComponent::setPropertyFromAttr(std::string propertyName, std::string &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto &propNode = data;


    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute(propertyName)->getValue();
    } catch (...) {
        if (level != Logger::MAJOR)
            Logger::log("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                        "': has missing value", level);
        else
            throw ConfigurationException("In property type '"+data->findAttribute("type")->getValue()+"': attribute named '" + propertyName +
                                         "': has missing value", Logger::MAJOR);
    }
}
