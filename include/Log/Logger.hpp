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
        
        
        static inline std::string _logDir = "Logs/";
        static inline std::string _logInstance = "";
        static inline std::string _engineLogFile = "engine.log";
        static inline Mode m_mode = RELEASE_MODE;
};


#endif //ENGINE_LOGGER_HPP
