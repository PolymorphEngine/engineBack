/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#ifndef ENGINE_COLLIDER2D_HPP
#define ENGINE_COLLIDER2D_HPP

#include "Component.hpp"

 namespace Polymorph
 {
    class Collider2dComponent;
    using Collider2dBase = std::shared_ptr<Collider2dComponent>;
    using Collider2d = safe_ptr<Collider2dComponent>;
    
    /**
     * @class Collider2dComponent
     * @details An abstract component that is used to make new collider shapes (box, circle ...)
     * @warning Do not try to use this as a component ! (AddComponent)
     */
    class Collider2dComponent : public Component
    {
        public:
///////////////////////////////// Constructors /////////////////////////////////
        public:
            Collider2dComponent(Entity &gameObject, std::string type);
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        private:
             /**
              * @property all colliders which collided with the object during this frame
              */
             std::map<std::string, bool> _encountered;
            
            bool _computer = false;
             /**
              * @property all colliders which didn't collided with the object during this frame
              */
            std::vector<Collider2d> not_encountered;

             /**
              * @property all colliders instantiated in the game
              */
            static inline std::vector<Collider2d> _allColliders = {};
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        private:
            /**
             * As to check collision with any collider shape implementation (box, circle ...)
             * @param collider the collider with the collision is checked
             * @return true if collision occurs
             */
            virtual bool checkCollision(Collider2d &collider) = 0;

            void update() override;

            void _broadCastCollisionStay(Collider2d &collider);
            void _broadCastCollisionEnter(Collider2d &collider);
            void _broadCastCollisionExit(Collider2d &collider);
            void _checkCollisionToBroadCast(Collider2d &collider);
///////////////////////////--------------------------///////////////////////////

     };


 }

#endif //ENGINE_COLLIDER2D_HPP
