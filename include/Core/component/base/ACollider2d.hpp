/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_ACOLLIDER2D_HPP
#define ENGINE_ACOLLIDER2D_HPP

#include "Core/component/base/Component.hpp"
#include <map>

 namespace Polymorph
 {
    class ACollider2dComponent;
    using Collider2dBase = std::shared_ptr<ACollider2dComponent>;
    using Collider2d = safe_ptr<ACollider2dComponent>;

    /**
     * @class Collider2dComponent
     * @details An abstract component that is used to make new collider shapes (box, circle ...)
     * @warning Do not try to use this as a component ! (AddComponent)
     */
    class ACollider2dComponent : public Component
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            ACollider2dComponent(GameObject gameObject, std::string type);
            ~ACollider2dComponent();

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            Vector2 offset = {0, 0};
        private:
            /**
             * @property all colliders encountered at runtime
             */
            std::map<std::string, bool> _encountered;

            /**
             * @property the iterator where is placed the instance of the collider
             */
            long _colliderIdx;

             /**
              * @property all colliders instantiated in the game
              */
            static inline std::vector<ACollider2dComponent *> _allColliders = {};
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            void update() override;

        private:
            /**
             * As to check collision with any collider shape implementation (box, circle ...)
             * @param collider the collider with the collision is checked
             * @return true if collision occurs
             */
            virtual bool checkCollision(ACollider2dComponent &collider) = 0;


            /**
             * @details BroadCasting collision event functions
             */
            void _checkCollisionToBroadCast(ACollider2dComponent &collider);

            void _broadCastCollisionStay(ACollider2dComponent &collider);
            void _broadCastCollisionEnter(ACollider2dComponent &collider);
            void _broadCastCollisionExit(ACollider2dComponent &collider);
///////////////////////////--------------------------///////////////////////////

     };


 }

#endif //ENGINE_ACOLLIDER2D_HPP
