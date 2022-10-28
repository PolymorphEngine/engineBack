/*
** EPITECH PROJECT, 2020
** ExceptionLogger.hpp
** File description:
** header for ExceptionLogger.c
*/

#ifndef ENGINE_EXCEPTIONLOGGER_HPP
#define ENGINE_EXCEPTIONLOGGER_HPP

#include <exception>
#include "Debug/Log/Logger.hpp"

namespace polymorph::engine
{
    class ExceptionLogger : public std::exception
    {
    
    ///////////////////////////////// Constructors /////////////////////////////////
    
        public:
            explicit ExceptionLogger(std::string message,
            Logger::severity level = Logger::severity::MAJOR);
    
    ///////////////////////////--------------------------///////////////////////////
    
    
    
    ///////////////////////////////// Properties /////////////////////////////////
    
        private:
            std::string _message;
            Logger::severity _level;
    
    ///////////////////////////--------------------------///////////////////////////
    
    
    
    ///////////////////////////////// Methods /////////////////////////////////
    
        public:
            const char *what() const noexcept override;
    
    ///////////////////////////--------------------------///////////////////////////
    
    };
}


#endif //ENGINE_EXCEPTIONLOGGER_HPP
