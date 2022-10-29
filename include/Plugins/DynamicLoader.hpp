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

namespace polymorph::engine
{
    class DynamicLibLoader
    {
        public:
    
            DynamicLibLoader() = default;
    
            ~DynamicLibLoader();
    
            DynamicLibLoader(const DynamicLibLoader &) = delete;
            DynamicLibLoader(DynamicLibLoader &&) noexcept;
    
        protected:
    #ifdef _WIN32
            HINSTANCE _handler = nullptr;
    #else
            void *_handler = nullptr;
    #endif
            std::string _libPath;
            //   void *_handler = nullptr;
    
        public:
            /**
             * @details Close the previous opened library (if one is open) and opens the one passed as parameter
             * @param libPath
             */
            void loadHandler(const std::string &libPath);
    
            template<typename T>
            T loadSymbol(std::string name, bool no_except = false)
            {
    #ifdef _WIN32
                T s = (T) GetProcAddress(_handler, name.c_str());
    #else
                void *s = dlsym(_handler, name.c_str());
    #endif
                if (s == nullptr && !no_except)
                    throw std::runtime_error("[DynamicLoader] Failed to find symbol named: " + name + "from lib: " + _libPath + ", type: " + typeid(T).name());
                return reinterpret_cast<T>(s);
            }
    
        protected:
            void closeHandle();
    };
}


#endif //ENGINE_DYNAMICLOADER_HPP
