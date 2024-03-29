/*
** EPITECH PROJECT, 2020
** Component_templated.hpp
** File description:
** header for Component_templated.c
*/

#ifndef ENGINE_COMPONENT_TEMPLATED_HPP
#define ENGINE_COMPONENT_TEMPLATED_HPP

#include "Utilities/safe_ptr.hpp"
#include "Component.hpp"
#include "Core/Entity/Entity.hpp"
#include "../transform/TransformComponent.hpp"

namespace polymorph::engine
{

    template<typename T>
    safe_ptr<T> Component::getComponent()
    {
        return gameObject->getComponent<T>();
    }

    /**
     * @details Looks for a component by type in parent's
     * @tparam T: The 'T' type of the component to look for.
     * @warning The type 'T' must inherit from the Component class to be fetched
     * @returns A safe pointer to the component 'T'
     */
    template<typename T>
    safe_ptr<T> Component::getComponentInParent()
    {
        if (!!transform->parent())
            return transform->parent()->gameObject->getComponent<T>();
    }

    /**
     * @details Looks for a component by type in children
     * @tparam T: The 'T' type of the component to look for.
     * @warning Using depth first search !
     * @warning The type 'T' must inherit from the Component class to be fetched
     * @returns A safe pointer to the component 'T'
     */
    template<typename T>
    safe_ptr<T> Component::getComponentInChildren()
    {
        for (auto &child: **transform)
        {
            auto c2 = child->getComponent<T>();
            if (!!c2)
                return c2;
        }

        for (auto &child: **transform)
        {
            auto c1 = child->getComponentInChildren<T>();
            if (!!c1)
                return c1;

        }
        return safe_ptr<T>(nullptr);
    }

    /**
     * @details Adds a component to the entity
     * @tparam T: The 'T' type of the component to add.
     * @warning Does nothing if the component is already added
     * @warning The type 'T' must have an initializer in the component factory to be added this way
     * @warning The type 'T' must inherit from the Component class to be added
     * @returns A safe pointer to the component 'T'
     */
    template<typename T>
    safe_ptr<T> Component::addComponent()
    {
        return gameObject->addComponent<T>();
    }

    /**
     * @details Checks if a component of type 'T' exist in the entity
     * @tparam T: The 'T' type of the component to check for.
     * @warning The type 'T' must inherit from the Component class to be checked
     * @returns True if the component exist
     */
    template<typename T>
    bool Component::componentExist()
    {
        return gameObject->componentExist<T>();
    }

    /**
     * @details Deletes the component of type 'T' from the entity
     * @tparam T: The 'T' type of the component to delete.
     * @warning The type 'T' must inherit from the Component class to be deleted
     * @returns True if the component existed and was deleted successfully
     */
    template<typename T>
    bool Component::deleteComponent()
    {
        return gameObject->deleteComponent<T>();
    }

}

#endif //ENGINE_COMPONENT_TEMPLATED_HPP
