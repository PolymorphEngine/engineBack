/*
** EPITECH PROJECT, 2020
** ExceptionLogger.cpp
** File description:
** header for ExceptionLogger.c
*/

#include "Debug/Exceptions/ExceptionLogger.hpp"

#include <utility>

namespace Ex = polymorph::engine;

Ex::ExceptionLogger::ExceptionLogger(std::string message, Logger::severity level)
{
    _message = std::move(message);
    _level = level;
}

const char *Ex::ExceptionLogger::what() const noexcept
{
    Logger::Log(_message, _level);

    return _message.c_str();
}
