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

///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline float deltaTime = 0.0f;
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
            Timer()= default;
            explicit Timer(float delay);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            float delay = 0;
            float actual = 0;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void tick();
            bool timeIsUp(bool isReset = true);;
//////////////////////--------------------------/////////////////////////

    };

}

#endif //ENGINE_TIME_HPP
