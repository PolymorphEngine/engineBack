/*
** EPITECH PROJECT, 2022
** Node_findChildrenByPath.cpp
** File description:
** Node_findChildrenByPath.cpp
*/

#include "Node.hpp"

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::findChildrenByPath(const std::string &path,
                                  const std::string &tag,
                                  char delimiter) const
{
    auto parent = findChildBySPath(path, delimiter);

    return parent->findChildren(tag);
}
std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::findChildrenBySPath(const std::string &path,
                                   char delimiter) const
{
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return findChildrenByPath(pathCpy, tag, delimiter);
}