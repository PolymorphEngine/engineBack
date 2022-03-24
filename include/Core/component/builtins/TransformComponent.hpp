/*
** EPITECH PROJECT, 2020
** Transform.hpp.h
** File description:
** header for Transform.c
*/

#ifndef ENGINE_TRANSFORMCOMPONENT_HPP
#define ENGINE_TRANSFORMCOMPONENT_HPP

#include <vector>
#include "component/base/Component.hpp"
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
        friend class TransformInitializer;
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

        private:
            /**
             * Position of the entity
             */
            Vector3 _position;

            /**
             * Rotation of the entity
             */
            Vector2 _rotation;

            /**
             * Scale of drawable components in the entity
             */
            Vector3 _scale;

            /**
             * A reference to the parent entity's transform (in the case the entity has a parent)
             */
            TransformBase _parent = nullptr;

            /**
             * The list of all references to children's entities transforms
             */
            std::vector<TransformBase> _children;

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
                return _children.begin();
            }

            /**
             * Delete the relation to a child at the provided index
             * @param pos the index of the related entity
             */
            void erase(int pos)
            {
                _children.erase(_children.begin() + pos);
            }

            /**
             * with this method, the transform is used as a container of children
             * This method allows to iterate over the list
             * @return An iterator to the end of the children list
             */
            iterator end()
            {
                return _children.end();
            }

            Transform parent();

            std::size_t nbChildren();

            bool noChild();

            const Vector3 &getPosition() const;

            void setPosition(const Vector3 &position);

            void setPositionX(const float posX);

            void setPositionY(const float posY);

            void setPositionZ(const float posZ);

            void move(const Vector3 &delta);

//TODO do this later
/*
            const Vector2 &getRotation() const;

            void setRotation(const Vector2 &rotation);

            void setRotationX(float rotationX);

            void setRotationY(float rotationY);


            const Vector3 &getScale() const;

            void setScale(const Vector3 &scale);

            void setScaleX(float scaleX);

            void setScaleY(float scaleY);

            void setScaleZ(float scaleZ);
*/

            void setParent(const std::shared_ptr<TransformComponent>& parent_ref);

            std::shared_ptr<TransformComponent> removeChild(TransformComponent &child);

            void setSiblingIndex(int index);

            void setLastSibling();

            void setFirstSibling();

            void start() override;

            void update() override;

        private:
            void _moveChildren(const Vector3 &delta);
            //TODO implement this
            /*
            void _rotateChildren(const Vector2 &delta);
            void _scaleChildren(const Vector3 &delta);
             */
///////////////////////////--------------------------///////////////////////////
    };
}

#endif //ENGINE_TRANSFORMCOMPONENT_HPP
