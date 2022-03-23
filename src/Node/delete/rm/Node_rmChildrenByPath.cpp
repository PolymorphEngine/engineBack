/*
** EPITECH PROJECT, 2022
** Node_rmChildrenByPath.cpp
** File description:
** Node_rmChildrenByPath.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildrenByPath(const std::string &path,
                                     const std::string &tag,
                                     char delimiter) noexcept
{
    auto children = popChildrenByPath(path, tag, delimiter);
}


void myxmlpp::Node::rmChildrenBySPath(const std::string &path,
                                      char delimiter) noexcept
{
    auto children = popChildrenBySPath(path, delimiter);
}