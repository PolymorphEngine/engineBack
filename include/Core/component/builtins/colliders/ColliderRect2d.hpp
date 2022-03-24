/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_COLLIDER2RECT_HPP
#define ENGINE_COLLIDER2RECT_HPP

#include "component/base/Collider2d.hpp"

namespace Polymorph
 {

    class ColliderRect2dComponent : public Collider2dComponent {

///////////////////////////////// Properties ///////////////////////////////////

        public:
            Vector2 size;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            bool checkCollision(Collider2dComponent &other) override;

///////////////////////////--------------------------///////////////////////////

    };
 }

#endif //ENGINE_COLLIDER2RECT_HPP
