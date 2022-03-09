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

    void TransformComponent::SetParent(std::shared_ptr<TransformComponent> parent)
    {
        if (this->parent != nullptr && this->parent != parent)
            this->parent->RemoveChild(*this);
        this->parent = parent;
        if (parent == nullptr)
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
            if ((*child).gameObject.getId() == remove.gameObject.getId())
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

        if (parent == nullptr || index < 0)
            return;
        if (index >= parent->children.size())
            index = parent->children.size() - 1;

        //TODO: Set index in scene !!!

        TransformBase self = parent->RemoveChild(*this);
        parent->children.insert(parent->children.begin() + index, self);
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

}
