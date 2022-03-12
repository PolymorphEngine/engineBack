/*
** EPITECH PROJECT, 2020
** ExceptionLogger.hpp
** File description:
** header for ExceptionLogger.c
*/

#ifndef ENGINE_EXCEPTIONLOGGER_HPP
#define ENGINE_EXCEPTIONLOGGER_HPP

#include <exception>
#include "Log/Logger.hpp"

class ExceptionLogger : public std::exception
{
    public:
        explicit ExceptionLogger(std::string message, Logger::severity level = Logger::severity::MAJOR);
        const char *what() const noexcept override;

    private:
        std::string _message;
        Logger::severity _level;
};


#endif //ENGINE_EXCEPTIONLOGGER_HPP
