/*
** EPITECH PROJECT, 2022
** Node_rmChildR.cpp
** File description:
** Node_rmChildR.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildR(const std::string &tag, int maxDepth) noexcept
{
    popChildR(tag, maxDepth);
}