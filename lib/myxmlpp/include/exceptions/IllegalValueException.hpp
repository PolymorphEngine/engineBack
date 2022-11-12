/*
** EPITECH PROJECT, 2020
** IllegalValueException.hpp.h
** File description:
** header for IllegalValueException.c
*/

#ifndef MYXMLPP_ILLEGALVALUEEXCEPTION_HPP
#define MYXMLPP_ILLEGALVALUEEXCEPTION_HPP

#include <string>
#include "Exception.hpp"

namespace myxmlpp {
    /**
     * Exception that can be thrown by setters/getters of attributes value
     * methods
     */
    class IllegalValueException: public Exception {
        protected:
            /**
             * Key of the anted attribute
             */
            std::string _key;

            /**
             * Legal type for the operation
             */
             std::string _legalType;

        public:
            IllegalValueException(std::string legalType,
                                  std::string key,
                                  std::string file,
                                  int line,
                                  std::string description="") noexcept;

            std::string getKey() const;

            std::string getLegalType() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            std::string baseWhat() const noexcept override;

            ~IllegalValueException() noexcept override = default;
    };
}


#endif //MYXMLPP_ILLEGALVALUEEXCEPTION_HPP
