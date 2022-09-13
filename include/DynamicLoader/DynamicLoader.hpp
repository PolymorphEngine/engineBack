/*
** EPITECH PROJECT, 2020
** DynamicLoader.hpp
** File description:
** header for DynamicLoader.c
*/

#ifndef ENGINE_DYNAMICLOADER_HPP
#define ENGINE_DYNAMICLOADER_HPP

#include <iostream>
#include <memory>
#include <vector>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <dlfcn.h> //dlopen
#endif

class DynamicLibLoader
{
    public:
        ~DynamicLibLoader();

    protected:
#ifdef _WIN32
        HINSTANCE _handler = nullptr;
#else
        void *_handler = nullptr;
#endif
     //   void *_handler = nullptr;

    public:
        /**
         * @details Close the previous opened library (if one is open) and opens the one passed as parameter
         * @param libPath
         */
        void loadHandler(const std::string& libPath);


        template<typename T, typename API>
        static T loadSymbol(std::string name)
        {
#ifdef _WIN32
            T s = (T)GetProcAddress(API::getHandler(), name.c_str());
            if (s == nullptr)
                throw std::runtime_error("Failed to find symbol named: "+ name);
            return reinterpret_cast<T>(s);
#else
            void *symbol = dlsym(API::getHandler(), name.c_str());
            if (symbol == nullptr)
                throw std::runtime_error("Failed to find symbol named: "+ name);
            return reinterpret_cast<T>(symbol);
#endif
        }
    protected:
        void closeHandle();
};


#endif //ENGINE_DYNAMICLOADER_HPP
