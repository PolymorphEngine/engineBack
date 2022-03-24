/*
** EPITECH PROJECT, 2020
** XmlComponent.hpp.h
** File description:
** header for XmlComponent.c
*/

#ifndef ENGINE_XMLCOMPONENT_HPP
#define ENGINE_XMLCOMPONENT_HPP

#include <utility>
#include <vector>
#include <iostream>
#include <memory>
#include <myxmlpp.hpp>
#include "Utilities/safe_ptr.hpp"

#include "Core/scene/SceneManager.hpp"
#include "Log/Logger.hpp"
#include "Core/entity/Entity.hpp"
#include "ConfigurationException.hpp"

namespace Polymorph
{
    class Scene;
    class Rect;
    class Vector2;
    class Vector3;
    class Entity;
    class SpriteModule;
    class TextModule;

    namespace Config
    {
        using XmlNode = myxmlpp::Node;

        /**
         * @class XmlComponent The class that interfaces a Component Xml Node
         * and the actual Component
         * inside the engine.
         */
        class XmlComponent
        {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            public:
                explicit XmlComponent(const std::shared_ptr<XmlNode> &node = nullptr);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            public:
                const static inline std::shared_ptr<XmlComponent> Empty = std::make_shared<XmlComponent>(nullptr);
            private:
                /**
                 * @property node which contains all data needed to load the binded component.
                 */
                std::shared_ptr<XmlNode> node = nullptr;

                /**
                 * @property the type of the component
                 */
                std::string type = "Empty";
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            public:

                /**
                 * @details Looks for the initial state of the component in the config
                 * @return the component enable state
                 */
                bool isEnabled();

                /**
                 * @details Looks for the component type in the component's config file
                 * @return The type of the component
                 */
                std::string getType();


                /**
                * @defgroup SetPropertySimple
                * @details A set of functions that takes a property as parameter and set its value with the configuration file
                * @param propertyName the name of the property in config
                * @param toSet the property to set
                * @warning propertyName as to be the exact same as the literal property name in the component !
                */

                /**
                * @defgroup SetPropertyList
                * @details A set of functions that takes a property List as parameter and adds elements in it based on the configuration file
                * @param propertyName the name of the property in config
                * @param toSet the List property to set
                * @warning propertyName as to be the exact same as the literal property name in the component !
                */

                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, GameObject &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, Vector3 &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, Vector2 &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, Rect &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, int &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, float &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, bool &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, std::string &toSet, Logger::severity level = Logger::DEBUG);

                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, safe_ptr<SpriteModule> &toSet, Logger::severity level = Logger::DEBUG);

