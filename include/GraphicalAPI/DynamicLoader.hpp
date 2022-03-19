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
#include <dlfcn.h>

class DynamicLibLoader
{
    public:
        ~DynamicLibLoader();
        
        
        /**
         * @details Close the previous opened library (if one is open) and opens the one passed as parameter
         * @param libPath 
         */
        void loadHandler(std::string libPath);
        
        template<typename T>
        static T loadSymbol(std::string name)
        {
            if (handler == nullptr)
                return nullptr;
            void *symbol = dlsym(handler, name.c_str());

            if (symbol == nullptr)
                throw std::runtime_error("Failed to find symbol named: "+ name);
            return reinterpret_cast<T>(symbol);
        }
    private:
        static inline void *handler = nullptr;
};


#endif //ENGINE_DYNAMICLOADER_HPP
