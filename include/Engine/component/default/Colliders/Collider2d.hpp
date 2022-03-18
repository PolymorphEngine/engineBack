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
            Collider2dComponent(Entity &gameObject, std::string &type);
            ~Collider2dComponent();

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            Vector2 offset;
        private:
            /**
             * @property all colliders encountered at runtime
             */
            std::map<std::string, bool> _encountered;
            
            /**
             * @property the iterator where is placed the instance of the collider
             */
            std::vector<Collider2dComponent *>::iterator _colliderIdx;
             
             /**
              * @property all colliders instantiated in the game
              */
            static inline std::vector<Collider2dComponent *> _allColliders = {};
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        private:
            /**
             * As to check collision with any collider shape implementation (box, circle ...)
             * @param collider the collider with the collision is checked
             * @return true if collision occurs
             */
            virtual bool checkCollision(Collider2dComponent &collider) = 0;

            void update() override;

            /**
             * @details BroadCasting collision event functions
             */
            void _checkCollisionToBroadCast(Collider2dComponent &collider);

            void _broadCastCollisionStay(Collider2dComponent &collider);
            void _broadCastCollisionEnter(Collider2dComponent &collider);
            void _broadCastCollisionExit(Collider2dComponent &collider);
///////////////////////////--------------------------///////////////////////////

     };


 }

#endif //ENGINE_COLLIDER2D_HPP
