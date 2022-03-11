/*
** EPITECH PROJECT, 2022
** Node_findChildR.cpp
** File description:
** Node_findChildR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::_findChildRecursive(const std::string &tag, int depth) const
{
    if (!depth)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    try {
        return findChild(tag);
    } catch (NodeNotFoundException& e) {}
    for (const auto& c : _children) {
        try {
            return c->_findChildRecursive(tag, depth - 1);
        } catch (NodeNotFoundException& e) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::findChildR(const std::string &tag,
                          int maxDepth) const
{
    return _findChildRecursive(tag, maxDepth);
}