/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** header for Input.c
*/


#pragma once

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
            std::map<arcade::KeyCode, bool> _pressedKeys;
            std::map<arcade::KeyCode, bool> _releasedKeys;
            std::map<arcade::KeyCode, bool> _holdedKeys;
    
//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            static bool isKeyDown(arcade::KeyCode code);
            static bool isKeyUp(arcade::KeyCode code);
            static bool isKeyHold(arcade::KeyCode code);
            
            static bool isMouseButtonDown(arcade::KeyCode buttonNb);
            static bool isMouseButtonUp(arcade::KeyCode buttonNb);
            static bool isMouseButtonHold(arcade::KeyCode buttonNb);
    
        private:
    
//////////////////////--------------------------/////////////////////////
    
    };
}



