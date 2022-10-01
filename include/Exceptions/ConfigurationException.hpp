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
///////////////////////////////// Constructors /////////////////////////////////

    public:
        explicit ConfigurationException(const std::string &message,
                                        Logger::severity level = Logger::severity::MAJOR);

///////////////////////////--------------------------///////////////////////////

};


#endif //ENGINE_CONFIGURATIONEXCEPTION_HPP
