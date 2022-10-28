/*
** EPITECH PROJECT, 2020
** XmlComponent.cpp.cc
** File description:
** header for XmlComponent.c
*/


#include <polymorph/Core.hpp>
#include <polymorph/Config.hpp>


std::string polymorph::engine::Config::XmlComponent::getType()
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

bool polymorph::engine::Config::XmlComponent::isEnabled()
{
    try {
        return node->findAttribute("enabled")->getValueBool();
    } catch(myxmlpp::Exception &e) {
        entity->Debug.log("No state property found for component '" + type +
                    "': set to false by default", Logger::DEBUG);
        return false;
    }
}

polymorph::engine::Config::XmlComponent::XmlComponent(const std::shared_ptr<XmlNode> &node, GameObject entity)
{
    this->node = node;
    this->entity = entity;
}

std::shared_ptr<myxmlpp::Node> polymorph::engine::Config::XmlComponent::_findProperty(const std::string& name, Logger::severity level)
{
    for (auto &property: *node) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR) {
        return nullptr;
    }
    throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': property named '" + name + "': not found.", Logger::MAJOR);
}

std::shared_ptr<myxmlpp::Node>
polymorph::engine::Config::XmlComponent::_findProperty(const std::string& name,
                                               const std::shared_ptr<myxmlpp::Node> &data, Logger::severity level)
{
    for (auto &property: *data) {
        try {
            auto attr = property->findAttribute("name");
            if (attr->getValue() == name)
                return property;
        } catch (...) {}
    }
    if (level != Logger::MAJOR) {
        return nullptr;
    }
    throw ConfigurationException("In property '"+data->getTag()+"': sub-property named '" + name + "': not found.", Logger::MAJOR);
}

bool polymorph::engine::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           int &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueInt();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            e.what();
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool polymorph::engine::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           float &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueFloat();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            e.what();
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool polymorph::engine::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
                                                           bool &toSet,
                                                           myxmlpp::Node &data,
                                                           Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValueBool();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            e.what();
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}

bool polymorph::engine::Config::XmlComponent::_setPropertyFromAttr(const std::string& name,
std::string &toSet, myxmlpp::Node &data, Logger::severity level)
{
    try {
        toSet = data.findAttribute(name)->getValue();
        return true;
    } catch (const myxmlpp::Exception &e) {
        if (level != Logger::MAJOR)
            e.what();
        else
            throw ConfigurationException(e.what(), Logger::MAJOR);
        return false;
    }
}
