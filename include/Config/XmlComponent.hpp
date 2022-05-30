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
    class TextModule;
    
    namespace Config
    {
        namespace CastHelper
        {
            template<class ...>
            using void_t = void;

            template<class T, class = void>
            struct is_container : std::false_type{};

            template<class T>
            struct is_container<T, void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type{};

            template<class T>
            static constexpr auto is_vector = CastHelper::is_container<T>::value;


            template<typename T, typename U = void>
            struct is_mappish_impl : std::false_type { };

            template<typename T>
            struct is_mappish_impl<T, 
                    void_t
                    <
                    typename T::key_type,
                    typename T::mapped_type,
                    decltype(std::declval<T&>()[std::declval<const typename T::key_type&>()])
                    >>
                    : std::true_type { };
            template<typename T>
            static constexpr auto is_map = CastHelper::is_mappish_impl<T>::value;
            
            template<typename T, typename U = void>
            struct is_shp_impl : std::false_type { };

            template<typename T>
            struct is_shp_impl<T, 
                    void_t<decltype(&T::operator*), decltype(&T::operator->)>
                    >
                    : std::true_type { };
            template<typename T>
            static constexpr auto is_sharedptr = CastHelper::is_shp_impl<T>::value;
            
            template<typename T, typename U = void>
            struct is_sp_impl : std::false_type { };

            template<typename T>
            struct is_sp_impl<T, 
                    void_t<decltype(&T::operator*), decltype(&T::operator->), decltype(&T::operator!)>
                    >
                    : std::true_type { };
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
                explicit XmlComponent(const std::shared_ptr<XmlNode> &node, GameObject entity = static_cast<GameObject>(nullptr));
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            public:
                const static inline std::shared_ptr<XmlComponent> Empty = std::make_shared<XmlComponent>(nullptr);
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
//                template<typename T, std::enable_if_t<!CastHelper::is_map<T>, int> = 0>
                template<typename T>
                void setProperty(const std::string& propertyName, T &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    if constexpr (std::is_enum<T>())
                        _setPrimitiveProperty<int>(property, reinterpret_cast<int &>(toSet), level);
                    else if constexpr (!std::is_enum<T>())
                        _setPrimitiveProperty<T>(property, toSet, level);
                };
                
//                template<typename T, std::enable_if_t<!CastHelper::is_map<T>, int> = 0>
                template<typename T>
                void setProperty(const std::string& propertyName, safe_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    _setRefProperty<T>(property, toSet, level);
                };
                template<typename T>
                void setProperty(const std::string& propertyName, std::shared_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    _setSharedProperty<T>(property, toSet, level);
                };

//                template<typename T, std::enable_if_t<!CastHelper::is_map<T>, int> = 0>
                template<typename T>
                void setProperty(const std::string& propertyName, std::vector<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    _setVectorProperty(property, toSet, level);
                };
                                
                template<typename T1, typename T2>
                void setProperty(const std::string& propertyName, std::map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    _setMapProperty<T1, T2>(property, toSet, level);
                };
                                
                template<typename T1, typename T2>
                void setProperty(const std::string& propertyName, std::unordered_map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, level);

                    if (property == nullptr)
                        return;
                    _setUMapProperty<T1, T2>(property, toSet, level);
                };










                template<typename T>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data, T &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    if constexpr (std::is_enum<T>())
                        _setPrimitiveProperty<int>(property, reinterpret_cast<int &>(toSet), level);
                    else if constexpr (!std::is_enum<T>())
                        _setPrimitiveProperty<T>(property, toSet, level);
                };                
                template<typename T>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data, std::shared_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    _setSharedProperty<T>(property, toSet, level);
                };
                
                template<typename T>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data,
                safe_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    _setRefProperty<T>(property, toSet, level);
                };

                template<typename T>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data,
                std::vector<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    static_assert(!CastHelper::is_map<T>);
                    _setVectorProperty<T>(property, toSet, level);
                };
                
                template<typename T1, typename T2>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data,
                std::map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    _setMapProperty<T1, T2>(property, toSet, level);
                };
                
                template<typename T1, typename T2>
                void setSubProperty(const std::string& propertyName, const std::shared_ptr<XmlNode> &data,
                std::unordered_map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    std::shared_ptr<XmlNode> property = _findProperty(propertyName, data, level);

                    if (property == nullptr)
                        return;
                    _setUMapProperty<T1, T2>(property, toSet, level);
                };

                
                
                
                
            private:
                template<typename T0, typename T1, typename T2>
                void _setMapPropertyFromNode(std::shared_ptr<XmlNode> &data, std::map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    static_assert(std::is_same<T0, typename std::map<T1, T2>>::value);
                    _setMapProperty(data, toSet, level);
                };

                template<typename T0, typename T1, typename T2>
                void _setMapPropertyFromNode(std::shared_ptr<XmlNode> &data, std::unordered_map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    static_assert(std::is_same<T0, typename std::unordered_map<T1, T2>>::value);
                    _setUMapProperty(data, toSet, level);
                };
                
                
                
                template<typename T, typename  T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, T &toSet, Logger::severity level = Logger::DEBUG)
                {
                    static_assert(!CastHelper::is_map<T> && !CastHelper::is_vector<T>
                    && !CastHelper::is_safeptr<T> && !std::is_enum<T>());
                    toSet = T(data, *this);
                };
                
                template<typename T, typename  T2 = void>
                void _setSharedProperty(std::shared_ptr<XmlNode> &data, std::shared_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    static_assert(!CastHelper::is_map<T> && !CastHelper::is_vector<T>
                    && !CastHelper::is_safeptr<T> && !std::is_enum<T>());
                    toSet = std::make_shared<T>(data, *this);
                };
                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, int &toSet, Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr("value", toSet, *data, level);
                }
                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, float &toSet, Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr("value", toSet, *data, level);
                }
                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, bool &toSet, Logger::severity level)
                {
                    _setPropertyFromAttr("value", toSet, *data, level);
                }
                template<typename T2 = void>
                void _setPrimitiveProperty(std::shared_ptr<XmlNode> &data, std::string &toSet, Logger::severity level)
                {
                    Polymorph::Config::XmlComponent::_setPropertyFromAttr("value", toSet, *data, level);
                }




                template<typename T, typename T2 = void>
                void _setRefProperty(std::shared_ptr<XmlNode> &refProp, safe_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    //static_assert(std::is_base_of_v<Component, T>);
                    if (refProp == nullptr)
                        return;
                    try {
                        auto id = refProp->findAttribute("id")->getValue();
                        GameObject gameObject;
                        if (!!entity && (entity->wasPrefab() || entity->isPrefab()))
                            gameObject = entity->findByPrefabId(id);
                        if (!gameObject)
                            gameObject = SceneManager::findById(id);
                        toSet = gameObject->getComponent<T>();
                        if (!toSet)
                            throw std::exception();
                    } catch (...) {
                        if (level != Logger::MAJOR)
                            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Ref named '" + refProp->findAttribute("name")->getValue() +
                                        "': has missing value or not found", level);
                        else
                            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Ref named '" + refProp->findAttribute("name")->getValue() +
                                                         "': has missing value or not found", Logger::MAJOR);
                    }
                };

                template<typename T2 = void>
                void _setRefProperty(std::shared_ptr<XmlNode> &refProp, GameObject &toSet, Logger::severity level)
                {
                    if (refProp == nullptr)
                        return;
                    try {
                        auto id = refProp->findAttribute("id")->getValue();
                        GameObject gameObject;
                        if (!!entity && (entity->wasPrefab() || entity->isPrefab()))
                            toSet = entity->findByPrefabId(id);
                        if (!gameObject)
                            toSet = SceneManager::findById(id);
                        if (!toSet)
                            throw std::exception();
                    } catch (...) {
                        if (level != Logger::MAJOR)
                            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': Ref named '" + refProp->findAttribute("name")->getValue() +
                                        "': has missing value or not found", level);
                        else
                            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': Ref named '" + refProp->findAttribute("name")->getValue() +
                                                         "': has missing value or not found", Logger::MAJOR);
                    }
                };

