/*
** EPITECH PROJECT, 2022
** Node_popChildR.cpp
** File description:
** Node_popChildR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::vector<std::shared_ptr<myxmlpp::Node>>::iterator
myxmlpp::Node::_findChildIt(const std::string& tag)
{
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::_popChildRecursive(const std::string &tag, int depth)
{
    if (!depth)
        return std::make_shared<Node>(nullptr);
    try {
        auto itToPop = _findChildIt(tag);
        std::shared_ptr<Node> toPop = *itToPop;
        _children.erase(itToPop);
        return toPop;
    } catch (NodeNotFoundException& e) {}
    for (const auto& c : _children) {
        try {
            return c->_findChildRecursive(tag, depth - 1);
        } catch (NodeNotFoundException& e) {}
    }
    return {nullptr};
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::popChildR(const std::string &tag, int maxDepth) noexcept
{
    return _popChildRecursive(tag, maxDepth);
}