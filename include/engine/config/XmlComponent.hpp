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
#include "Vector.hpp"
#include "Rect.hpp"
#include "safe_ptr.hpp"

namespace Polymorph
{
    
    class Scene;
    class Entity;
    namespace Config
    {
        using XmlNode = void *;

        /**
         * @class The class that interfaces a Component Xml Node and the actual Component
         * inside the engine.
         * @    
         */
        class XmlComponent
        {
            public:
                /**
                 * @summary Looks for the initial state of the component in the config
                 * @return the component enable state
                 */
                bool isEnabled();

                /**
                 * @summary Looks for the component type in the component's config file
                 * @return The type of the component
                 */
                std::string getType();

                /**
                 * @summary Looks for a Vector3 property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An Vector3 property
                 */
                Vector3 getVector3Property(std::string name);


                /**
                 * @summary Looks for a Vector2 property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An Vector2 property
                 */
                Vector2 getVector2Property(std::string name);
                
                /**
                 * @summary Looks for a Rect property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An Rect property
                 */
                Rect getRectProperty(std::string name);


                /**
                 * @summary Looks for a character string property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An std::string property
                 */
                std::string getStringProperty(std::string name);

                /**
                 * @summary Looks for a integer property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An int property
                 */
                int getIntProperty(std::string name);

                /**
                 * @summary Looks for a floating point property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An float property
                 */
                float getFloatProperty(std::string name);
                
                /**
                 * @summary Looks for a boolean property in the component's config file
                 * @param name: the name of the property to look for
                 * @return An bool property
                 */
                bool getBoolProperty(std::string name);
                
                /**
                 * @summary Looks for a component reference property in the component's config file,
                 *          then with the data found it uses it to search the entity->component requested
                 *          in the engine.
                 * @tparam T: the T type of the component to look for
                 * @param name: the name of the property to look for
                 * @return A smart pointer (safe_ptr<T>) of the component property
                 */
                template<typename T>
                safe_ptr<T> getComponentReferenceProperty(std::string name);

                /**
                 * @summary Looks for an entity reference property in the component's config file,
                 *          then with the data found it uses it to search the entity requested
                 *          in the engine.
                 * @param name: the name of the property to look for
                 * @return An smart pointer (safe_ptr<T>) of the entity (alias GameObject) property
                 */
                safe_ptr<Entity> getEntityReferenceProperty(std::string name);

                /**
                 * @summary Looks for an LIST of entity reference property in the component's config file,
                 *          then with the data found it uses it to search the entities requested
                 *          in the engine.
                 * @param name: the name of the property to look for
                 * @return An vector of smart pointer (safe_ptr<T>) of entities (alias GameObject)
                 */
                std::vector<safe_ptr<Entity>> getEntityReferencePropertylList(std::string name);

                /**
                * @summary Looks for an custom property in the component's config file,
                *          then with the data found it tries to build the custom object by passing
                *          the data found to it's constructor
                * @tparam T: the 'T' type of the object config to look for
                * @warning Never try to call this with an object type that doesn't have a proper constructor !
                * @param name: the name of the property to look for
                * @return An instance of the custom object requested
                */
                template<typename T>
                T getTemplatedProperty(std::string name);

                /**
                 * 
                 * @summary Looks for an custom property in the component's config file,
                 *          then with the data found it tries to build the custom object by passing
                 *          the data found to it's constructor
                 * @tparam T: the 'T' type of the objects configs to look for
                 * @warning Never try to call this with an object type that doesn't have a proper constructor !
                 * @param name: the name of the property to look for
                 * @return An list of instances of the custom objects requested
                 */
                template<typename T>
                std::vector<T> getListOfTemplatedProperty(std::string name);

            private:
                
                std::string type;
                std::shared_ptr<XmlNode> node;
                std::shared_ptr<Scene> scene;
        };
    }
}

#endif //ENGINE_XMLCOMPONENT_HPP
