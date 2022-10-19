/*
** EPITECH PROJECT, 2020
** DynamicLoader.cpp
** File description:
** header for DynamicLoader.c
*/

#include "DynamicLoader/DynamicLoader.hpp"
#include "Polymorph/Debug.hpp"


DynamicLibLoader::~DynamicLibLoader()
{
    if (_handler != nullptr)
        closeHandle();
    _handler = nullptr;
}

void DynamicLibLoader::loadHandler(const std::string& libPath)
{

    if (_handler != nullptr)
        closeHandle();

#if _WIN32
    _handler = LoadLibrary(TEXT(libPath.c_str()));
#else
    _handler = dlopen(libPath.c_str(), RTLD_LAZY);
#endif

    if (_handler == nullptr)
        throw ExceptionLogger("[DynamicLoader] Failed to dl open library at path: " + libPath);
    _libPath = libPath;
}

void DynamicLibLoader::closeHandle() {
    #if _WIN32
    FreeLibrary((HMODULE)_handler);
#else
    dlclose(_handler);
#endif
}
