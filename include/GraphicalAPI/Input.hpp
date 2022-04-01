/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** header for Input.c
*/


#pragma once

#include "GraphicalAPI/arcade/IDisplayModule.hpp"
#include "GraphicalAPI.hpp"

namespace Polymorph
{
    
    class Input
    {
    
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
    
//////////////////////--------------------------/////////////////////////
    
    
    
///////////////////////////// PROPERTIES ////////////////////////////////
        public:
    
        private:




//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            static bool isKeyDown(arcade::KeyCode code);
            static bool isKeyUp(arcade::KeyCode code);
            static bool isKeyHold(arcade::KeyCode code);
            
            static bool isMouseButtonDown(arcade::KeyCode buttonNb);
            static bool isMouseButtonUp(arcade::KeyCode buttonNb);
            static bool isMouseButtonHold(arcade::KeyCode buttonNb);
            static std::vector<arcade::KeyCode> getCurrentInputs();

        private:
    
//////////////////////--------------------------/////////////////////////
    
    };
}



