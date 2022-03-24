/*
** EPITECH PROJECT, 2020
** IPointerHandler.hpp
** File description:
** header for IPointerHandler.c
*/

#ifndef ENGINE_IPOINTERHANDLER_HPP
#define ENGINE_IPOINTERHANDLER_HPP

namespace Polymorph
{
    class PointerEvent;

    class IPointerHandler
    {
        public:
            virtual void onPointerEnter(PointerEvent &event) = 0;
            virtual void onPointerHover(PointerEvent &event) = 0;
            virtual void onPointerExit(PointerEvent &event) = 0;
    };
}


#endif //ENGINE_IPOINTERHANDLER_HPP
