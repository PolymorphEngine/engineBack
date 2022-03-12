/*
** EPITECH PROJECT, 2020
** MissingNode.hpp
** File description:
** header for MissingNode.c
*/

#ifndef ENGINE_MISSINGNODE_HPP
#define ENGINE_MISSINGNODE_HPP


#include "ConfigurationException.hpp"

class MissingNode : public ConfigurationException
{
    public:
        explicit MissingNode(std::string nodeName, Logger::severity level = Logger::MINOR);
};


#endif //ENGINE_MISSINGNODE_HPP
