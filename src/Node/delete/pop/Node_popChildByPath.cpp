/*
** EPITECH PROJECT, 2022
** Node_popChildByPath.cpp
** File description:
** Node_popChildByPath.cpp
*/

#include "Node.hpp"

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::popChildByPath(const std::string &path,
                              const std::string &tag,
                              char delimiter) noexcept
{
    try {
        std::shared_ptr<Node> childParent = findChildBySPath(path, delimiter);
        return childParent->popChild(tag);
    } catch (const std::exception &e) {}
    return {nullptr};
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::popChildBySPath(const std::string &path,
                               char delimiter) noexcept
{
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return popChildByPath(pathCpy, tag, delimiter);
}