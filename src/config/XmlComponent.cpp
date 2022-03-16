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

std::shared_ptr<myxmlpp::Node> Polymorph::Config::XmlComponent::_findProperty(std::string name)
{
    for (auto &property: *node) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    Logger::log("Property name '" + name + "': not found.", Logger::DEBUG);
    return nullptr;
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, int &toSet)
{
    auto propNode = _findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueInt();
    } catch (...) {
        Logger::log("Property named '" + propertyName + "': has no value",
                    Logger::DEBUG);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, float &toSet)
{
    auto propNode = _findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueFloat();
    } catch (...) {
        Logger::log("Property named '" + propertyName + "': has no value",
                    Logger::DEBUG);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, bool &toSet)
{
    auto propNode = _findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValueBool();
    } catch (...) {
        Logger::log("Property named '" + propertyName + "': has no value",
                    Logger::DEBUG);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::string &toSet)
{
    auto propNode = _findProperty(propertyName);

    if (propNode == nullptr)
        return;

    try {
        toSet = propNode->findAttribute("value")->getValue();
    } catch (...) {
        Logger::log("Property named '" + propertyName + "': has no value",
                    Logger::DEBUG);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector3 &toSet)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        Logger::log("Incomplete Vector2 property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::log("x value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::log("y value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.z = vector->findAttribute("z")->getValueFloat();
    } catch (...) {
        Logger::log("z value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }
}



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Vector2 &toSet)
{
    std::shared_ptr<XmlNode> vectorProp = _findProperty(propertyName);
    std::shared_ptr<XmlNode> vector;

    if (vectorProp == nullptr)
        return;

    try {
        vector = vectorProp->findChild("Vector");
    } catch (...) {
        Logger::log("Incomplete Vector2 property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.x = vector->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::log("x value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.y = vector->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::log("y value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }
}




void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, Rect &toSet)
{
    std::shared_ptr<XmlNode> rectProp = _findProperty(propertyName);
    std::shared_ptr<XmlNode> rect;

    if (rectProp == nullptr)
        return;

    try {
        rect = rectProp->findChild("Rect");
    } catch (...) {
        Logger::log("Incomplete Rect property named '" + propertyName +
                    "': not found", Logger::DEBUG);
        return;
    }

    try {
        toSet.x = rect->findAttribute("x")->getValueFloat();
    } catch (...) {
        Logger::log("x value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.y = rect->findAttribute("y")->getValueFloat();
    } catch (...) {
        Logger::log("y value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.width = rect->findAttribute("width")->getValueFloat();
    } catch (...) {
        Logger::log("width value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }

    try {
        toSet.height = rect->findAttribute("height")->getValueFloat();
    } catch (...) {
        Logger::log("height value of vector property named '" + propertyName +
                    "': not found", Logger::DEBUG);
    }
}


void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<int> &toSet)
{
    auto propNode = _findProperty(propertyName);

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



void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<float> &toSet)
{
    auto propNode = _findProperty(propertyName);

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

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<bool> &toSet)
{
    auto propNode = _findProperty(propertyName);

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

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<std::string> &toSet)
{
    auto propNode = _findProperty(propertyName);

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

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<Vector3> &toSet)
{
    auto vectorProp = _findProperty(propertyName);
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

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, GameObject &toSet)
{
    auto refProp = _findProperty(propertyName);

    if (refProp == nullptr)
        return;

    try {
        auto id = refProp->findAttribute("id")->getValue();
        toSet = SceneManager::findById(id);
    } catch (...) {
        Logger::log("Property gameObject ref named '" + propertyName +
                    "': has no value", Logger::DEBUG);
    }
}

void Polymorph::Config::XmlComponent::setProperty(std::string propertyName, std::vector<GameObject> &toSet)
{
    auto refProp = _findProperty(propertyName);
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
