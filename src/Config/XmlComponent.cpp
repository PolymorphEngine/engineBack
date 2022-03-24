/*
** EPITECH PROJECT, 2020
** XmlComponent.cpp.cc
** File description:
** header for XmlComponent.c
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>
#include "XmlComponent.hpp"


std::string Polymorph::Config::XmlComponent::getType()
{
    if (this == Empty.get())
        return "Empty";
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

std::shared_ptr<myxmlpp::Node> Polymorph::Config::XmlComponent::_findProperty(const std::string& name, Logger::severity level)
{
    for (auto &property: *node) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR) {
        Logger::log("In component '"+node->findAttribute("type")->getValue()+"': property named '" + name + "': not found.", level);
        return nullptr;
    }
    throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': property named '" + name + "': not found.", Logger::MAJOR);
}



void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, int &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;
    _setPropertyFromAttr("value", toSet, *propNode, level);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, float &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;
    _setPropertyFromAttr("value", toSet, *propNode, level);
}


void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, bool &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;
    _setPropertyFromAttr("value", toSet, *propNode, level);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::string &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;
    _setPropertyFromAttr("value", toSet, *propNode, level);
}




void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Vector3 &toSet, Logger::severity level)
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
    _setPropertyFromAttr("x", toSet.x, *vector, level);
    _setPropertyFromAttr("y", toSet.y, *vector, level);
    _setPropertyFromAttr("z", toSet.z, *vector, level);
}



void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Vector2 &toSet, Logger::severity level)
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
    _setPropertyFromAttr("x", toSet.x, *vector, level);
    _setPropertyFromAttr("y", toSet.y, *vector, level);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Rect &toSet, Logger::severity level)
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

    _setPropertyFromAttr("x", toSet.x, *rect, level);
    _setPropertyFromAttr("y", toSet.y, *rect, level);
    _setPropertyFromAttr("width", toSet.width, *rect, level);
    _setPropertyFromAttr("height", toSet.height, *rect, level);
}


void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<int> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueInt());
        } catch (...) {
            Logger::log("Property Int List named '" + propertyName +
                        "': has no value", level);
        }
    }
}



void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<float> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueFloat());
        } catch (...) {
            Logger::log("Property Float List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<bool> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueBool());
        } catch (...) {
            Logger::log("Property Bool List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<std::string> &toSet, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValue());
        } catch (...) {
            Logger::log("Property String List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, Logger::severity level)
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
                        level);
            continue;
        }
        _setPropertyFromAttr("x", tmp.x, *vector, level);
        _setPropertyFromAttr("y", tmp.y, *vector, level);
        _setPropertyFromAttr("z", tmp.z, *vector, level);

        toSet[count] = tmp;
        count += 1;
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Sprite &toSet, Logger::severity level)
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

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Text &toSet, Logger::severity level)
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

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, GameObject &toSet, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, level);
    std::string id;

    if (refProp == nullptr)
        return;

    _setPropertyFromAttr("id", id, *refProp, level);
    toSet = SceneManager::findById(id);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, Logger::severity level)
{
    auto refProp = _findProperty(propertyName, level);
    auto i = 0;

    if (refProp == nullptr)
        return;

    for (auto &elem : *refProp) {
        try {
            auto id = elem->findAttribute("id")->getValue();
            auto gameObject = SceneManager::findById(id);

            if (!gameObject)
                throw;
            toSet.push_back(gameObject);
        } catch (myxmlpp::Exception &e) {
            Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                        ", in list named '" + propertyName + "': has no value" +
                        e.baseWhat(), level);
        } catch (...) {
            Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                        ", in list named '" + propertyName + "': not found",
                        level);
        }
        ++i;
    }
}



// STATICS
std::shared_ptr<myxmlpp::Node>
Polymorph::Config::XmlComponent::_findProperty(const std::string& name,
                                               std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    for (auto &property: *data) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR) {
        Logger::log("In property'"+data->getTag()+"': sub-property named '" + name + "': not found.", level);
        return nullptr;
    }
    throw ConfigurationException("In property '"+data->getTag()+"': sub-property named '" + name + "': not found.", Logger::MAJOR);
}


void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, int &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    if (!_setPropertyFromAttr("value", toSet, *propNode, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, float &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    if (!_setPropertyFromAttr("value", toSet, *propNode, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}


void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, bool &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    if (!_setPropertyFromAttr("value", toSet, *propNode, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::string &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);
    auto parent_type = data->findAttribute("type")->getValue();
    auto parent_name = data->findAttribute("name")->getValue();

    if (propNode == nullptr)
        return;

    if (!_setPropertyFromAttr("value", toSet, *propNode, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}




void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Vector3 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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

    if (!_setPropertyFromAttr("x", toSet.x, *vector, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("y", toSet.y, *vector, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("z", toSet.z, *vector, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}



void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Vector2 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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

    if (!_setPropertyFromAttr("x", toSet.x, *vector, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("y", toSet.y, *vector, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}




void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, Rect &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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
    if (!_setPropertyFromAttr("x", toSet.x, *rect, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("y", toSet.y, *rect, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("width", toSet.width, *rect, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);

    if (!_setPropertyFromAttr("height", toSet.height, *rect, level))
        Logger::log("In property type '"+parent_type+"', named '"+parent_name+"': sub-property named '" + propertyName +
                    "': has missing value", level);
}


void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<int> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueInt());
        } catch (...) {
            Logger::log("Property Int List named '" + propertyName +
                        "': has no value", level);
        }
    }
}



void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<float> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueFloat());
        } catch (...) {
            Logger::log("Property Float List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<bool> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValueBool());
        } catch (...) {
            Logger::log("Property Bool List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<std::string> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    auto propNode = _findProperty(propertyName, data, level);

    if (propNode == nullptr)
        return;

    for (auto &element : *propNode) {
        try {
            toSet.push_back(element->findAttribute("value")->getValue());
        } catch (...) {
            Logger::log("Property String List named '" + propertyName +
                        "': has no value", level);
        }
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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
                        level);
            continue;
        }
        _setPropertyFromAttr("x", tmp.x, *vector, level);
        _setPropertyFromAttr("y", tmp.y, *vector, level);
        _setPropertyFromAttr("z", tmp.z, *vector, level);

        toSet[count] = tmp;
        count += 1;
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, GameObject &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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

bool Polymorph::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           int &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueInt();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            Logger::log(e.what(),
                        level);
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool Polymorph::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           float &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueFloat();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            Logger::log(e.what(),
                        level);
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool Polymorph::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           bool &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueBool();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            Logger::log(e.what(),
                        level);
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool Polymorph::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           std::string &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValue();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            Logger::log(e.what(),
                        level);
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

void Polymorph::Config::XmlComponent::setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
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
                            level);
                throw;
            }
            toSet.push_back(gameObject);
        } catch (myxmlpp::Exception &e) {
            Logger::log("Property gameObject ref nb: " + std::to_string(i) +
                        ", in list named '" + propertyName + "': has no value" +
                        e.baseWhat(), level);
        }
        ++i;
    }
}
