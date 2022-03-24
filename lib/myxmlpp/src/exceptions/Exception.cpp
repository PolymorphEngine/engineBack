/*
** EPITECH PROJECT, 2021
** Exception.cpp.cc
** File description:
** Exception.cpp.cc
*/

#include <iostream>
#include <sstream>
#include <utility>
#include "Exception.hpp"

myxmlpp::Exception::Exception(std::string file, int line,
                              std::string description) noexcept :
        _file(std::move(file)),
        _description(std::move(description))
{
    std::ostringstream str;
    str << line;
    _line = str.str();
}

const char *myxmlpp::Exception::what() const noexcept {
    return _errorMessage.c_str();
}

std::string myxmlpp::Exception::baseWhat() const noexcept{
    return std::string("\nError in ") +
           _file +
           std::string(" at line ") +
           _line;
}

std::string myxmlpp::Exception::details() const noexcept {
    if (!_description.empty())
        return std::string("\nOptionnal details : ")
               + _description
               + std::string("\n");
    else
        return std::string("\n");
}

const std::string &myxmlpp::Exception::getFile() const noexcept {
    return _file;
}

const std::string &myxmlpp::Exception::getLine() const noexcept {
    return _line;
}

void myxmlpp::Exception::build() noexcept {
    _errorMessage = baseWhat() + details();
}
