/*
** EPITECH PROJECT, 2020
** Symbols.hpp
** File description:
** header for Symbols.c
*/

#ifndef PLUGIN_TEMPLATE_SYMBOLS_HPP
#define PLUGIN_TEMPLATE_SYMBOLS_HPP

// Define EXPORT_MODULE for any platform
#if defined _WIN32 || defined __CYGWIN__
    #ifdef WIN_EXPORT
    // Exporting...
        #ifdef __GNUC__
          #define EXPORT_MODULE extern "C" __attribute__ ((dllexport))
        #else
          #define EXPORT_MODULE extern "C" __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #ifdef __GNUC__
            #define EXPORT_MODULE extern "C" __attribute__ ((dllimport))
        #else
            #define EXPORT_MODULE extern "C" __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #endif
    #define NOT_EXPORT_MODULE
#else
    #if __GNUC__ >= 4
        #define EXPORT_MODULE extern "C" __attribute__ ((visibility ("default")))
        #define NOT_EXPORT_MODULE  __attribute__ ((visibility ("hidden")))
    #else
        #define EXPORT_MODULE extern "C" 
        #define NOT_EXPORT_MODULE extern "C" 
    #endif
#endif

#include "IPlugin.hpp"
#include "../Core/Engine.hpp"
#include <memory>

#define STR(a) #a

#define SYMBOL_EXPORT(ns, name, ret, def)           \
namespace ns {                           \
    EXPORT_MODULE ret *create##name def;     \
    namespace Symbols {                         \
        const std::string create##name = "create" STR(name);   \
        using create##name##DEF = ret *(*)def;          \
    }                                           \
}

#define SYMBOL_EXPORT_DESTRUCTOR(ns, name, ret)           \
namespace ns {                           \
    EXPORT_MODULE void destoy##name(ret *name) ;     \
    namespace Symbols {                         \
        const std::string destroy##name = "destroy" STR(name);   \
        using destroy##name##DEF = void (*)(ret *);          \
    }                                           \
}



SYMBOL_EXPORT(polymorph::engine, Plugin, IPlugin, (Config::XmlNode &data, Engine &game, std::string PluginsPath))


#endif //PLUGIN_TEMPLATE_SYMBOLS_HPP
