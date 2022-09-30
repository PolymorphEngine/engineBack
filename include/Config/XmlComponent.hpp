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
#include "Exceptions/ConfigurationException.hpp"

namespace Polymorph
{
    class Scene;

    class Rect;

    class Vector2;

    class Vector3;

    class Entity;

    class SpriteModule;

    class arcadeTextModule;

    namespace Config
    {
        namespace CastHelper
        {
            template<class ...>
            using void_t = void;

            template<class T, class = void>
            struct is_container : std::false_type
            {
            };

            template<class T>
            struct is_container<T, void_t<decltype(std::begin(
                    std::declval<T>())), decltype(std::end(std::declval<T>()))>>
                    : std::true_type
            {
            };

            template<class T>
            static constexpr auto is_vector = CastHelper::is_container<T>::value;

            template<typename T, typename U = void>
            struct is_mappish_impl : std::false_type
            {
            };

            template<typename T>
            struct is_mappish_impl<T,
                    void_t
                            <
                                    typename T::key_type,
                                    typename T::mapped_type,
                                    decltype(std::declval<T &>()[std::declval<const typename T::key_type &>()])
                            >>
                    : std::true_type
            {
            };
            template<typename T>
            static constexpr auto is_map = CastHelper::is_mappish_impl<T>::value;

            template<typename T, typename U = void>
            struct is_shp_impl : std::false_type
            {
            };

            template<typename T>
            struct is_shp_impl<T,
                    void_t<decltype(&T::operator*), decltype(&T::operator->)>
            >
                    : std::true_type
            {
            };
            template<typename T>
            static constexpr auto is_sharedptr = CastHelper::is_shp_impl<T>::value;

            template<typename T, typename U = void>
            struct is_sp_impl : std::false_type
            {
            };

            template<typename T>
            struct is_sp_impl<T,
                    void_t<decltype(&T::operator*), decltype(&T::operator->), decltype(&T::operator!)>
            >
                    : std::true_type
            {
            };
            template<typename T>
            static constexpr auto is_safeptr = CastHelper::is_sp_impl<T>::value;
        };

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
                explicit XmlComponent(const std::shared_ptr<XmlNode> &node,
                                      GameObject entity = static_cast<GameObject>(nullptr));
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            public:
                const static inline std::shared_ptr<XmlComponent> Empty = std::make_shared<XmlComponent>(
                        nullptr);
            private:
                /**
                 * @property node which contains all data needed to load the binded component.
                 */
                std::shared_ptr<XmlNode> node = nullptr;
                GameObject entity;

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


            public:


                //Name Version
                template<typename T>
                void setProperty(const std::string &propertyName, T &toSet,
                                 Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    if constexpr (std::is_enum<T>())
                        _setPrimitiveProperty<int>(property,
                                                   reinterpret_cast<int &>(toSet),
                                                   level);
                    else if constexpr (! std::is_enum<T>())
                        _setPrimitiveProperty<T>(property, toSet, level);
                };

                template<typename T>
                void
                setProperty(const std::string &propertyName, safe_ptr<T> &toSet,
                            Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    _setRefProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setProperty(const std::string &propertyName,
                                 std::shared_ptr<T> &toSet,
                                 Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    _setSharedProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setProperty(const std::string &propertyName,
                                 std::vector<T> &toSet,
                                 Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    _setVectorProperty(property, toSet, level);
                };

                template<typename T1, typename T2>
                void setProperty(const std::string &propertyName,
                                 std::map<T1, T2> &toSet,
                                 Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    _setMapProperty<T1, T2>(property, toSet, level);
                };

                template<typename T1, typename T2>
                void setProperty(const std::string &propertyName,
                                 std::unordered_map<T1, T2> &toSet,
                                 Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(
                            propertyName, level);

                    if (property == nullptr)
                        return;
                    _setUMapProperty<T1, T2>(property, toSet, level);
                };


                template<typename T>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    T &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    if constexpr (std::is_enum<T>())
                        _setPrimitiveProperty<int>(property,
                                                   reinterpret_cast<int &>(toSet),
                                                   level);
                    else if constexpr (! std::is_enum<T>())
                        _setPrimitiveProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    std::shared_ptr<T> &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    _setSharedProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    safe_ptr<T> &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    _setRefProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    std::vector<T> &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    static_assert(! CastHelper::is_map<T>);
                    _setVectorProperty<T>(property, toSet, level);
                };

                template<typename T1, typename T2>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    std::map<T1, T2> &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    _setMapProperty<T1, T2>(property, toSet, level);
                };

