/*
** EPITECH PROJECT, 2021
** Node.cpp.cc
** File description:
** Node.cpp.cc
*/

#include <utility>
#include "exceptions/AttributeNotFoundException.hpp"
#include "exceptions/ParsingException.hpp"
#include "Node.hpp"

myxmlpp::Node::Node(myxmlpp::Node *parent) noexcept
    : _parent(parent)
{}

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string tag,
                    std::vector<std::shared_ptr<Node>> children) noexcept
        : _parent(parent), _tag(std::move(tag)), _children(std::move(children))
{}

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string tag,
                    std::vector<std::shared_ptr<Attribute>> attributes,
                    std::vector<std::shared_ptr<Node>> children) noexcept
        : _parent(parent), _tag(std::move(tag)),
        _attributes(std::move(attributes)), _children(std::move(children))
{}

myxmlpp::Node::Node(myxmlpp::Node *parent,
                    std::string &str,
                    std::string &remaining)
        : _parent(parent)
{
    _parseNodeString(str, remaining);
}

myxmlpp::Node::Node(myxmlpp::Node *parent,
                    std::string &str)
        : _parent(parent)
{
    std::string remaining = str;

    _parseNodeString(str, remaining);
    if (!remaining.empty())
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "non matching characters in file");
}