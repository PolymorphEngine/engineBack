/*
** EPITECH PROJECT, 2020
** IDropHandler.hpp
** File description:
** header for IDropHandler.c
*/

#ifndef ENGINE_IDROPHANDLER_HPP
#define ENGINE_IDROPHANDLER_HPP

namespace Polymorph
{
    class PointerEvent;

    class IDropHandler
    {
        public:
            virtual void onDrop(PointerEvent &event) = 0;

            virtual void checkDrop(PointerEvent &event) = 0;
    };
}

#endif //ENGINE_IDROPHANDLER_HPP
