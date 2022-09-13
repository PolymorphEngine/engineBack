/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_COLLIDER2CIRCLE_HPP
#define ENGINE_COLLIDER2CIRCLE_HPP

#include "Core/component/base/ACollider2d.hpp"

namespace Polymorph
 {
    class ColliderCircle2dComponent;
    using ColliderCircle2d = safe_ptr<ColliderCircle2dComponent>;
    using ColliderCircle2dBase = std::shared_ptr<ColliderCircle2dComponent>;

    class ColliderCircle2dComponent : public ACollider2dComponent
    {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            explicit ColliderCircle2dComponent(GameObject entity);

///////////////////////////--------------------------///////////////////////////

///////////////////////////////// Properties ///////////////////////////////////

        public:
            float radius = 0.0f;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            bool checkCollision(ACollider2dComponent &other) override;

///////////////////////////--------------------------///////////////////////////

    };
 }

#endif //ENGINE_COLLIDER2CIRCLE_HPP
