/*
** EPITECH PROJECT, 2020
** Transfoem.cpp.c
** File description:
** Transfoem.cpp.c
*/

#include "default/TransformComponent.hpp"
#include "Entity.hpp"

namespace Polymorph
{

    void TransformComponent::setParent(const std::shared_ptr<TransformComponent>& parent_ref)
    {
        if (this->parent != nullptr && this->parent != parent_ref)
            this->parent->removeChild(*this);
        this->parent = parent_ref;
        if (parent_ref == nullptr)
        {
            //TODO: Set index in scene at (next parent empty Entity index) - 1
        }
        setLastSibling();
    }

    void TransformComponent::updateChildren()
    {

    }

    TransformBase TransformComponent::removeChild(TransformComponent &child)
    {
        int pos = 0;

        for (auto &tchild: *this)
        {
            if (tchild->gameObject.getId() == child.gameObject.getId())
            {
                erase(pos);
                child.parent.reset();
                //TODO: reset in scene
                return (tchild);
            }
            ++pos;
        }
        return nullptr;
    }

    void TransformComponent::setSiblingIndex(int index)
    {

        if (parent == nullptr)
            return;
        if (index < 0)
            index = 0;
        if (index >= parent->children.size() && index != 0)
            index = parent->children.size() - 1;

        //TODO: Set index in scene !!!

        parent->removeChild(*this);
        parent->children.insert(parent->children.begin() + index, this->gameObject.transform);
    }

    void TransformComponent::setLastSibling()
    {
        if (parent == nullptr)
            //TODO : Log "Tried to set sibling index on an object which hasn't a parent"
            return;
        setSiblingIndex((int) parent->children.size() - 1);
    }

    void TransformComponent::setFirstSibling()
    {
        setSiblingIndex(0);
    }

    TransformComponent::TransformComponent(Entity &gameObject)
            : Component("Transform", gameObject)
    {

    }

    void TransformComponent::start()
    {

    }

}
