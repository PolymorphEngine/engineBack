/*
** EPITECH PROJECT, 2020
** FileException.cpp.c
** File description:
** FileException.cpp.c
*/

#include "FileException.hpp"

#include <utility>

myxmlpp::FileException::FileException(std::string filepath,
                                      const std::string &file,
                                      int line,
                                      const std::string &description) noexcept
    : _filepath(std::move(filepath)), Exception(file, line, description)
{
    build();
}

const std::string &myxmlpp::FileException::getFilepath() const {
    return _filepath;
}

std::string myxmlpp::FileException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(": error while interacting with file ")
           + _filepath;
}