/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::findChildren(const std::string &tag) const
{
    std::vector<std::shared_ptr<Node>> list;

    for (auto & it : _children) {
        if (it->getTag() == tag)
            list.push_back(it);
    }
    if (list.empty())
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    return list;
}

void myxmlpp::Node::findChildren(const std::string &tag,
        std::vector<std::shared_ptr<myxmlpp::Node>> *children)  const
{
    std::size_t backupSize = children->size();

    for (auto & it : _children) {
        if (it->getTag() == tag)
            children->push_back(it);
    }
    if (children->size() == backupSize)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);

}