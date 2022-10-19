/*
** EPITECH PROJECT, 2020
** IPointerClickHandler.hpp
** File description:
** header for IPointerClickHandler.c
*/

#ifndef ENGINE_IPOINTERCLICKHANDLER_HPP
#define ENGINE_IPOINTERCLICKHANDLER_HPP

namespace Polymorph
{
    class PointerEvent;

    class IPointerClickHandler
    {
        public:
            virtual void onPointerDown(PointerEvent &event) = 0;

            virtual void onPointerHold(PointerEvent &event) = 0;

            virtual void onPointerUp(PointerEvent &event) = 0;
    };
}

#endif //ENGINE_IPOINTERCLICKHANDLER_HPP
