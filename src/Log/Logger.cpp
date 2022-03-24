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
#include "Log/Logger.hpp"

void Logger::log(std::string message, std::string specificFile,
                 Logger::severity level)
{
    if (_logInstance.empty())
        initLogInstance();

    _logFile(message, specificFile, level);
    _consoleLog(message, level);
}

void Logger::log(std::string message, Logger::severity level)
{
    if (_logInstance.empty())
        initLogInstance();

    _logFile(message, level);
    _consoleLog(message, level);
}

void Logger::initLogInstance(Mode mode)
{
    _mode = mode;

    _logInstance = _getTimeNow("%F_%X");
}

void Logger::_logFile(std::string message, Logger::severity level)
{
    if (_mode == RELEASE_MODE && level == DEBUG)
        return;

    std::fstream file(_logDir + "/"+ _logInstance, std::ios_base::out|std::ios_base::app);

    if (!file.is_open())
        throw std::runtime_error("Failed to open log file");

    file << _getTimeNow("%X") +" : "+ _severity_to_string(level)+" | "+ message << std::endl;
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
    if (_mode == RELEASE_MODE && level == DEBUG)
        return;

    std::ofstream file(_logDir + "/" + filepath);

    if (!file.is_open())
        throw std::runtime_error("Failed to open log file");

    file << _getTimeNow("%X") +" : "+ _severity_to_string(level)+" | "+ message << std::endl;
    file.close();
}

void Logger::_consoleLog(std::string message, Logger::severity level)
{
    if (_mode == RELEASE_MODE && level == DEBUG)
        return;

    std::cout << "["+_getTimeNow("%X") +"] : "+ _severity_to_color(level)+_severity_to_string(level)+" | "+ message + RESET << std::endl;

}

void Logger::setLogDir(std::string logDir)
{
    _logDir = logDir;
    if (!std::filesystem::is_directory(logDir))
        std::filesystem::create_directory(logDir);
}

void Logger::setLogInstanceName(std::string logInstanceName)
{
    _logInstance = logInstanceName + "_" + _getTimeNow("%F_%X");
}

std::string Logger::_severity_to_color(Logger::severity level)
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
    }
}