                template<typename T1, typename T2>
                void setSubProperty(const std::string &propertyName,
                                    const std::shared_ptr<XmlNode> &data,
                                    std::unordered_map<T1, T2> &toSet,
                                    Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = (propertyName != "")
                                                        ? _findProperty(
                                    propertyName, data, level) : data;

                    if (property == nullptr)
                        return;
                    _setUMapProperty<T1, T2>(property, toSet, level);
                };


            private:
                template<typename T0, typename T1, typename T2>
                void _setMapPropertyFromNode(std::shared_ptr<XmlNode> &data,
                                             std::map<T1, T2> &toSet,
                                             Logger::severity level = Logger::DEBUG)
                {
                    static_assert(
                            std::is_same<T0, typename std::map<T1, T2>>::value);
                    _setMapProperty(data, toSet, level);
                };

                template<typename T0, typename T1, typename T2>
                void _setMapPropertyFromNode(std::shared_ptr<XmlNode> &data,
                                             std::unordered_map<T1, T2> &toSet,
                                             Logger::severity level = Logger::DEBUG)
                {
                    static_assert(
                            std::is_same<T0, typename std::unordered_map<T1, T2>>::value);
                    _setUMapProperty(data, toSet, level);
                };


                template<typename T, typename T2 = void>
                void
                _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, T &toSet,
                                      Logger::severity level = Logger::DEBUG)
                {
                    static_assert(! CastHelper::is_map<T> &&
                                  ! CastHelper::is_vector<T>
                                  && ! CastHelper::is_safeptr<T> &&
                                  ! std::is_enum<T>());
                    toSet = T(data, *this);
                };

