/*
** EPITECH PROJECT, 2020
** ColliderCircle2dComponent.hpp
** File description:
** header for ColliderCircle2dComponent.c
*/

#ifndef ENGINE_COLLIDERCIRCLE2D_HPP
#define ENGINE_COLLIDERCIRCLE2D_HPP

#include "Collider2d.hpp"
#include "Component.hpp"

namespace Polymorph
{

    class ColliderCircle2dComponent : public Collider2dComponent
    {
///////////////////////////////// Constructors /////////////////////////////////

    public:
        explicit ColliderCircle2dComponent(Entity &gameObject);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        public:
            float radius = 0.0;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        private:
            bool checkCollision(Collider2dComponent &other) override;

///////////////////////////--------------------------///////////////////////////


    };

}

#endif //ENGINE_COLLIDERCIRCLE2D_HPP
