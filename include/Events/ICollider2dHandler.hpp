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
    class ACollider2dComponent;


    class ICollider2dHandler
    {
        public:
            virtual void onCollisionEnter(ACollider2dComponent &collider) = 0;
            virtual void onCollisionExit(ACollider2dComponent &collider) = 0;
            virtual void onCollisionStay(ACollider2dComponent &collider) = 0;
    };
}

#endif //ENGINE_ICOLLIDER2DHANDLER_HPP
