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
          #define EXPORT_MODULE __attribute__ ((dllexport))
        #else
          #define EXPORT_MODULE __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #ifdef __GNUC__
            #define EXPORT_MODULE __attribute__ ((dllimport))
        #else
            #define EXPORT_MODULE __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #endif
    #define NOT_EXPORT_MODULE
#else
    #if __GNUC__ >= 4
        #define EXPORT_MODULE __attribute__ ((visibility ("default")))
        #define NOT_EXPORT_MODULE  __attribute__ ((visibility ("hidden")))
    #else
        #define EXPORT_MODULE
        #define NOT_EXPORT_MODULE
    #endif
#endif

#include "IPlugin.hpp"
#include "../Core/Engine.hpp"


#define SYMBOL_EXPORT(ns, name, ret, def)           \
namespace ns {                           \
    extern "C" EXPORT_MODULE ret *name def;     \
    namespace Symbols {                         \
        const std::string name = #name;   \
        using name##DEF = ret *(*)def;          \
    }                                           \
}

SYMBOL_EXPORT(Polymorph, loadPlugin, IPlugin, (Config::XmlNode &data, Engine &game, std::string PluginsPath))


#endif //PLUGIN_TEMPLATE_SYMBOLS_HPP
