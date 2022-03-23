/*
** EPITECH PROJECT, 2021
** IllegalValueException.cpp.cc
** File description:
** IllegalValueException.cpp.cc
*/


#include "IllegalValueException.hpp"

#include <utility>

myxmlpp::IllegalValueException::IllegalValueException(std::string legalType,
                                                      std::string key,
                                                      std::string file,
                                                      int line,
                                                      std::string description)
                                                      noexcept
    : _legalType(std::move(legalType)), _key(std::move(key)),
      Exception(std::move(file), line, std::move(description))
{
    build();
}

std::string myxmlpp::IllegalValueException::getKey() const {
    return _key;
}

std::string myxmlpp::IllegalValueException::getLegalType() const {
    return _legalType;
}

std::string myxmlpp::IllegalValueException::baseWhat() const noexcept{
    return Exception::baseWhat()
           + std::string(": illegal for attribute ")
           + _key
           + std::string(", desired type ")
           + _legalType;
}
