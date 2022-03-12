/*
** EPITECH PROJECT, 2020
** MissingAttribute.hpp
** File description:
** header for MissingAttribute.c
*/

#ifndef ENGINE_MISSINGATTRIBUTE_HPP
#define ENGINE_MISSINGATTRIBUTE_HPP


#include "ConfigurationException.hpp"

class MissingAttribute : public ConfigurationException
{
    public:
        explicit MissingAttribute(std::string attribute, std::string nodeName, Logger::severity level = Logger::MINOR);
};


#endif //ENGINE_MISSINGATTRIBUTE_HPP
