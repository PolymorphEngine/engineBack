/*
** EPITECH PROJECT, 2020
** Time.hpp.h
** File description:
** header for Time.c
*/

#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <iostream>

namespace Polymorph
{
    class Time
    {
        public:
            static float deltaTime;
    };

    class Timer
    {
        public:
            float delay = 0;
            float actual = 0;
            void tick() {
                actual += Time::deltaTime;
            };
            bool timeIsUp(bool isReset = true)
            {
                if (actual >= delay)
                {
                    if (isReset)
                        actual = 0;
                    return true;
                }
            };
    };

}

#endif //ENGINE_TIME_HPP
