/*
** EPITECH PROJECT, 2020
** Time.cpp
** File description:
** Time.cpp
*/

#include "Time.hpp"

namespace Polymorph
{


    void Timer::tick()
    {
            actual += Time::deltaTime;
    }

    bool Timer::timeIsUp(bool isReset)
    {
        if (actual >= delay) {
            if (isReset)
                actual = 0;
            return true;
        }
        return false;
    }

    Timer::Timer(float delay)
    {
        this->delay = delay;
    }
}