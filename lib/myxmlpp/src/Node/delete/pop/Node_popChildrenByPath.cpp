/*
** EPITECH PROJECT, 2022
** Node_popChildrenByPath.cpp
** File description:
** Node_popChildrenByPath.cpp
*/

#include "Node.hpp"

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::popChildrenByPath(const std::string &path,
                                 const std::string &tag,
                                 char delimiter) noexcept
{
    try {
        std::shared_ptr<Node> childrenParent = findChildBySPath(path,
                                                                delimiter);
        return childrenParent->popChildren(tag);
    } catch (const std::exception &e) {}
    return {nullptr};
}

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::popChildrenBySPath(const std::string &path,
                                  char delimiter) noexcept
{
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return popChildrenByPath(pathCpy, tag, delimiter);
}