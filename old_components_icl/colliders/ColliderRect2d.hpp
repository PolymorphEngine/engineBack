/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_COLLIDER2RECT_HPP
#define ENGINE_COLLIDER2RECT_HPP

#include "Core/Component/base/ACollider2d.hpp"

namespace Polymorph
{
    class ColliderRect2dComponent;

    using ColliderRect2d = safe_ptr<ColliderRect2dComponent>;
    using ColliderRect2dBase = std::shared_ptr<ColliderRect2dComponent>;

    class ColliderRect2dComponent : public ACollider2dComponent
    {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            explicit ColliderRect2dComponent(GameObject entity);

///////////////////////////--------------------------///////////////////////////

///////////////////////////////// Properties ///////////////////////////////////

        public:
            Vector2 size;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            bool checkCollision(ACollider2dComponent &other) override;

            void debugDraw() final;
            void setColliderPosition() final;
///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COLLIDER2RECT_HPP
