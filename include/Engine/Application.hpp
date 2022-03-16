/*
** EPITECH PROJECT, 2020
** Application.hpp
** File description:
** header for Application.cpp
*/

#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <iostream>
#include "Engine.hpp"

namespace Polymorph
{
    using ExitCode = int;

    class Application
    {

///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline std::string assetsPath = "";

            static inline std::shared_ptr<Engine> Game = nullptr;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static void quit(ExitCode code);
//////////////////////--------------------------/////////////////////////


    };
}

#endif //ENGINE_APPLICATION_HPP
