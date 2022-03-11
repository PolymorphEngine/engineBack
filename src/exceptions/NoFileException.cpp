/*
** EPITECH PROJECT, 2021
** NoFileException.cpp.cc
** File description:
** NoFileException.cpp.cc
*/

#include <string>
#include "NoFileException.hpp"

myxmlpp::NoFileException::NoFileException(const std::string &filepath,
                                          const std::string &file, int line)
        :FileException(filepath, file, line) {
    build();
}

std::string myxmlpp::NoFileException::baseWhat() const noexcept {
    return FileException::baseWhat()
           + std::string(": no file at the given filepath ")
           + _filepath;
}
