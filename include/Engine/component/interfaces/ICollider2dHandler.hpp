/*
** EPITECH PROJECT, 2020
** IColliderHandler.hpp
** File description:
** header for IColliderHandler.c
*/

#ifndef ENGINE_ICOLLIDER2DHANDLER_HPP
#define ENGINE_ICOLLIDER2DHANDLER_HPP

#include "default/Colliders/Collider2d.hpp"

namespace Polymorph
{
    class Collider2dComponent;
    
    
    class ICollider2dHandler
    {
        public:
            virtual void onCollisionEnter(Collider2d &collider) = 0;
            virtual void onCollisionExit(Collider2d &collider) = 0;
            virtual void onCollisionStay(Collider2d &collider) = 0;
    };
}

#endif //ENGINE_ICOLLIDER2DHANDLER_HPP
