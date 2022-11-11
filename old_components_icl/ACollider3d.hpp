/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_ACOLLIDER3D_HPP
#define ENGINE_ACOLLIDER3D_HPP

#include "Core/Component/base/Component.hpp"
#include "Utilities/types/Vector.hpp"
#include "Utilities/InstanceStore.hpp"
#include <map>


namespace Polymorph
{
    class ACollider3dComponent;

    using Collider3dBase = std::shared_ptr<ACollider3dComponent>;
    using Collider3d = safe_ptr<ACollider3dComponent>;

    /**
     * @class Collider3dComponent
     * @details An abstract component that is used to make new collider shapes (box, circle ...)
     * @warning Do not try to use this as a component !(AddComponent)
     */
    class ACollider3dComponent : public Component
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            ACollider3dComponent(GameObject gameObject,
                                 const std::string &type);

            ~ACollider3dComponent();

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            Vector3 offset;

        private:
            safe_ptr<ACollider3dComponent> _this_safe;
            static inline InstanceStore<ACollider3dComponent> _instanceStore;
            /**
             * @property all colliders encountered at runtime
             */
            std::map<std::string, bool> _encountered;
            bool _isPrefab = false;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            void update() override;

            void onAwake() override;

        private:
            virtual void debugDraw() = 0;

            virtual void setColliderPosition() = 0;

            /**dd
             * As to check collision with any collider shape implementation (box, circle ...)
             * @param collider the collider with the collision is checked
             * @return true if collision occurs
             */
            virtual bool checkCollision(ACollider3dComponent &collider) = 0;

            /**
             * @details BroadCasting collision event functions
             */
            void _checkCollisionToBroadCast(ACollider3dComponent &collider);

            void _broadCastCollisionStay(ACollider3dComponent &collider);

            void _broadCastCollisionEnter(ACollider3dComponent &collider);

            void _broadCastCollisionExit(ACollider3dComponent &collider);
///////////////////////////--------------------------///////////////////////////

    };


}

#endif //ENGINE_ACOLLIDER3D_HPP
