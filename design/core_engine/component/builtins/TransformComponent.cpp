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
        if (this->parent != nullptr)
            this->parent->RemoveChild(*this);
        this->parent = parent;
        if (parent == nullptr)
        {
            //TODO: reset in scene
        }
        SetLastSibling();
    }

    void TransformComponent::UpdateChildren()
    {

    }

    TransformBase &TransformComponent::RemoveChild(TransformComponent &remove)
    {
        int pos = 0;

        for (auto &child: children)
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
    }

    void TransformComponent::Update()
    {
    }


    void TransformComponent::SetSiblingIndex(int index)
    {

        if (parent == nullptr || index < 0 || index >= parent->children.size())
            return;
        TransformBase &self = parent->RemoveChild(*this);
        std::vector<TransformBase> &cs = parent->children;
        cs.insert(cs.begin() + index, self);
    }

    void TransformComponent::SetLastSibling()
    {
        if (parent == nullptr)
            //TODO : Log "Tried to set sibling index on an object which hasn't a parent"
            return;
        SetSiblingIndex((int)parent->children.size());
    }

    void TransformComponent::SetFirstSibling()
    {
        SetSiblingIndex(0);
    }

}

