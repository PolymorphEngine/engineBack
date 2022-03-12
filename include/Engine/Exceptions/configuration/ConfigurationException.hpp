/*
** EPITECH PROJECT, 2020
** ConfigurationException.hpp
** File description:
** header for ConfigurationException.c
*/

#ifndef ENGINE_CONFIGURATIONEXCEPTION_HPP
#define ENGINE_CONFIGURATIONEXCEPTION_HPP



#include "Exceptions/ExceptionLogger.hpp"

class ConfigurationException : public ExceptionLogger
{
    public:
        explicit ConfigurationException(std::string message, Logger::severity level = Logger::severity::MAJOR);
        
};


#endif //ENGINE_CONFIGURATIONEXCEPTION_HPP
