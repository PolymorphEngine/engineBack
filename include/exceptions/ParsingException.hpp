/*
** EPITECH PROJECT, 2020
** ParsingException.hpp
** File description:
** header for ParsingException.c
*/

#ifndef MYXMLPP_PARSINGEXCEPTION_HPP
#define MYXMLPP_PARSINGEXCEPTION_HPP

#include "Exception.hpp"

namespace myxmlpp {
    class ParsingException: public Exception {
        protected:
            /**
             * Key of the anted attribute
             */
            std::string _content;

        public:
            ParsingException(std::string  content,
                                       const std::string& file,
                                       int line,
                                       const std::string& description="") noexcept;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            std::string baseWhat() const noexcept override;

            ~ParsingException() noexcept override = default;
    };
}

#endif //MYXMLPP_PARSINGEXCEPTION_HPP
