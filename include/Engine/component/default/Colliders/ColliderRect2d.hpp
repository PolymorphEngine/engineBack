/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_COLLIDER2RECT_HPP
#define ENGINE_COLLIDER2RECT_HPP

#include "Collider2d.hpp"

namespace Polymorph
 {

    class ColliderRect2dComponent : public Collider2dComponent
    {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            explicit ColliderRect2dComponent(Entity &entity);

///////////////////////////--------------------------///////////////////////////

///////////////////////////////// Properties ///////////////////////////////////

        public:
            Vector2 size = {0, 0};

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            bool checkCollision(Collider2dComponent &other) override;

///////////////////////////--------------------------///////////////////////////

    };
 }

#endif //ENGINE_COLLIDER2RECT_HPP
