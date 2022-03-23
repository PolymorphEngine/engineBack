/*
** EPITECH PROJECT, 2022
** Node_popChildren.cpp
** File description:
** Node_popChildren.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::vector<std::vector<std::shared_ptr<myxmlpp::Node>>::iterator>
myxmlpp::Node::_findChildrenIt(const std::string &tag)
{
    std::vector<std::vector<std::shared_ptr<Node>>::iterator> list;

    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag)
            list.push_back(it);
    }
    return list;
}

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::popChildren(const std::string& tag) noexcept
{
    std::vector<std::vector<std::shared_ptr<Node>>::iterator> toPopList =
            _findChildrenIt(tag);
    std::vector<std::shared_ptr<Node>> toPopNodes;

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        toPopNodes.push_back(**it);
        _children.erase(*it);
    }
    return toPopNodes;
}