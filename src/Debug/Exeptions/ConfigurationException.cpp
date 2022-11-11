/*
** EPITECH PROJECT, 2020
** ConfigurationException.cpp
** File description:
** header for ConfigurationException.c
*/

#include "Debug/Exceptions/ConfigurationException.hpp"

namespace polymorph::engine
{
    ConfigurationException::ConfigurationException(const std::string& message,
    Logger::severity level) : ExceptionLogger("[Corrupted files] " + message, level)
    {}
}
