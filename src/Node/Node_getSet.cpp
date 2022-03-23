/*
** EPITECH PROJECT, 2022
** NodeGetSet.cpp
** File description:
** NodeGetSet.cpp
*/

#include "Node.hpp"

std::string myxmlpp::Node::getTag() const noexcept
{
    return _tag;
}

std::string myxmlpp::Node::getData() const noexcept
{
    return _data;
}

myxmlpp::Node *myxmlpp::Node::getParent() const noexcept
{
    return _parent;
}

void myxmlpp::Node::setTag(const std::string &tag) noexcept {
    _tag = tag;
}

void myxmlpp::Node::setData(const std::string &data) noexcept {
    _data = data;
}

void myxmlpp::Node::setParent(myxmlpp::Node *parent) noexcept {
    _parent = parent;
}

bool myxmlpp::Node::allEmpty() const noexcept {
    return empty() && noAttributes();
}