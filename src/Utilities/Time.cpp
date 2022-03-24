/*
** EPITECH PROJECT, 2020
** Time.cpp
** File description:
** Time.cpp
*/

#include <Polymorph/Types.hpp>

namespace Polymorph
{


    Time::Time() : _lastTime(Clock::now()) {};

    void Time::computeDeltaTime()
    {
        auto now = Clock::now();
        std::chrono::duration<double> diff = now - _lastTime;

        deltaTime = diff.count();
        _lastTime = now;
    }

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

    Timer::Timer(double delay)
    {
        this->delay = delay;
    }
}