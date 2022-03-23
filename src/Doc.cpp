/*
** EPITECH PROJECT, 2021
** Doc.cpp
** File description:
** Doc.cpp
*/


#include <filesystem>
#include <iostream>
#include "Doc.hpp"
#include "exceptions/FileException.hpp"
#include "ParsingException.hpp"
#include "NoFileException.hpp"
#include "PermissionDeniedException.hpp"

namespace fs = std::filesystem;
using fs::status;

void myxmlpp::Doc::_throwOpenError(const std::string &filepath,
                                   bool keepOpen)
{
    fs::perms perms = status(filepath).permissions();
    fs::perms rdwr = (fs::perms::others_read | fs::perms::others_write);
    if (!fs::exists(filepath))
        throw NoFileException(filepath, MYXMLPP_ERROR_LOCATION);
    else if ((keepOpen&& ((perms & rdwr) != rdwr))
    || (!keepOpen && ((perms & fs::perms::others_read) == fs::perms::none)))
        throw PermissionDeniedException(filepath, MYXMLPP_ERROR_LOCATION);
    throw myxmlpp::FileException(filepath, MYXMLPP_ERROR_LOCATION,
                                 "Cannot open file");
}

void myxmlpp::Doc::_readFile(const std::string& filepath, bool keepOpen)
{
    _filepath = filepath;
    std::stringstream strStream;
    _file.exceptions(std::ios::badbit | std::ios::failbit);

    try {
        _file.open(filepath.c_str(),
                   keepOpen ? std::ios::in | std::ios::out : std::ios::in);
    } catch (const std::ios_base::failure& e) {
        _throwOpenError(filepath, keepOpen);
    }
    strStream << _file.rdbuf();
    _content = strStream.str();
    if (!keepOpen)
        _file.close();
}

myxmlpp::Doc::Doc(const std::string& filepath, bool keepOpen)
        :_keepOpen(keepOpen)
{
    _readFile(filepath, keepOpen);
    _root = std::make_shared<Node>(nullptr, _content);
}

void myxmlpp::Doc::write(const std::string &filepathOverride) {
    if (!filepathOverride.empty())
        setFilepath(filepathOverride);
    if (!_keepOpen) {
        try {
            _file.open(_filepath.c_str(), std::fstream::out);
        } catch (const std::ios_base::failure &e) {
            _throwOpenError(_filepath, _keepOpen);
        }
    }
    _file << _root->asString();
    if (!_keepOpen)
        _file.close();
}

void myxmlpp::Doc::writeF(const std::string &filepathOverride) {
    if (!filepathOverride.empty())
        setFilepath(filepathOverride);
    if (!_keepOpen) {
        try {
            _file.open(_filepath.c_str(), std::fstream::out);
        } catch (const std::ios_base::failure &e) {
            _throwOpenError(_filepath, _keepOpen);
        }
    }
    _file << _root->asFString(0);
    if (!_keepOpen)
        _file.close();
}

const std::string &myxmlpp::Doc::getFilepath() const noexcept
{
    return _filepath;
}

void myxmlpp::Doc::setFilepath(const std::string &filepath)
{
    if (_keepOpen) {
        _file.close();
        try {
            _file.open(filepath.c_str(), std::ios::in | std::ios::out);
        } catch (const std::ios_base::failure& e) {
            _throwOpenError(filepath, _keepOpen);
        }
    }
    _filepath = filepath;
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Doc::getRoot() const noexcept
{
    return _root;
}
