/*
** EPITECH PROJECT, 2020
** GraphicalException.cpp
** File description:
** header for GraphicalException.c
*/

#include "Debug/Exceptions/GraphicalException.hpp"

GraphicalException::GraphicalException(const std::string& apiMessage,
Logger::severity level)
: ExceptionLogger("[Graphical issue] " + apiMessage, level)
{

}
