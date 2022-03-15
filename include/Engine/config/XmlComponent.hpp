/*
** EPITECH PROJECT, 2020
** XmlComponent.hpp.h
** File description:
** header for XmlComponent.c
*/

#ifndef ENGINE_XMLCOMPONENT_HPP
#define ENGINE_XMLCOMPONENT_HPP

#include <vector>
#include <iostream>
#include <memory>
#include "safe_ptr.hpp"
#include "Node.hpp"
#include "SceneManager.hpp"
#include "Log/Logger.hpp"
#include "Entity.hpp"
#include "Scene.hpp"

namespace Polymorph
{

    class Scene;
    class Entity;
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
            public:
                explicit XmlComponent(std::shared_ptr<XmlNode> node);
                
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
                
                
                template<typename T>
                void setProperty(std::string propertyName, T &toSet)
                {
                    
                };
                
                template<typename T>
                void setProperty(std::string propertyName, std::vector<T> &toSet)
                {
                    
                };

                template<typename T>
                void setProperty(std::string propertyName, std::vector<safe_ptr<T>> &toSet)
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
                            auto gameObject = SceneManager::Current->findById(id);
                            auto comp = gameObject->GetComponent<T>();

                            if (!comp)
                                throw;
                            toSet.push_back(comp);
                        }
                        catch (...)
                        {
                            Logger::Log("Property Component ref nb :"+std::to_string(i)+", in list named '" +propertyName+ "': has no value", Logger::DEBUG);
                        }
                        ++i;
                    }
                };
                void setProperty(std::string propertyName, std::vector<GameObject> &toSet)
                {
                    auto refProp = findProperty(propertyName);
                    auto i = 0;

                    if (refProp == nullptr)
                        return;

                    for (auto &elem : *refProp)
                    {
                        try
                        {
                            auto id = elem->findAttribute("id")->getValue();
                            auto gameObject = SceneManager::Current->findById(id);
                            toSet.push_back(gameObject);
                        }
                        catch (...)
                        {
                            Logger::Log("Property Component ref nb :"+std::to_string(i)+", in list named '" +propertyName+ "': has no value", Logger::DEBUG);
                        }
                        ++i;
                    }
                };

                template<typename T>
                void setProperty(std::string propertyName, safe_ptr<T> &toSet)
                {
                    auto refProp = findProperty(propertyName);

                    if (refProp == nullptr)
                        return;

                    try
                    {
                        auto id = refProp->findAttribute("id")->getValue();
                        auto gameObject = SceneManager::FindById(id);
                        auto comp = gameObject->GetComponent<T>();

                        if (!comp)
                            throw;
                        toSet = comp;
                    }
                    catch (...)
                    {
                        Logger::Log("Property gameObject ref named '" +propertyName+ "': has no value", Logger::DEBUG);
                    }
                }
            private:
                
                std::shared_ptr<XmlNode> findProperty(std::string name);
                
                std::string type;
                std::shared_ptr<XmlNode> node;
                std::shared_ptr<Scene> scene;
        };
    }
}

#endif //ENGINE_XMLCOMPONENT_HPP
