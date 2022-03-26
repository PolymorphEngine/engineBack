/*
** EPITECH PROJECT, 2021
** NodeNotFoundException.cpp.cc
** File description:
** NodeNotFoundException.cpp.cc
*/


#include "NodeNotFoundException.hpp"

#include <utility>

myxmlpp::NodeNotFoundException::NodeNotFoundException(std::string  tag,
        const std::string& file,
        int line,
        const std::string& description) noexcept
    : _tag(std::move(tag)), Exception(file, line, description)
{
    build();
}

std::string myxmlpp::NodeNotFoundException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(": cannot find node ")
           + _tag;
}

std::string myxmlpp::NodeNotFoundException::getTag() const noexcept {
    return _tag;
}