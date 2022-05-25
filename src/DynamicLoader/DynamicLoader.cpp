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
        closeHandle();
    _handler = nullptr;
}

void DynamicLibLoader::loadHandler(const std::string& libPath)
{

    //TODO: check close error ?
    if (_handler != nullptr)
        closeHandle();

#if _WIN32
    LoadLibrary(libPath.c_str());
#else
    dlopen(libPath.c_str(), RTLD_LAZY);
#endif

    if (_handler == nullptr)
        throw ExceptionLogger("Failed to dl open library at path: " + libPath);
}

void DynamicLibLoader::closeHandle() {
    #if _WIN32
    FreeLibrary((HMODULE)_handler);
#else
    dlclose(_handler);
#endif
}
