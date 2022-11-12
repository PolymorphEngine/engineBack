/*
** EPITECH PROJECT, 2022
** Node_findChildrenR.cpp
** File description:
** Node_findChildrenR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

void myxmlpp::Node::_findChildrenRecursive(
        std::vector<std::shared_ptr<Node>> *children,
        const std::string &tag,
        int depth) const
{
    bool found = false;

    if (!depth)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    try {
        findChildren(tag, children);
        found = true;
    } catch (NodeNotFoundException& e) {}
    for (const auto& c : _children) {
        try {
            c->_findChildrenRecursive(children, tag, depth - 1);
            found = true;
        } catch (NodeNotFoundException& e) {}
    }
    if (!found)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::findChildrenR(const std::string &tag,
                             int maxDepth)  const
{
    std::vector<std::shared_ptr<Node>> children;

    try {
        _findChildrenRecursive(&children, tag, maxDepth);
    } catch (NodeNotFoundException& e) {
        if (maxDepth > 0 || maxDepth == -1)
            throw;
    }
    return children;
}