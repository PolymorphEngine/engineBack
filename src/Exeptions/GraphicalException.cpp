/*
** EPITECH PROJECT, 2020
** GraphicalException.cpp
** File description:
** header for GraphicalException.c
*/

#include "GraphicalException.hpp"

GraphicalException::GraphicalException(const std::string& apiMessage,
Logger::severity level)
: ExceptionLogger("[Graphical issue] " + apiMessage, level)
{

}
