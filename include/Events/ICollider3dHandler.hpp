/*
** EPITECH PROJECT, 2020
** IColliderHandler.hpp
** File description:
** header for IColliderHandler.c
*/

#ifndef ENGINE_ICOLLIDER3DHANDLER_HPP
#define ENGINE_ICOLLIDER3DHANDLER_HPP

namespace Polymorph
{
    class ACollider3dComponent;


    class ICollider3dHandler
    {
        public:
            virtual void onCollisionEnter(ACollider3dComponent &collider) = 0;
            virtual void onCollisionExit(ACollider3dComponent &collider) = 0;
            virtual void onCollisionStay(ACollider3dComponent &collider) = 0;
    };
}

#endif //ENGINE_ICOLLIDER3DHANDLER_HPP
