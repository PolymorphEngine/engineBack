/*
** EPITECH PROJECT, 2020
** DynamicLoader.cpp
** File description:
** header for DynamicLoader.c
*/

#include "GraphicalAPI/DynamicLoader.hpp"
#include "GraphicalException.hpp"

DynamicLibLoader::~DynamicLibLoader()
{
    if (handler != nullptr)
        dlclose(handler);
}

void DynamicLibLoader::loadHandler(std::string libPath)
{

    //TODO: check close error ?
    if (handler != nullptr)
        dlclose(handler);
    
    handler = dlopen(libPath.c_str(), RTLD_LAZY);

    if (handler == nullptr)
        throw GraphicalException("Failed to dl open library at path: " + libPath);
}
