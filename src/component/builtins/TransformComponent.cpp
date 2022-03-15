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

    void TransformComponent::SetParent(const std::shared_ptr<TransformComponent>& parent_ref)
    {
        if (this->parent != nullptr && this->parent != parent_ref)
            this->parent->RemoveChild(*this);
        this->parent = parent_ref;
        if (parent_ref == nullptr)
        {
            //TODO: Set index in scene at (next parent empty Entity index) - 1
        }
        SetLastSibling();
    }

    void TransformComponent::UpdateChildren()
    {

    }

    TransformBase TransformComponent::RemoveChild(TransformComponent &remove)
    {
        int pos = 0;

        for (auto &child: *this)
        {
            if (child->gameObject.getId() == remove.gameObject.getId())
            {
                erase(pos);
                remove.parent.reset();
                //TODO: reset in scene
                return (child);
            }
            ++pos;
        }
        return nullptr;
    }

    void TransformComponent::SetSiblingIndex(int index)
    {

        if (parent == nullptr)
            return;
        if (index < 0)
            index = 0;
        if (index >= parent->children.size() && index != 0)
            index = parent->children.size() - 1;

        //TODO: Set index in scene !!!

        parent->RemoveChild(*this);
        parent->children.insert(parent->children.begin() + index, this->gameObject.transform);
    }

    void TransformComponent::SetLastSibling()
    {
        if (parent == nullptr)
            //TODO : Log "Tried to set sibling index on an object which hasn't a parent"
            return;
        SetSiblingIndex((int)parent->children.size() - 1);
    }

    void TransformComponent::SetFirstSibling()
    {
        SetSiblingIndex(0);
    }

    TransformComponent::TransformComponent(Entity &gameObject)
            : Component("Transform", gameObject)
    {

    }

    void TransformComponent::Start()
    {

    }

}
