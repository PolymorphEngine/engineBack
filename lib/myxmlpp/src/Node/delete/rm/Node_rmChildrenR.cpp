/*
** EPITECH PROJECT, 2022
** Node_rmChildrenR.cpp
** File description:
** Node_rmChildrenR.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildrenR(const std::string &tag,
                                int maxDepth) noexcept
{
    auto children = popChildrenR(tag, maxDepth);
}