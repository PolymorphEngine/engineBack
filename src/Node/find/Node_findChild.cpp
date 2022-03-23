/*
** EPITECH PROJECT, 2022
** Node_findChild.cpp
** File description:
** Node_findChild.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::findChild(const std::string& tag) const
{
    for (auto & it : _children) {
        if (it->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}