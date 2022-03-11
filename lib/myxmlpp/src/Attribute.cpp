/*
** EPITECH PROJECT, 2021
** attribute.cpp.cc
** File description:
** attribute.cpp.cc
*/

#include <fstream>
#include <sstream>
#include "IllegalValueException.hpp"
#include "FileException.hpp"
#include "Attribute.hpp"
#include "Doc.hpp"
#include "ParsingException.hpp"

namespace myxmlpp {

    Attribute::Attribute(const std::string &key,
                         const std::string &value)
        : _key(key), _value(value)
    {}

    Attribute::Attribute(std::string &fileContent)
    {
        std::regex rgx("[\r\n\t\f\v ]*([a-zA-Z0-9_]+)=\"([^\"]*)\"");
        std::smatch matches;

        if (!std::regex_search(fileContent, matches, rgx)) {
            throw myxmlpp::ParsingException(fileContent, MYXMLPP_ERROR_LOCATION, "Cannot parse attribute string");
        }
        _key = matches[1].str();
        _value = matches[2].str();
    }

    std::string Attribute::asString() const noexcept {
        return _key + "=\"" + _value + "\"";
    }

    std::string Attribute::getKey() const noexcept
    {
        return _key;
    }

    void Attribute::setKey(const std::string &value) noexcept
    {
        _key = value;
    }

    std::string Attribute::getValue() const noexcept
    {
        return _value;
    }

    int Attribute::getValueInt() const
    {
        char *rest;
        int toReturn = (int) strtol(_value.c_str(), &rest, 10);

        if (*rest)
            throw IllegalValueException("Int", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
        return toReturn;
    }

    float Attribute::getValueFloat() const
    {
        char *rest;
        float toReturn = strtof(_value.c_str(), &rest);

        if (*rest)
            throw IllegalValueException("Float", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
        return toReturn;
    }

    bool Attribute::getValueBool(const std::string &trueElement,
                                 const std::string &falseElement) const
    {
        if (_value == trueElement)
            return true;
        else if (_value == falseElement)
            return false;
        else
            throw IllegalValueException("Float", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
    }

    Doc Attribute::getValueXmlDoc() const
    {
        Doc test(_value);
        return test;
    }

    std::ios_base::openmode Attribute::_getValueFileOpenMode(
            openMode_t mode)
    {
        switch (mode) {
            case OPENRD:
                return std::fstream::in;
            case OPENWR:
                return std::fstream::out;
            case OPENRDWR:
                return std::fstream::in | std::fstream::out;
            case OPENAPP:
                return std::fstream::in | std::fstream::out | std::fstream::app;
            default:
                return std::fstream::in;
        }
    }

    std::fstream Attribute::getValueFile(openMode_t mode) const
    {
        std::ios_base::openmode openMode = _getValueFileOpenMode(mode);

        try {
            return std::fstream(_value.c_str(), openMode);
        } catch (std::ios_base::failure &e) {
            throw FileException(_value, MYXMLPP_ERROR_LOCATION);
        }

    }

    void Attribute::setValue(const std::string &value) noexcept
    {
        _value = value;
    }

    void Attribute::setValueInt(int value)
    {
        std::stringstream ss;
        ss << value;
        _value = ss.str();
    }

    void Attribute::setValueFloat(float value)
    {
        std::stringstream ss;
        ss << value;
        _value = ss.str();
    }

    void Attribute::setValueBool(bool value,
                                 const std::string &trueElement,
                                 const std::string &falseElement)
    {
        setValue(value ? trueElement : falseElement);
    }
}