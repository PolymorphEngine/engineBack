/*
** EPITECH PROJECT, 2020
** Time.cpp
** File description:
** Time.cpp
*/

#include <polymorph/Types.hpp>
#include <Core/Engine.hpp>
#include <Core/Component/base/Component.hpp>
#include "Utilities/Time.hpp"




namespace polymorph::engine
{


    Time::Time() : _lastTime(Clock::now()) {}

    void Time::computeDeltaTime()
    {
        auto now = Clock::now();
        std::chrono::duration<double> diff = now - _lastTime;

        deltaTime = diff.count();
        if (deltaTime > 0.016)
            deltaTime = 0.016;
        _lastTime = now;
    }

    std::string Time::formatToMinutes(float time)
    {
        auto minutes = static_cast<int>(std::floor(time / 60));
        auto seconds = time - static_cast<int>((minutes * 60));
        std::string m = ((minutes < 10) ? "0" : "") + std::to_string(minutes);
        std::string s = ((seconds < 10) ? "0" : "") + std::to_string(
                static_cast<int>(seconds));
        return m + ":" + s;
    }

    void Timer::tick()
    {
        actual += time.deltaTime;
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

    Timer::Timer(Time &time, double delay) : time(time), delay(delay)
    {

    }

    Timer::Timer(Engine &game, double delay) : time(game.getTime()), delay(delay)
    {

    }

    Timer::Timer(GameObject &object, double delay) : time(object->time), delay(delay)
    {

    }

    Timer::Timer(Component &component, double delay) : time(component.time), delay(delay)
    {

    }
}