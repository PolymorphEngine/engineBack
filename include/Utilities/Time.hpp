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
#include "safe_ptr.hpp"

namespace polymorph::engine
{
    class Engine;
    class Component;
    class Entity;
    using GameObject = safe_ptr<Entity>;
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
            /**
             * @property deltaTime the time between the last frame and the current frame
             */
            double deltaTime = 0.0f;

        private:
            /**
             * @property _lastTime the time of the last frame
             */
            Duration _lastTime;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @details Update the deltaTime of the current frame
             */
            void computeDeltaTime();

            /**
             * @details Get the current time from minutes to string
             * @return the current time in a string format
             */
            std::string formatToMinutes(float time);
//////////////////////--------------------------/////////////////////////

    };

    class Timer
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            /**
             * @brief Created a new timer from a specified delay
             * @param delay The delay in seconds
             */
            explicit Timer(Time &time, double delay);
            explicit Timer(Engine &game, double delay);
            explicit Timer(GameObject &object, double delay);
            explicit Timer(Component &component, double delay);
            
            Timer(Timer &&moved) noexcept : time(moved.time), delay(moved.delay), actual(moved.actual) {};
            Timer(Timer &copy) = default;
            
            Timer &operator=(const Timer &moved) {
                time = moved.time;
                delay = moved.delay;
                actual = moved.actual;
                return *this;
            };
            
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Time &time;
            /**
             * @property delay The delay in seconds
             */
            double delay = 0;

            /**
             * @property actual The current time of timer in seconds 
             */
            double actual = 0;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @brief Update the current time of the timer
             */
            void tick();

            /**
             * @brief Know if the current time is greater than the delay and may reset the timer
             * @param isReset If true, the timer will be reset
             * @return true if the current time is greater than the delay
             */
            bool timeIsUp(bool isReset = true);;
//////////////////////--------------------------/////////////////////////

    };

}

#endif //ENGINE_TIME_HPP
