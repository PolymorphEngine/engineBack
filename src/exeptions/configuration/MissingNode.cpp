/*
** EPITECH PROJECT, 2020
** MissingNode.cpp
** File description:
** header for MissingNode.c
*/

#include "Engine/Exceptions/configuration/MissingNode.hpp"

MissingNode::MissingNode(std::string nodeName, Logger::severity level)
: ConfigurationException("Missing node named: \'"+nodeName+"\'", level)
{}
