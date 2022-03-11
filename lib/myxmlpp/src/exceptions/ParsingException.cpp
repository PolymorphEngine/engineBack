/*
** EPITECH PROJECT, 2021
** ParsingException.cpp
** File description:
** ParsingException.cpp
*/


#include "ParsingException.hpp"

#include <utility>

myxmlpp::ParsingException::ParsingException(
        std::string  content,
        const std::string& file,
        int line,
        const std::string& description) noexcept
        : _content(std::move(content)), Exception(file, line, description)
{
    build();
}

std::string myxmlpp::ParsingException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(": error while parsing file content : ")
           + _content;
}