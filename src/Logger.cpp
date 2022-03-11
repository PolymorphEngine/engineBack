/*
** EPITECH PROJECT, 2020
** Logger.cpp
** File description:
** header for Logger.c
*/

#include <chrono>
#include <ctime>
#include <fstream>
#include "Log/Logger.hpp"

void Logger::Log(std::string message, std::string specificFile,
Logger::severity level)
{
    if (_logInstance.empty())
        initLogInstance();

    _logFile(message, specificFile, level);
}

void Logger::Log(std::string message, Logger::severity level)
{
    if (_logInstance.empty())
        initLogInstance();

    _logFile(message, level);
}

void Logger::initLogInstance(Mode mode)
{
    m_mode = mode;
    
    _logInstance = _getTimeNow("%F_%X");
}

void Logger::_logFile(std::string message, Logger::severity level)
{
    if (m_mode == RELEASE_MODE && level == DEBUG)
        return;
    
    std::ofstream file(_logDir + _logInstance + "/"+ _engineLogFile);
    
    if (!file.is_open())
        throw std::runtime_error("Failed to open log file");

    //TODO: coloration ?
    file << _getTimeNow("%X") +" : "+ _severity_to_string(level)+" "+ message << std::endl;
    file.close();
}

std::string Logger::_getTimeNow(std::string flags)
{
    char buffer[80];
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    std::strftime(buffer, 80, flags.c_str(), timeinfo);
    std::string s("");
    s+= buffer;
    return buffer;
}

std::string Logger::_severity_to_string(Logger::severity level)
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
Logger::_logFile(std::string message, std::string filepath, Logger::severity level)
{
    if (m_mode == RELEASE_MODE && level == DEBUG)
        return;

    std::ofstream file(_logDir + _logInstance + "/"+ filepath);

    if (!file.is_open())
        throw std::runtime_error("Failed to open log file");

    //TODO: coloration ?
    file << _getTimeNow("%X") +" : "+ _severity_to_string(level)+" "+ message << std::endl;
    file.close();
}

void Logger::_consoleLog(std::string message, Logger::severity level)
{
    //TODO: colorize text
    if (m_mode == RELEASE_MODE && level == DEBUG)
        return;

    std::cout << _getTimeNow("%X") +" : "+ _severity_to_string(level)+" "+ message << std::endl;

}

void Logger::setLogDir(std::string logDir)
{
    _logDir = logDir;
}

void Logger::setLogInstance(std::string logInstance)
{
    _logInstance = logInstance +"_"+ _getTimeNow("%F_%X");
}
