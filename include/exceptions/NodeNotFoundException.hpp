/*
** EPITECH PROJECT, 2020
** NodeNotFoundException.hpp.h
** File description:
** header for NodeNotFoundException.c
*/

#ifndef MYXMLPP_NODENOTFOUNDEXCEPTION_HPP
#define MYXMLPP_NODENOTFOUNDEXCEPTION_HPP

#include <string>
#include "Exception.hpp"

namespace myxmlpp {
    /**
     * Exception to throw when a node is not found in findChild* methods
     */
    class NodeNotFoundException: public Exception {
        protected:
            /**
             * Tag of the wanted node
             */
            std::string _tag;

        public:
            NodeNotFoundException(const std::string& tag,
                                  const std::string& file,
                                  int line,
                                  const std::string& description="") noexcept;

            std::string getTag() const noexcept;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            std::string baseWhat() const noexcept override;

            ~NodeNotFoundException() noexcept override
            = default;
    };
}


#endif //MYXMLPP_NODENOTFOUNDEXCEPTION_HPP
