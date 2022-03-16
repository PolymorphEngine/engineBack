/*
** EPITECH PROJECT, 2020
** MissingAttribute.cpp
** File description:
** header for MissingAttribute.c
*/

#include "Engine/Exceptions/configuration/MissingAttribute.hpp"

MissingAttribute::MissingAttribute(std::string attribute, std::string nodeName, Logger::severity level)
        : ConfigurationException("Missing attribute named: \'"+attribute+"\' in node named \'"+nodeName+"\'", level)
{}