                /**
                 * @ingroup SetPropertySimple
                 */
                void setProperty(const std::string& propertyName, safe_ptr<TextModule> &toSet, Logger::severity level = Logger::DEBUG);


                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(std::string propertyName, std::vector<Vector2> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(std::string propertyName, std::vector<Rect> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(const std::string& propertyName, std::vector<int> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(const std::string& propertyName, std::vector<float> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(const std::string& propertyName, std::vector<bool> &toSet, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                void setProperty(const std::string& propertyName, std::vector<std::string> &toSet, Logger::severity level = Logger::DEBUG);


                /**
                 * @details , doesn't touch it if property is not found
                 * @tparam T the type of the property to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
                 * @param propertyName the name of the property in config
                 * @param toSet the property to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                void setProperty(std::string propertyName, T &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(std::move(propertyName), level);

                    if (property == nullptr)
                        return;

                    toSet = T(property);
                };

                /**
                 * @details sets a property List by its name, doesn't touch it if property is not found
                 * @tparam T the type of the properties Elements of the List to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
                 * @param propertyName the name of the property in config
                 * @param toSet the property List to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                void setProperty(const std::string& propertyName, std::vector<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    auto propNode = _findProperty(propertyName, level);
                    auto i = 0;

                    if (propNode == nullptr)
                        return;

                    for (auto &element : *propNode) {
                        try {
                            toSet.emplace_back(element);
                        } catch (...) {
                            Logger::log("Property List of Templates named '" +
                                    propertyName + "': Element nb "+std::to_string(i)+" has no value",
                                    level);
                        }
                        ++i;
                    }
                };

                /**
                 * @details sets Component Reference by its property name, doesn't touch it if property is not found
                 * @tparam T the type of the Component to set
                 * @param propertyName the name of the property in config
                 * @param toSet the Component Reference to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                void setProperty(const std::string& propertyName, safe_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    auto refProp = _findProperty(propertyName, level);

                    if (refProp == nullptr)
                        return;

                    try {
                        auto id = refProp->findAttribute("id")->getValue();
                        auto gameObject = SceneManager::findById(id);
                        auto comp = gameObject->getComponent<T>();

                        if (!comp)
                            throw;
                        toSet = comp;
                    } catch (...) {
                        if (level != Logger::MAJOR)
                            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': ComponentRef named '" + propertyName +
                                        "': has missing value or not found", level);
                        else
                            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': ComponentRef named '" + propertyName +
                                                         "': has missing value or not found", Logger::MAJOR);
                    }
                }

                /**
                 * @details sets a List of Component Reference by its property name, doesn't touch it if property is not found
                 * @tparam T the type of the Components in the List to set
                 * @param propertyName the name of the property List in config
                 * @param toSet the Component Reference List to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                void setProperty(const std::string& propertyName, std::vector<safe_ptr<T>> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    auto refProp = _findProperty(propertyName, level);
                    auto i = 0;

                    if (refProp == nullptr)
                        return;

                    for (auto &elem : *refProp) {
                        try {
                            auto id = refProp->findAttribute("id")->getValue();
                            auto gameObject = SceneManager::findById(id);
                            auto comp = gameObject->getComponent<T>();

                            if (!comp)
                                throw;
                            toSet.push_back(comp);
                        } catch (...) {
                            Logger::log("Property Component ref nb :" +
                                        std::to_string(i) +
                                        ", in list named '" + propertyName +
                                        "': has no value", Logger::DEBUG);
                        }
                        ++i;
                    }
                };

                /**
                 * @details sets a List of GameObject References by its property name, doesn't touch it if property is not found
                 * @param propertyName the name of the property List in config
                 * @param toSet the GameObject Reference List to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                void setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, Logger::severity level = Logger::DEBUG);




//////////////////////------------STATICS-----------------/////////////////////////

                /**
                 * @defgroup Static_SetPropertySimple
                 * @details A set of functions that takes a property as parameter and set its value with the configuration file
                 * @param propertyName the name of the property in config
                 * @param toSet the property to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */

                /**
                * @defgroup Static_SetPropertyList
                * @details A set of functions that takes a property List as parameter and adds elements in it based on the configuration file
                * @param propertyName the name of the property in config
                * @param toSet the List property to set
                * @param data the node of the templated property property to set
                * @warning propertyName as to be the exact same as the literal property name in the component !
                */

                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, GameObject &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, Vector3 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, Vector2 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, Rect &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, int &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, float &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, bool &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertySimple
                 */
                static void setProperty(const std::string& propertyName, std::string &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);




                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(std::string propertyName, std::vector<Vector2> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(std::string propertyName, std::vector<Rect> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(const std::string& propertyName, std::vector<int> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(const std::string& propertyName, std::vector<float> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(const std::string& propertyName, std::vector<bool> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                /**
                 * @ingroup SetPropertyList
                 */
                static void setProperty(const std::string& propertyName, std::vector<std::string> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);

                static void setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, std::shared_ptr<XmlNode> &data, Logger::severity level = Logger::DEBUG);


                /**
                 * @details , doesn't touch it if property is not found
                 * @tparam T the type of the property to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
                 * @param propertyName the name of the property in config
                 * @param toSet the property to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                static void setProperty(std::string propertyName, T &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(std::move(propertyName), data, level);

                    if (property == nullptr)
                        return;

                    toSet = T(property);
                };

                /**
                 * @details sets a property List by its name, doesn't touch it if property is not found
                 * @tparam T the type of the properties Elements of the List to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
                 * @param propertyName the name of the property in config
                 * @param toSet the property List to set
                 * @warning propertyName as to be the exact same as the literal property name in the component !
                 */
                template<typename T>
                static void setProperty(std::string propertyName, std::vector<T> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG)
                {
                    auto propNode = _findProperty(propertyName, data, level);

                    if (propNode == nullptr)
                        return;

                    for (auto &element : *propNode) {
                        try {
                            toSet.emplace_back(element);
                        } catch (...) {
                            Logger::log("Property List of Templates named '" +
                                        propertyName + "': has no value",
                                        Logger::DEBUG);
                        }
                    }
                };
            private:
                /**
                 * @details Searches a property by its attribute 'name' in the component node
                 * @param name the value of the attribute called 'name' in the property node to find
                 * @return the node found (nullptr if not found)
                 */
                std::shared_ptr<XmlNode> _findProperty(const std::string& name, Logger::severity level = Logger::DEBUG);
                static std::shared_ptr<XmlNode> _findProperty(const std::string& name, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, int &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, float &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, bool &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, std::string &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
//////////////////////--------------------------/////////////////////////

        };
    }
}

#endif //ENGINE_XMLCOMPONENT_HPP
