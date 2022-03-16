/*
** EPITECH PROJECT, 2022
** PhysicsSettings.cpp
** File description:
** PhysicsSettings.cpp
*/


#include "PhysicsSettings.hpp"
#include "Log/Logger.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"

Polymorph::Settings::PhysicsSettings::PhysicsSettings(
        const std::shared_ptr<XmlNode>& node)
        : _node(node)
{
    _init2DGravity();
    _init3DGravity();
}

void Polymorph::Settings::PhysicsSettings::_init2DGravity()
{
    try {
        auto gravNode = _node->findChild("Gravity2D");

        _2DGravity.x = gravNode->findAttribute("x")->getValueFloat();
        _2DGravity.y = gravNode->findAttribute("y")->getValueFloat();
    } catch (const myxmlpp::NodeNotFoundException &e) {
        Logger::Log("Gravity2D setting not found", Logger::DEBUG);
        _createDefault2DGrav();
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Gravity2D setting is incomplete", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Gravity2D setting is malformed");
    }
}

void Polymorph::Settings::PhysicsSettings::_init3DGravity()
{
    try {
        auto gravNode = _node->findChild("Gravity3D");

        _3DGravity.x = gravNode->findAttribute("x")->getValueFloat();
        _3DGravity.y = gravNode->findAttribute("y")->getValueFloat();
        _3DGravity.z = gravNode->findAttribute("z")->getValueFloat();
    } catch (const myxmlpp::NodeNotFoundException &e) {
        Logger::Log("Gravity3D setting not found", Logger::DEBUG);
        _createDefault3DGrav();
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Gravity3D setting is incomplete", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Gravity3D setting is malformed");
    }
}

Polymorph::Vector2 Polymorph::Settings::PhysicsSettings::getGravity2D() {
    return _2DGravity;
}

Polymorph::Vector3 Polymorph::Settings::PhysicsSettings::getGravity3D() {
    return _3DGravity;
}

void
Polymorph::Settings::PhysicsSettings::setGravity2D(Polymorph::Vector2 newGrav)
{
    _2DGravity = newGrav;
    std::shared_ptr<XmlNode> gravNode;

    try {
        gravNode = _node->findChild("Gravity2D");
    } catch (const myxmlpp::NodeNotFoundException &e) {
        throw ConfigurationException("Cannot find gravity XML node, save failed");
    }
    _saveToAttribute(gravNode, "2D", "x", newGrav.x);
    _saveToAttribute(gravNode, "2D", "y", newGrav.y);
}

void Polymorph::Settings::PhysicsSettings::setGravity2D(float newYGrav)
{
    _2DGravity.y = newYGrav;

    try {
        _saveToAttribute(_node->findChild("Gravity2D"), "2D", "y", newYGrav);
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException("Cannot find Gravity2D node", Logger::MAJOR);
    }
}

void
Polymorph::Settings::PhysicsSettings::setGravity3D(Polymorph::Vector3 newGrav)
{
    _3DGravity = newGrav;
    std::shared_ptr<XmlNode> gravNode;

    try {
        gravNode = _node->findChild("Gravity2D");
    } catch (const myxmlpp::NodeNotFoundException &e) {
        throw ConfigurationException("Cannot find gravity XML node, save failed");
    }
    _saveToAttribute(gravNode, "3D", "x", newGrav.x);
    _saveToAttribute(gravNode, "3D", "y", newGrav.y);
    _saveToAttribute(gravNode, "3D", "z", newGrav.z);

}

void Polymorph::Settings::PhysicsSettings::setGravity3D(float newZGrav)
{
    _3DGravity.z = newZGrav;

    try {
        _saveToAttribute(_node->findChild("Gravity3D"), "3D", "z", newZGrav);
    } catch (myxmlpp::Exception &e) {
        throw ConfigurationException("Cannot find Gravity3D node", Logger::MAJOR);
    }
}

void Polymorph::Settings::PhysicsSettings::_createDefault2DGrav() {
    auto grav = std::make_shared<XmlNode>(*_node);
    grav->setTag("Gravity2D");
    grav->addAttribute("x", "0");
    grav->addAttribute("y", "-9.81");
    _node->addChild(grav);
}

void Polymorph::Settings::PhysicsSettings::_createDefault3DGrav() {
    auto grav = std::make_shared<XmlNode>(*_node);
    grav->setTag("Gravity3D");
    grav->addAttribute("x", "0");
    grav->addAttribute("y", "0");
    grav->addAttribute("z", "-9.81");
    _node->addChild(grav);
}

void Polymorph::Settings::PhysicsSettings::_saveToAttribute(
        const std::shared_ptr<XmlNode> &node,
        const std::string &dimension,
        const std::string &attrName,
        float value)
{
    try {
        node->findAttribute(attrName)->setValueFloat(value);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        throw ConfigurationException("Failed to save xml data [Physics Settings " + dimension + ": " + attrName + "]"+ e.baseWhat(), Logger::MAJOR);
    }
}
