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

#define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#define NOVIRTUALKEYCODES // VK_*
#define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
#define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#define NOSYSMETRICS      // SM_*
#define NOMENUS           // MF_*
#define NOICONS           // IDI_*
#define NOKEYSTATES       // MK_*
#define NOSYSCOMMANDS     // SC_*
#define NORASTEROPS       // Binary and Tertiary raster ops
#define NOSHOWWINDOW      // SW_*
#define OEMRESOURCE       // OEM Resource values
#define NOATOM            // Atom Manager routines
#define NOCLIPBOARD       // Clipboard routines
#define NOCOLOR           // Screen colors
#define NOCTLMGR          // Control and Dialog routines
#define NODRAWTEXT        // DrawText() and DT_*
#define NOGDI             // All GDI defines and routines
#define NOKERNEL          // All KERNEL defines and routines
#define NOUSER     
//#define NONLS             // All NLS defines and routines
#define NOMB              // MB_* and MessageBox()
#define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE        // typedef METAFILEPICT
#define NOMINMAX          // Macros min(a,b) and max(a,b)
#define NOMSG             // typedef MSG and associated routines
#define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL          // SB_* and scrolling routines
#define NOSERVICE         // All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND           // Sound driver routines
#define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
#define NOWH              // SetWindowsHook and WH_*
#define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
#define NOCOMM            // COMM driver routines
#define NOKANJI           // Kanji support stuff.
#define NOHELP            // Help engine interface.
#define NOPROFILER        // Profiler interface.
#define NODEFERWINDOWPOS  // DeferWindowPos routines
#define NOMCX             // Modem Configuration Extensions

#include <Windows.h>

#undef near
#undef far

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
