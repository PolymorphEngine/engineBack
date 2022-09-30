/*
** EPITECH PROJECT, 2020
** IButtonHandler.hpp
** File description:
** header for IButtonHandler.c
*/


#pragma once

namespace Polymorph
{
    class Entity;

    using GameObject = safe_ptr<Entity>;

    class IButtonHandler
    {
        public:
            virtual void onButtonPressed(GameObject pressed) = 0;

            virtual void onButtonReleased(GameObject released) = 0;

            virtual void onButtonDown(GameObject pressed) = 0;
    };
}
