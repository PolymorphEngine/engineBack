/*
** EPITECH PROJECT, 2020
** IMonitorDisplay.hpp.h
** File description:
** header for IMonitorDisplay.c
*/

#ifndef ENGINE_IPOLYMORPHDISPLAY_HPP
#define ENGINE_IPOLYMORPHDISPLAY_HPP

namespace Polymorph
{
    class IPolymorphDisplay
    {
    public:
        virtual bool isRunning() = 0;
        virtual void clearDisplay() = 0;
        virtual void draw() = 0;
    };
}
#endif //ENGINE_IPOLYMORPHDISPLAY_HPP
