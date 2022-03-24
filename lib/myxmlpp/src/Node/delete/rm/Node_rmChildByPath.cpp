/*
** EPITECH PROJECT, 2022
** Node_rmChildByPath.cpp
** File description:
** Node_rmChildByPath.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildByPath(const std::string &path,
                                  const std::string &tag,
                                  char delimiter) noexcept
{
    popChildByPath(path, tag, delimiter);
}



void myxmlpp::Node::rmChildBySPath(const std::string &path,
                                   char delimiter) noexcept
{
    popChildBySPath(path, delimiter);
}