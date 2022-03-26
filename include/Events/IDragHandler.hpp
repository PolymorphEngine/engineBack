/*
** EPITECH PROJECT, 2020
** IPointerDragHandler.hpp
** File description:
** header for IPointerDragHandler.c
*/

#ifndef ENGINE_IDRAGHANDLER_HPP
#define ENGINE_IDRAGHANDLER_HPP

namespace Polymorph
{
    class PointerEvent;

    class IDragHandler
    {
        public:
            virtual void onDrag(PointerEvent &event) = 0;
            virtual void onDragBegin(PointerEvent &event) = 0;
            virtual void onDragEnd(PointerEvent &event) = 0;
    };
}

#endif //ENGINE_IDRAGHANDLER_HPP
