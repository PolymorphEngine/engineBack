/*
** EPITECH PROJECT, 2020
** DynamicLoader.cpp
** File description:
** header for DynamicLoader.c
*/

#include "DynamicLoader/DynamicLoader.hpp"
#include "GraphicalException.hpp"


DynamicLibLoader::~DynamicLibLoader()
{
    if (_handler != nullptr)
        dlclose(_handler);
}

void DynamicLibLoader::loadHandler(std::string libPath)
{

    //TODO: check close error ?
    if (_handler != nullptr)
        dlclose(_handler);

    _handler = dlopen(libPath.c_str(), RTLD_LAZY);

    if (_handler == nullptr)
        throw ExceptionLogger("Failed to dl open library at path: " + libPath);
}

