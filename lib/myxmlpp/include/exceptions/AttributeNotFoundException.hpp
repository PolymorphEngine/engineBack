/*
** EPITECH PROJECT, 2020
** AttributeNotFoundException.hpp.h
** File description:
** header for AttributeNotFoundException.c
*/

#ifndef MYXMLPP_ATTRIBUTENOTFOUNDEXCEPTION_HPP
#define MYXMLPP_ATTRIBUTENOTFOUNDEXCEPTION_HPP

#include <string>
#include "Exception.hpp"

namespace myxmlpp {
    /**
     * Exception to throw when an attribute is not found in findAttribute*
     * methods
     */
    class AttributeNotFoundException: public Exception {
        protected:
            /**
             * Key of the anted attribute
             */
            std::string _key;

        public:
            AttributeNotFoundException(std::string  key,
                    const std::string& file,
                    int line,
                    const std::string& description="") noexcept;

            std::string getKey() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            std::string baseWhat() const noexcept override;

            ~AttributeNotFoundException() noexcept override = default;
    };
}


#endif //MYXMLPP_ATTRIBUTENOTFOUNDEXCEPTION_HPP
