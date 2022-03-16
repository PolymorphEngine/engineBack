/*
** EPITECH PROJECT, 2020
** ExceptionLogger.cpp
** File description:
** header for ExceptionLogger.c
*/

#include "Engine/Exceptions/ExceptionLogger.hpp"

ExceptionLogger::ExceptionLogger(std::string message, Logger::severity level)
{
    _message = message;
    _level = level;
}

const char *ExceptionLogger::what() const noexcept
{
    Logger::log(_message, _level);
    return _message.c_str();
}
