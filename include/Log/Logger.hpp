/*
** EPITECH PROJECT, 2020
** Logger.hpp
** File description:
** header for Logger.c
*/

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <iostream>

class Logger
{
    public:
        static inline std::string BLACK = "\033[0;30m";   // BLACK
        static inline std::string RED = "\033[0;31m";     // RED
        static inline std::string GREEN = "\033[0;32m";   // GREEN
        static inline std::string YELLOW = "\033[0;33m";  // YELLOW
        static inline std::string BLUE = "\033[0;34m";    // BLUE
        static inline std::string PURPLE = "\033[0;35m";  // PURPLE
        static inline std::string CYAN = "\033[0;36m";    // CYAN
        static inline std::string WHITE = "\033[0;37m";
        static inline std::string RESET = "\033[0m";

        enum severity {
            DEBUG,
            INFO,
            MINOR,
            MAJOR
        };

        enum Mode {
            DEBUG_MODE,
            RELEASE_MODE
        };
        
        static void setLogDir(std::string logDir);
        static void setLogInstanceName(std::string logInstanceName);
        static void initLogInstance(Mode mode = RELEASE_MODE);
        
        static void Log(std::string message, severity level = INFO);
        static void Log(std::string message, std::string specificFile, severity level = INFO);
        
        
    private:
        static void _consoleLog(std::string message, severity level);
        static void _logFile(std::string message, severity level = INFO);
        static void _logFile(std::string message, std::string file, severity level = INFO);
        
        static std::string _getTimeNow(std::string flags);
        static std::string _severity_to_string(severity );
        static std::string _severity_to_color(severity );
        
        
        static inline std::string _logDir = "Logs/";
        static inline std::string _logInstance = "";
        static inline std::string _engineLogFile = "engine.log";
        static inline Mode m_mode = RELEASE_MODE;
};


#endif //ENGINE_LOGGER_HPP
