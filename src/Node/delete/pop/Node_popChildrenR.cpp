/*
** EPITECH PROJECT, 2022
** Node_popChildrenR.cpp
** File description:
** Node_popChildrenR.cpp
*/

#include "Node.hpp"

void
myxmlpp::Node::_popChildrenRecurs(std::vector<std::shared_ptr<Node>> &children,
                                  const std::string &tag,
                                  int depth)
{
    if (depth == 0)
        return;
    auto toPopList = _findChildrenIt(tag);

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        children.push_back(**it);
        _children.erase(*it);
    }
    for (auto it = _children.begin();
         it != _children.end(); ++it)
        (*it)->_popChildrenRecurs(children, tag, depth - 1);
}

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::popChildrenR(const std::string &tag,
                            int maxDepth) noexcept
{
    std::vector<std::shared_ptr<Node>> popped;

    _popChildrenRecurs(popped, tag, maxDepth);
    return popped;
}