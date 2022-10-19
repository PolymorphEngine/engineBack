/*
** EPITECH PROJECT, 2020
** DrawableComponent.hpp
** File description:
** header for DrawableComponent.c
*/

#ifndef ENGINE_ADRAWABLE3DCOMPONENT_HPP
#define ENGINE_ADRAWABLE3DCOMPONENT_HPP

#include "Core/component/base/Component.hpp"

namespace Polymorph
{
    class ADrawable3dComponent;

    using Drawable3d = safe_ptr<ADrawable3dComponent>;

    class ADrawable3dComponent : public Component
    {
///////////////////////////////// Constructors /////////////////////////////////
        public:
            ADrawable3dComponent(std::string type, GameObject gameObject);
///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            Vector3 offset;
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            /**
             * @details An overridable method that's called once per frame in the game loop.
             */
            void update() override
            {};

            /**
             * @details An overridable method that's called once in the lifetime of the component.
             *          It is called before the games start (or upon component creation at runtime).
             * @warning Is called even if the enable state of the component is set to false on creation.
             */
            void onAwake() override
            {};

            /**
             * @details An overridable method that's called once in the lifetime of the component,
             *          It is called before the update method (or upon component creation at runtime).
             * @warning Is called ONLY when the enabled state of the component is passed to true.
             */
            void start() override
            {};

            /**
             * @details An overridable method that draws the component if its an drawable only.
             *          Called once per frame.
             */
            virtual void draw() = 0;
///////////////////////////--------------------------///////////////////////////


    };


}

#endif //ENGINE_ADRAWABLE3DCOMPONENT_HPP
