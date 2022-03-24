/*
** EPITECH PROJECT, 2020
** Time.hpp.h
** File description:
** header for Time.c
*/

#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <iostream>
#include <chrono>

namespace Polymorph
{
    class Time
    {
        using Clock = std::chrono::steady_clock;
        using Duration = std::chrono::time_point<Clock>;

///////////////////////////////// Constructors /////////////////////////////////

        public:
            /**
             * @details Create a Time clock by initializing internal properties
             */
            explicit Time();
///////////////////////////--------------------------///////////////////////////
///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline double deltaTime = 0.0f;

        private:
            Duration _lastTime;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void computeDeltaTime();
//////////////////////--------------------------/////////////////////////

    };



    class Timer
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            Timer() = default;
            explicit Timer(double delay);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            double delay = 0;
            double actual = 0;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void tick();
            bool timeIsUp(bool isReset = true);;
//////////////////////--------------------------/////////////////////////

    };

}

#endif //ENGINE_TIME_HPP
