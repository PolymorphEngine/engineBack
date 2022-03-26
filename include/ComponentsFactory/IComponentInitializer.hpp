/*
** EPITECH PROJECT, 2020
** IComponentInitalizer
** File description:
** header for IComponentInitalizer.c
*/


#pragma once

#include <iostream>

namespace Polymorph
{
    class Component;
    
    class IComponentInitializer
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IComponentInitializer() = default;
    
//////////////////////--------------------------/////////////////////////
    
    
    
/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void build() = 0;
    
            virtual void reference() = 0;
            virtual std::string getType() const = 0;
            virtual std::shared_ptr<Component> operator*() = 0;
            virtual std::shared_ptr<Component> get() = 0;

        private:
    
//////////////////////--------------------------/////////////////////////

    };
}



