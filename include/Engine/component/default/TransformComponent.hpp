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
#include "safe_ptr.hpp"
#include "Vector.hpp"

namespace Polymorph
{
    using TransformBase = std::shared_ptr<TransformComponent>;
    using Transform = safe_ptr<TransformComponent>;

    /**
     * @class TransformComponent A special component which handles all the
     * parent/children relation for entities
     */
    class TransformComponent : public Component
    {
        using iterator = std::vector<std::shared_ptr<TransformComponent>>::iterator;

///////////////////////////////// Constructors /////////////////////////////////

        public:
            /**
             * Create a transform component with the entity which it belongs to
             * @param gameObject the container entity
             */
            explicit TransformComponent(Entity &gameObject);
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        public:
            /**
             * Position of the entity
             */
            Vector3 position;

            /**
             * Rotation of the entity
             */
            Vector3 rotation;

            /**
             * Scale of drawable components in the entity
             */
            Vector3 scale;

            /**
             * A reference to the parent entity's transform (in the case the entity has a parent)
             */
            TransformBase parent = nullptr;

            /**
             * The list of all references to children's entities transforms
             */
            std::vector<TransformBase> children;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            /**
             * with this method, the transform is used as a container of children
             * This method allows to iterate over the list
             * @return An iterator to the begin of the children list
             */
            iterator begin()
            {
                return children.begin();
            }

            /**
             * Delete the relation to a child at the provided index
             * @param pos the index of the related entity
             */
            void erase(int pos)
            {
                children.erase(children.begin() + pos);
            }

            /**
             * with this method, the transform is used as a container of children
             * This method allows to iterate over the list
             * @return An iterator to the end of the children list
             */
            iterator end()
            {
                return children.end();
            }

            void setParent(const std::shared_ptr<TransformComponent>& parent_ref);

            std::shared_ptr<TransformComponent> removeChild(TransformComponent &child);

            void setSiblingIndex(int index);

            void setLastSibling();

            void setFirstSibling();

            void start() override;

        private:
            void updateChildren();
///////////////////////////--------------------------///////////////////////////
    };
}

#endif //ENGINE_TRANSFORMCOMPONENT_HPP
