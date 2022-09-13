/*
** EPITECH PROJECT, 2022
** Node_rmChild.cpp
** File description:
** Node_rmChild.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChild(const std::string &tag) noexcept
{
    popChild(tag);
}