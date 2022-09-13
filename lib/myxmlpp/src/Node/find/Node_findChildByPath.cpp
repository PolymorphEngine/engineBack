/*
** EPITECH PROJECT, 2022
** Node_findChildByPath.cpp
** File description:
** Node_findChildByPath.cpp
*/

#include <sstream>
#include "Node.hpp"

std::vector<std::string> myxmlpp::Node::_split(const std::string &str,
                                               char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss (str);
    std::string item;

    while (getline(ss, item, delimiter)) {
        result.push_back (item);
    }

    return result;
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::_searchChild(const Node *current,
                            const std::vector<std::string> &tab,
                            std::vector<std::string>::iterator it)
{
    std::shared_ptr<Node> node = current->findChild(*it);

    if (++it != tab.end())
        return _searchChild(node.get(), tab, it);
    return node;
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::findChildByPath(const std::string &path,
                               const std::string &tag,
                               char delimiter) const
{
    std::vector<std::string> tab = _split(path, delimiter);
    auto it = tab.begin();
    auto node = _searchChild(this, tab, it);
    return node->findChild(tag);
}

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::findChildBySPath(const std::string &path, char delimiter) const
{
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return findChildByPath(pathCpy, tag, delimiter);
}