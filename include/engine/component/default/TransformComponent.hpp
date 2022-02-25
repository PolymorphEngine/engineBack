/*
** EPITECH PROJECT, 2020
** Transform.hpp.h
** File description:
** header for Transform.c
*/

#ifndef ENGINE_TRANSFORMCOMPONENT_HPP
#define ENGINE_TRANSFORMCOMPONENT_HPP

#include <vector>
#include "Component.hpp"
#include "ref_ptr.hpp"
#include "safe_ptr.hpp"
#include "Vector.hpp"

namespace Polymorph
{
    using TransformBase = std::shared_ptr<TransformComponent>;
    using Transform = safe_ptr<TransformComponent>;
    class TransformComponent : public Component
    {
        public:

            explicit TransformComponent(Entity &gameObject) : Component("Transform", gameObject)
            {}

            Vector3 position;
            Vector3 rotation;
            Vector3 scale;
            TransformBase parent;
            std::vector<TransformBase> children;

            typedef std::vector<std::shared_ptr<TransformComponent>>::iterator iterator;
            iterator begin()
            {
                return children.begin();
            }

            void erase(int pos)
            {
                children.erase(children.begin() + pos);
            }

            iterator end()
            {
                return children.end();
            }

            void SetParent(std::shared_ptr<TransformComponent> parent);

            std::shared_ptr<TransformComponent> &RemoveChild(TransformComponent &child);
            void SetSiblingIndex(int index);
            void SetLastSibling();
            void SetFirstSibling();

            void Update() override;
        private:
            void UpdateChildren();

    };


}

#endif //ENGINE_TRANSFORMCOMPONENT_HPP
