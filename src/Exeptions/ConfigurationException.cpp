/*
** EPITECH PROJECT, 2020
** ConfigurationException.cpp
** File description:
** header for ConfigurationException.c
*/

#include "Exceptions/ConfigurationException.hpp"

ConfigurationException::ConfigurationException(const std::string& message,
Logger::severity level) : ExceptionLogger("[Corrupted files] " + message, level)
{}
