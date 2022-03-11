/*
** EPITECH PROJECT, 2020
** Exception.hpp.h
** File description:
** header for Exception.c
*/

#ifndef MYXMLPP_EXCEPTION_HPP
#define MYXMLPP_EXCEPTION_HPP

#include <string>

#define MYXMLPP_ERROR_LOCATION __FILE__, __LINE__

namespace myxmlpp {
    /**
     * Base exception for the lib, only containing mandatory informations to debug
     */
    class Exception: public std::exception {
        protected:
            /**
             * Short descripition of the error
             */
            std::string _description;

            /**
             * File in which the error was raised
             */
            std::string _file;

            /**
             * Line at which the error was raised
             */
            std::string _line;
            
            /**
             * Complete error message
             */
            std::string _errorMessage;

        public:
            Exception(std::string  file, int line,
                      std::string  description="") noexcept;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            const char *what() const noexcept override;
            
            void build() noexcept;

            /**
             * Error message displaying only file and line of the error
             * @return partial error message
             */
            virtual std::string baseWhat() const noexcept;

            virtual std::string details() const noexcept;

            const std::string &getFile() const noexcept;

            const std::string &getLine() const noexcept;

            ~Exception() noexcept override = default;
    };
}


#endif //MYXMLPP_EXCEPTION_HPP
