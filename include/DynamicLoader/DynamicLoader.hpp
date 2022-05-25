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
#if _WIN32
    #include <Windows.h>
#else
    #include <dlfcn.h> //dlopen
#endif

class DynamicLibLoader
{
    public:
        ~DynamicLibLoader();

    protected:
        void *_handler = nullptr;


    public:
        /**
         * @details Close the previous opened library (if one is open) and opens the one passed as parameter
         * @param libPath
         */
        void loadHandler(const std::string& libPath);


    protected:
        template<typename T, typename API>
        static T loadSymbol(std::string name)
        {
            auto handler = API::getHandler();

            if (handler == nullptr)
                return nullptr;


#if _WIN32
            void *symbol = (void *)GetProcAddress((HMODULE)handler, name.c_str());
#else
            void *symbol = dlsym(handler, name.c_str());
#endif

            if (symbol == nullptr)
                throw std::runtime_error("Failed to find symbol named: "+ name);
            return reinterpret_cast<T>(symbol);
        }

        void closeHandle();
};


#endif //ENGINE_DYNAMICLOADER_HPP
