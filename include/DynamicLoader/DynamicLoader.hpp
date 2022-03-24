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
#include <dlfcn.h>

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

            void *symbol = dlsym(handler, name.c_str());

            if (symbol == nullptr)
                throw std::runtime_error("Failed to find symbol named: "+ name);
            return reinterpret_cast<T>(symbol);
        }
};


#endif //ENGINE_DYNAMICLOADER_HPP
