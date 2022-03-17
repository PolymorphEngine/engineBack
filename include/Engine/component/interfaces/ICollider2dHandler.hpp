/*
** EPITECH PROJECT, 2020
** IColliderHandler.hpp
** File description:
** header for IColliderHandler.c
*/

#ifndef ENGINE_ICOLLIDER2DHANDLER_HPP
#define ENGINE_ICOLLIDER2DHANDLER_HPP

namespace Polymorph
{
    class Collider2d;
    
    class ICollider2dHandler
    {
        public:
            virtual void onCollisionEnter(Collider2d &collider) = 0;
            virtual void onCollisionExit(Collider2d &collider) = 0;
            virtual void onCollisionStay(Collider2d &collider) = 0;
    };
}

#endif //ENGINE_ICOLLIDER2DHANDLER_HPP
