/*
** EPITECH PROJECT, 2020
** AssetManager.hpp
** File description:
** header for AssetManager.c
*/


#pragma once


#include <string>
#include <vector>

class AssetManager
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
    public:

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:
        std::vector<std::string> _assetsFolders;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        std::string tryResolve(const std::string &resource);
        void addPath(const std::string &path);


    private:

//////////////////////--------------------------/////////////////////////

};
