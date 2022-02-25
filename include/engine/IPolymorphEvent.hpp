/*
** EPITECH PROJECT, 2020
** IPolymorphEvent.hpp.h
** File description:
** header for IPolymorphEvent.c
*/

#ifndef ENGINE_IPOLYMORPHEVENT_HPP
#define ENGINE_IPOLYMORPHEVENT_HPP

#include <vector>
#include <iostream>

namespace Polymorph
{
    class IPolymorphEvent
    {
    };

    class PolymorphEvents{
    public:
        void storeEvents();

    private:
        std::vector<IPolymorphEvent> _events;
    };
}

#endif //ENGINE_IPOLYMORPHEVENT_HPP