//                template<typename T, std::enable_if_t<!CastHelper::is_map<T>, int> = 0>
                template<typename T>
                void _setVectorProperty(std::shared_ptr<XmlNode> &data, std::vector<T> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem : *data)
                    {
                        if constexpr (CastHelper::is_map<T>)
                        {
                            T tmp;
                            _setMapPropertyFromNode(elem, tmp, level);
                            toSet.push_back(tmp);
                        }
                        if constexpr (CastHelper::is_safeptr<T>)
                        {
                            T tmp;
                            _setRefProperty(elem, tmp, level);
                            toSet.push_back(tmp);
                        }
                        if constexpr (CastHelper::is_sharedptr<T> && !CastHelper::is_safeptr<T>)
                        {
                            T tmp;
                            _setSharedProperty(elem, tmp, level);
                            toSet.push_back(tmp);
                        }
                        if constexpr (CastHelper::is_vector<T> && !std::is_same_v<T, std::string>)
                        {
                            T tmp;
                            _setVectorProperty(elem, tmp, level);
                            toSet.push_back(tmp);
                        }
                        if constexpr (!CastHelper::is_vector<T> 
                        && !CastHelper::is_safeptr<T> && !CastHelper::is_map<T>)
                        {
                            T tmp;
                            _setPrimitiveProperty(elem, tmp, level);
                            toSet.push_back(tmp);
                        }
                    }
                };
                
                
                template<typename T1, typename T2>
                void _setMapProperty(std::shared_ptr<XmlNode> &data, std::map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem : *data)
                    {
                        T1 key;
                        auto keyElem = elem->begin();
                        {
                            if constexpr (CastHelper::is_map<T1>)
                                _setMapPropertyFromNode(*keyElem, key, level);
                            if constexpr (CastHelper::is_safeptr<T1>)
                                _setRefProperty(*keyElem, key, level);
                            if constexpr (CastHelper::is_sharedptr<T1> && !CastHelper::is_safeptr<T1>)
                                _setSharedProperty(*keyElem, key, level);
                            if constexpr (CastHelper::is_vector<T1> && !std::is_same_v<T1, std::string>)
                                _setVectorProperty(*keyElem, key, level);
                            if constexpr (!CastHelper::is_vector<T1>
                            && !CastHelper::is_safeptr<T1> && !CastHelper::is_map<T1>)
                                _setPrimitiveProperty((*keyElem), key, level);
                        }
                        
                        auto valueElem = elem->begin() + 1;
                        T2 value;
                        {
                            if constexpr (CastHelper::is_map<T2>)
                                _setMapPropertyFromNode(*valueElem,
                                                        value, level);
                            if constexpr (CastHelper::is_safeptr<T2>)
                                _setRefProperty(*valueElem, value,
                                                level);
                            if constexpr (CastHelper::is_sharedptr<T2> && !CastHelper::is_safeptr<T2>)
                                _setSharedProperty(*valueElem, value, level);
                            if constexpr (CastHelper::is_vector<T2> && !std::is_same_v<T2, std::string>)
                                _setVectorProperty(*valueElem, value,
                                                   level);
                            if constexpr (! CastHelper::is_vector<T2>
                            && !CastHelper::is_safeptr<T2> && !CastHelper::is_map<T2>)
                                _setPrimitiveProperty(*valueElem, value,
                                                      level);
                        }
                        toSet.insert_or_assign(key, value);
                    }
                };

                template<typename T1, typename T2>
                void _setUMapProperty(std::shared_ptr<XmlNode> &data, std::unordered_map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
                {
                    for (auto &elem : *data)
                    {
                        T1 key;
                        auto keyElem = elem->begin();
                        auto valueElem = elem->begin() + 1;
                        T2 value;
                        {
                            if constexpr (CastHelper::is_map<T1>)
                                _setMapPropertyFromNode(*keyElem, key, level);
                            if constexpr (CastHelper::is_safeptr<T1>)
                                _setRefProperty(*keyElem, key, level);
                            if constexpr (CastHelper::is_sharedptr<T1> && !CastHelper::is_safeptr<T1>)
                                _setSharedProperty(*keyElem, key, level);
                            if constexpr (CastHelper::is_vector<T1> && !std::is_same_v<T1, std::string>)
                                _setVectorProperty(*keyElem, key, level);
                            if constexpr (!CastHelper::is_vector<T1>
                                          && !CastHelper::is_safeptr<T1> &&
                                          !CastHelper::is_map<T1>)
                                _setPrimitiveProperty(*keyElem, key, level);
                        }
                        {
                            if constexpr (CastHelper::is_map<T2>)
                                _setMapPropertyFromNode(*valueElem,
                                                        value, level);
                            if constexpr (CastHelper::is_safeptr<T2>)
                                _setRefProperty(*valueElem, value,
                                                level);
                            if constexpr (CastHelper::is_sharedptr<T2> && !CastHelper::is_safeptr<T2>)
                                _setSharedProperty(*valueElem, value, level);
                            if constexpr (CastHelper::is_vector<T2> && !std::is_same_v<T2, std::string>)
                                _setVectorProperty(*valueElem, value,
                                                   level);
                            if constexpr (! CastHelper::is_vector<T2>
                                          && ! CastHelper::is_safeptr<T2> &&
                                          ! CastHelper::is_map<T2>)
                                _setPrimitiveProperty(*valueElem, value,
                                                      level);
                        }
                        toSet.insert_or_assign(key, value);
                    }
                };

                /**
                * @defgroup SetPropertyList
                * @details A set of functions that takes a property List as parameter and adds elements in it based on the configuration file
                * @param propertyName the name of the property in config
                * @param toSet the List property to set
                * @warning propertyName as to be the exact same as the literal property name in the component !
                */

//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                //void setProperty(const std::string& propertyName, GameObject &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
////                void setProperty(const std::string& propertyName, Vector3 &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
////                void setProperty(const std::string& propertyName, Vector2 &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
////                void setProperty(const std::string& propertyName, Rect &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//
//
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                void setProperty(const std::string& propertyName, safe_ptr<SpriteModule> &toSet, Logger::severity level = Logger::DEBUG);
//
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                void setProperty(const std::string& propertyName, safe_ptr<TextModule> &toSet, Logger::severity level = Logger::DEBUG);
//
//
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(std::string propertyName, std::vector<Vector2> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(std::string propertyName, std::vector<Rect> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(const std::string& propertyName, std::vector<int> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(const std::string& propertyName, std::vector<float> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(const std::string& propertyName, std::vector<bool> &toSet, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                void setProperty(const std::string& propertyName, std::vector<std::string> &toSet, Logger::severity level = Logger::DEBUG);
//                
//                template<typename T1, typename  T2>
//                void setProperty(const std::string& propertyName, std::map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, level);
//
//                    if (refProp == nullptr)
//                        return;
//
//                    for (auto &elem : *refProp)
//                        toSet.insert(getPairProperty<T1, T2>(elem, level));
//                }
//                template<typename T1, typename  T2>
//                void setProperty(const std::string& propertyName, std::unordered_map<T1, T2> &toSet, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, level);
//
//                    if (refProp == nullptr)
//                        return;
//
//                    for (auto &elem : *refProp)
//                        toSet.insert(getPairProperty<T1, T2>(elem, level));
//                }
//                /**
//                 * @details , doesn't touch it if property is not found
//                 * @tparam T the type of the property to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
//                 * @param propertyName the name of the property in config
//                 * @param toSet the property to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//
//                /**
//                 * @details sets a property List by its name, doesn't touch it if property is not found
//                 * @tparam T the type of the properties Elements of the List to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
//                 * @param propertyName the name of the property in config
//                 * @param toSet the property List to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 **/
//                template<typename T>
//                void setProperty(const std::string& propertyName, std::vector<T> &toSet, Logger::severity level = Logger::DEBUG)
//                {
//                    auto propNode = _findProperty(propertyName, level);
//                    auto i = 0;
//
//                    if (propNode == nullptr)
//                        return;
//
//                    for (auto &element : *propNode) {
//                        try {
//                            toSet.emplace_back(element);
//                        } catch (...) {
//                            Logger::log("Property List of Templates named '" +
//                                    propertyName + "': Element nb "+std::to_string(i)+" has no value",
//                                    level);
//                        }
//                        ++i;
//                    }
//                };
//
//                /**
//                 * @details sets Component Reference by its property name, doesn't touch it if property is not found
//                 * @tparam T the type of the Component to set
//                 * @param propertyName the name of the property in config
//                 * @param toSet the Component Reference to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//                template<typename T>
//                void setProperty(const std::string& propertyName, safe_ptr<T> &toSet, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, level);
//
//                    if (refProp == nullptr)
//                        return;
//
//                    try {
//                        auto id = refProp->findAttribute("id")->getValue();
//                        auto gameObject = SceneManager::findById(id);
//                        auto comp = gameObject->getComponent<T>();
//
//                        if (!comp)
//                            throw std::exception();
//                        toSet = comp;
//                    } catch (...) {
//                        if (level != Logger::MAJOR)
//                            Logger::log("In component '"+node->findAttribute("type")->getValue()+"': ComponentRef named '" + propertyName +
//                                        "': has missing value or not found", level);
//                        else
//                            throw ConfigurationException("In component '"+node->findAttribute("type")->getValue()+"': ComponentRef named '" + propertyName +
//                                                         "': has missing value or not found", Logger::MAJOR);
//                    }
//                };   
//
//                /**
//                 * @details sets a List of Component Reference by its property name, doesn't touch it if property is not found
//                 * @tparam T the type of the Components in the List to set
//                 * @param propertyName the name of the property List in config
//                 * @param toSet the Component Reference List to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//                template<typename T>
//                void setProperty(const std::string& propertyName, std::vector<safe_ptr<T>> &toSet, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, level);
//                    auto i = 0;
//
//                    if (refProp == nullptr)
//                        return;
//
//                    for (auto &elem : *refProp) {
//                        try {
//                            auto id = elem->findAttribute("id")->getValue();
//                            auto gameObject = SceneManager::findById(id);
//                            auto comp = gameObject->getComponent<T>();
//
//                            if (!comp)
//                                throw;
//                            toSet.push_back(comp);
//                        } catch (...) {
//                            Logger::log("Property Component ref nb :" +
//                                        std::to_string(i) +
//                                        ", in list named '" + propertyName +
//                                        "': has no value", Logger::DEBUG);
//                        }
//                        ++i;
//                    }
//                };
//
//                /**
//                 * @details sets a List of GameObject References by its property name, doesn't touch it if property is not found
//                 * @param propertyName the name of the property List in config
//                 * @param toSet the GameObject Reference List to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//                void setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, Logger::severity level = Logger::DEBUG);
//



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

//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, GameObject &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, Vector3 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, Vector2 &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, Rect &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, int &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, float &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, bool &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertySimple
//                 */
//                static void setProperty(const std::string& propertyName, std::string &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//
//
//
//
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(const std::string& propertyName, std::vector<Vector3> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(std::string propertyName, std::vector<Vector2> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(std::string propertyName, std::vector<Rect> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(const std::string& propertyName, std::vector<int> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(const std::string& propertyName, std::vector<float> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(const std::string& propertyName, std::vector<bool> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//                /**
//                 * @ingroup SetPropertyList
//                 */
//                static void setProperty(const std::string& propertyName, std::vector<std::string> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
//
//                static void setProperty(const std::string& propertyName, std::vector<GameObject> &toSet, std::shared_ptr<XmlNode> &data, Logger::severity level = Logger::DEBUG);
//                
//                template<typename T1, typename  T2>
//                static void setProperty(const std::string& propertyName, std::map<T1, T2> &toSet, std::shared_ptr<XmlNode> &data, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, data, level);
//
//                    if (refProp == nullptr)
//                        return;
//
//                    for (auto &elem : *refProp)
//                        toSet.insert_or_assign(getPairProperty<T1, T2>(elem, level));
//                }
//                template<typename T1, typename  T2>
//                static void setProperty(const std::string& propertyName, std::unordered_map<T1, T2> &toSet, std::shared_ptr<XmlNode> &data, Logger::severity level = Logger::DEBUG)
//                {
//                    auto refProp = _findProperty(propertyName, data, level);
//
//                    if (refProp == nullptr)
//                        return;
//
//                    for (auto &elem : *refProp)
//                        toSet.insert_or_assign(getPairProperty<T1, T2>(elem, level));
//                }
//
//                /**
//                 * @details , doesn't touch it if property is not found
//                 * @tparam T the type of the property to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
//                 * @param propertyName the name of the property in config
//                 * @param toSet the property to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//                template<typename T>
//                static void setProperty(std::string propertyName, T &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG)
//                {
//                    std::shared_ptr<XmlNode> property = _findProperty(std::move(propertyName), data, level);
//
//                    if (property == nullptr)
//                        return;
//
//                    toSet = T(property);
//                };
//
//                /**
//                 * @details sets a property List by its name, doesn't touch it if property is not found
//                 * @tparam T the type of the properties Elements of the List to set, it's type can be an unknown type class as long as its constructor can take an xml node to construct the object
//                 * @param propertyName the name of the property in config
//                 * @param toSet the property List to set
//                 * @warning propertyName as to be the exact same as the literal property name in the component !
//                 */
//                template<typename T>
//                static void setProperty(std::string propertyName, std::vector<T> &toSet, std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG)
//                {
//                    auto propNode = _findProperty(propertyName, data, level);
//
//                    if (propNode == nullptr)
//                        return;
//
//                    for (auto &element : *propNode) {
//                        try {
//                            toSet.emplace_back(element);
//                        } catch (...) {
//                            Logger::log("Property List of Templates named '" +
//                                        propertyName + "': has no value",
//                                        Logger::DEBUG);
//                        }
//                    }
//                }; 
            private:
                /**
                 * @details Searches a property by its attribute 'name' in the component node
                 * @param name the value of the attribute called 'name' in the property node to find
                 * @return the node found (nullptr if not found)
                 */
                std::shared_ptr<XmlNode> _findProperty(const std::string& name, Logger::severity level = Logger::DEBUG);
                static std::shared_ptr<XmlNode> _findProperty(const std::string& name, const std::shared_ptr<myxmlpp::Node> &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, int &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, float &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, bool &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
                static bool _setPropertyFromAttr(const std::string& name, std::string &toSet, myxmlpp::Node &data, Logger::severity level = Logger::DEBUG);
//////////////////////--------------------------/////////////////////////

        };
    }
}

#endif //ENGINE_XMLCOMPONENT_HPP