                template<typename T, typename T2 = void>
                void _setSharedProperty(std::shared_ptr<XmlNode> &data,
                                        std::shared_ptr<T> &toSet,
                                        Logger::severity level = Logger::DEBUG)
                {
                    static_assert(! CastHelper::is_map<T> &&
                                  ! CastHelper::is_vector<T>
                                  && ! CastHelper::is_safeptr<T> &&
                                  ! std::is_enum<T>());
                    toSet = std::make_shared<T>(data, *this);
                };

                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data,
                                           int &toSet, Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr(
                            "value", toSet, *data, level);
                }

                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data,
                                           float &toSet, Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr(
                            "value", toSet, *data, level);
                }

                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data,
                                           bool &toSet, Logger::severity level)
                {
                    _setPropertyFromAttr("value", toSet, *data, level);
                }

                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data,
                                           std::string &toSet,
                                           Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr(
                            "value", toSet, *data, level);
                }

                template<typename T, typename T2 = void>
                void _setRefProperty(std::shared_ptr<XmlNode> &refProp,
                                     safe_ptr<T> &toSet,
                                     Logger::severity level = Logger::DEBUG)
                {
                    if (refProp == nullptr)
                        return;
                    try
                    {
                        auto id = refProp->findAttribute("id")->getValue();
                        GameObject gameObject;
                        if (! ! entity && (entity->getPrefabId() == id ||
                                           entity->getId() == id))
                            gameObject = entity;
                        if (! gameObject && ! ! entity)
                            gameObject = entity->findByPrefabId(id);
                        if (! gameObject)
                            gameObject = SceneManager::findById(id);
                        if (! ! gameObject)
                            toSet = gameObject->getComponent<T>();
                        if (! toSet)
                            throw std::exception();
                    } catch (...)
                    {
                        if (level != Logger::MAJOR)
                            Logger::log("In component '" + node->findAttribute(
                                                "type")->getValue() + "': Ref named '" +
                                        refProp->findAttribute(
                                                "name")->getValue() +
                                        "': has missing value or not found",
                                        level);
                        else
                            throw ConfigurationException("In component '" +
                                                         node->findAttribute(
                                                                 "type")->getValue() +
                                                         "': Ref named '" +
                                                         refProp->findAttribute(
                                                                 "name")->getValue() +
                                                         "': has missing value or not found",
                                                         Logger::MAJOR);
                    }
                };

                template<typename T2 = void>
                void _setRefProperty(std::shared_ptr<XmlNode> &refProp,
                                     GameObject &toSet, Logger::severity level)
                {
                    if (refProp == nullptr)
                        return;
                    try
                    {
                        auto id = refProp->findAttribute("id")->getValue();
                        if (! ! entity && (entity->getPrefabId() == id ||
                                           entity->getId() == id))
                            toSet = entity;
                        if (! toSet && ! ! entity)
                            toSet = entity->findByPrefabId(id);
                        if (! toSet)
                            toSet = SceneManager::findById(id);
                        if (! toSet)
                            throw std::exception();
                    } catch (...)
                    {
                        if (level != Logger::MAJOR)
                            Logger::log("In component '" + node->findAttribute(
                                                "type")->getValue() + "': Ref named '" +
                                        refProp->findAttribute(
                                                "name")->getValue() +
                                        "': has missing value or not found",
                                        level);
                        else
                            throw ConfigurationException("In component '" +
                                                         node->findAttribute(
                                                                 "type")->getValue() +
                                                         "': Ref named '" +
                                                         refProp->findAttribute(
                                                                 "name")->getValue() +
                                                         "': has missing value or not found",
                                                         Logger::MAJOR);
                    }
                };

                template<typename T>
                void _setVectorProperty(std::shared_ptr<XmlNode> &data,
                                        std::vector<T> &toSet,
                                        Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem: *data)
                    {
                        T tmp;

                        setSubProperty("", elem, tmp, level);
                        toSet.push_back(tmp);
                    }
                };


                template<typename T1, typename T2>
                void _setMapProperty(std::shared_ptr<XmlNode> &data,
                                     std::map<T1, T2> &toSet,
                                     Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem: *data)
                    {
                        T1 key;
                        auto keyElem = elem->begin();
                        T2 value;
                        auto valueElem = elem->begin() + 1;
                        setSubProperty("", *keyElem, key, level);
                        setSubProperty("", *valueElem, value, level);
                        toSet.insert_or_assign(key, value);
                    }
                };

                template<typename T1, typename T2>
                void _setUMapProperty(std::shared_ptr<XmlNode> &data,
                                      std::unordered_map<T1, T2> &toSet,
                                      Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem: *data)
                    {
                        T1 key;
                        auto keyElem = elem->begin();
                        auto valueElem = elem->begin() + 1;
                        T2 value;
                        setSubProperty("", *keyElem, key, level);
                        setSubProperty("", *valueElem, value, level);
                        toSet.emplace(key, value);
                    }
                };
            private:
                /**
                 * @details Searches a property by its attribute 'name' in the component node
                 * @param name the value of the attribute called 'name' in the property node to find
                 * @return the node found (nullptr if not found)
                 */
                std::shared_ptr<XmlNode> _findProperty(const std::string &name,
                                                       Logger::severity level = Logger::DEBUG);

                static std::shared_ptr<XmlNode>
                _findProperty(const std::string &name,
                              const std::shared_ptr<myxmlpp::Node> &data,
                              Logger::severity level = Logger::DEBUG);

                static bool
                _setPropertyFromAttr(const std::string &name, int &toSet,
                                     myxmlpp::Node &data,
                                     Logger::severity level = Logger::DEBUG);

                static bool
                _setPropertyFromAttr(const std::string &name, float &toSet,
                                     myxmlpp::Node &data,
                                     Logger::severity level = Logger::DEBUG);

                static bool
                _setPropertyFromAttr(const std::string &name, bool &toSet,
                                     myxmlpp::Node &data,
                                     Logger::severity level = Logger::DEBUG);

                static bool _setPropertyFromAttr(const std::string &name,
                                                 std::string &toSet,
                                                 myxmlpp::Node &data,
                                                 Logger::severity level = Logger::DEBUG);
//////////////////////--------------------------/////////////////////////

        };
    }
}

#endif //ENGINE_XMLCOMPONENT_HPP
