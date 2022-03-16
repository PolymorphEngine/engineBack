/*
** EPITECH PROJECT, 2022
** PhysicsSettings.cpp
** File description:
** PhysicsSettings.cpp
*/


#include "PhysicsSettings.hpp"
#include "Log/Logger.hpp"

Polymorph::Settings::PhysicsSettings::PhysicsSettings(
        const std::shared_ptr<XmlNode>& node)
{
    _init2DGravity(node);
    _init3DGravity(node);
}

void Polymorph::Settings::PhysicsSettings::_init2DGravity(
        const std::shared_ptr<XmlNode>& node)
{
    try {
        auto gravNode = node->findChild("Gravity2D");

        _2DGravity.x = gravNode->findAttribute("x")->getValueFloat();
        _2DGravity.y = gravNode->findAttribute("y")->getValueFloat();
    } catch (const myxmlpp::NodeNotFoundException &e) {
        Logger::Log("Gravity2D setting not found", Logger::DEBUG);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Gravity2D setting is incomplete", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        Logger::Log("Gravity2D setting is malformated", Logger::MINOR);
        //TODO think of log level
    }
}

void Polymorph::Settings::PhysicsSettings::_init3DGravity(
        const std::shared_ptr<XmlNode>& node)
{
    try {
        auto gravNode = node->findChild("Gravity3D");

        _3DGravity.x = gravNode->findAttribute("x")->getValueFloat();
        _3DGravity.y = gravNode->findAttribute("y")->getValueFloat();
        _3DGravity.z = gravNode->findAttribute("z")->getValueFloat();
    } catch (const myxmlpp::NodeNotFoundException &e) {
        Logger::Log("Gravity3D setting not found", Logger::DEBUG);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Gravity3D setting is incomplete", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        Logger::Log("Gravity3D setting is malformated", Logger::MINOR);
        //TODO think of log level
    }
}

Polymorph::Vector2 Polymorph::Settings::PhysicsSettings::getGravity2D() {
    return _2DGravity;
}

Polymorph::Vector3 Polymorph::Settings::PhysicsSettings::getGravity3D() {
    return _3DGravity;
}
