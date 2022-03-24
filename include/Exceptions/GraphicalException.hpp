/*
** EPITECH PROJECT, 2020
** GraphicalException.hpp
** File description:
** header for GraphicalException.c
*/

#ifndef ENGINE_GRAPHICALEXCEPTION_HPP
#define ENGINE_GRAPHICALEXCEPTION_HPP


#include "ExceptionLogger.hpp"

class GraphicalException : public ExceptionLogger
{
///////////////////////////////// Constructors /////////////////////////////////
    public:
        explicit GraphicalException(const std::string& apiMessage, Logger::severity level = Logger::MAJOR);
///////////////////////////--------------------------///////////////////////////

};


#endif //ENGINE_GRAPHICALEXCEPTION_HPP
