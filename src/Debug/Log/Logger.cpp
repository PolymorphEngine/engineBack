/*
** EPITECH PROJECT, 2020
** Logger.cpp
** File description:
** header for Logger.c
*/

#include <ctime>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <utility>
#include "Debug/Log/Logger.hpp"

namespace polymorph::engine
{
    void Logger::log(const std::string& message, std::string specificFile,
                     Logger::severity level)
    {
        if (_logInstance.empty())
            initLogInstance();
    
        _logFile(message, std::move(specificFile), level);
        _consoleLog(message, level);
    }
    
    void Logger::log(const std::string& message, Logger::severity level)
    {
        if (_logInstance.empty())
            initLogInstance();
    
        _logFile(message, level);
        _consoleLog(message, level);
    }
    
    void Logger::initLogInstance(Mode mode)
    {
        _mode = mode;
    
        _logInstance = getTimeNow("%F_%X");
    }
    
    void Logger::_logFile(const std::string& message, Logger::severity level)
    {
        if (_mode == RELEASE_MODE && level == DEBUG)
            return;
        auto filepath = _logDir + "/"+ _logInstance + ".log";
        std::fstream file(filepath, std::ios_base::out|std::ios_base::app);
    
        if (!file.is_open())
            throw std::runtime_error("Failed to open log file");
    
        file << getTimeNow("%X") + " : " + severity_to_string(level) + " | " + message << std::endl;
        file.close();
    }
    
    std::string Logger::getTimeNow(const std::string& flags)
    {
        char buffer[80];
        time_t rawtime;
        struct tm * timeinfo;
    
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        std::strftime(buffer, 80, flags.c_str(), timeinfo);
        std::string s;
        s+= buffer;
    #ifdef _WIN32
        std::replace(s.begin(), s.end(),':', '.');
    #endif
        return s;
    }
    
    std::string Logger::severity_to_string(Logger::severity level)
    {
        switch (level)
        {
            case INFO:
                return "INFO";
            case DEBUG:
                return "DEBUG";
            case MINOR:
                return "MINOR";
            case MAJOR:
                return "MAJOR";
        }
        return "";
    }
    
    void
    Logger::_logFile(const std::string& message, const std::string& filepath, Logger::severity level)
    {
        if (_mode == RELEASE_MODE && level == DEBUG)
            return;
    
        std::fstream file(_logDir + "/" + filepath + ".log", std::ios_base::out|std::ios_base::app);
    
        if (!file.is_open())
            throw std::runtime_error("Failed to open log file");
    
        file << getTimeNow("%X") + " : " + severity_to_string(level) + " | " + message << std::endl;
        file.close();
    }
    
    void Logger::_consoleLog(const std::string& message, Logger::severity level)
    {
        if (_mode == RELEASE_MODE && level == DEBUG)
            return;
    
        std::cout << "[" + getTimeNow("%X") + "] : " + severity_to_color(level) +
                     severity_to_string(level) + " | " + message + RESET << std::endl;
    
    }
    
    void Logger::setLogDir(const std::string& logDir)
    {
        _logDir = logDir;
        if (!std::filesystem::is_directory(logDir))
            std::filesystem::create_directory(logDir);
    }
    
    void Logger::setLogInstanceName(const std::string& logInstanceName)
    {
        _logInstance = logInstanceName + "_" + getTimeNow("%F_%X");
    }
    
    std::string Logger::severity_to_color(Logger::severity level)
    {
        switch (level) {
            case DEBUG:
                return GREEN;
            case INFO:
                return WHITE;
            case MINOR:
                return YELLOW;
            case MAJOR:
                return RED;
            default:
                return WHITE;
        }
    }
    
    bool Logger::isDebugBuild()
    {
        return (_mode == DEBUG_MODE);
    }

    void Logger::Log(const std::string &message, Logger::severity level)
    {
        std::cout << "[" + getTimeNow("%X") + "] : " + severity_to_color(level) +
        severity_to_string(level) + " | " + message + RESET << std::endl;
    }
}
