/*
** EPITECH PROJECT, 2020
** FileException.hpp.h
** File description:
** header for FileException.c
*/

#ifndef MYXML_FILEEXCEPTION_HPP
#define MYXML_FILEEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>
#include "Exception.hpp"

namespace myxmlpp {

    /**
     * Generic exception relative to file manipulation
     */
    class FileException: public myxmlpp::Exception {
        protected:
            /**
             * Path of the problematic file
             */
            std::string _filepath;

        public:
            FileException(const std::string&  filepath,
                          const std::string&  file,
                          int line,
                          const std::string& description="") noexcept;

            const std::string &getFilepath() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            std::string baseWhat() const noexcept override;

            ~FileException() noexcept override = default;
    };
}


#endif //MYXML_FILEEXCEPTION_HPP
