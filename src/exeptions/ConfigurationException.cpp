/*
** EPITECH PROJECT, 2020
** ConfigurationException.cpp
** File description:
** header for ConfigurationException.c
*/

#include "ConfigurationException.hpp"

ConfigurationException::ConfigurationException(std::string message,
Logger::severity level) : ExceptionLogger("[Corrupted files] " + message, level)
{}
