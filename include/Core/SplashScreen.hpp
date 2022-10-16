/*
** EPITECH PROJECT, 2020
** SplashScreen.hpp
** File description:
** header for SplashScreen.c
*/


#pragma once

#include "Utilities/Time.hpp"
#include "GraphicalAPI/modules/TextureModule.hpp"

namespace Polymorph
{
    class SplashScreen
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SplashScreen(std::string path);


            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            Timer _fadeOutTimer = Timer(0.005);
            std::unique_ptr<TextureModule> _icon;
            std::unique_ptr<TextModule> _label;
            std::vector<std::unique_ptr<TextModule>> _authors;
            bool _done = false;
            unsigned char _currentAlpha = 255;


            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            bool isFinished();

            void update();


        private:


            //////////////////////--------------------------/////////////////////////

    };
}
