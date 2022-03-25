/*
** EPITECH PROJECT, 2022
** Node_writeUtils.cpp
** File description:
** Node_writeUtils.cpp
*/

#include <Node.hpp>

std::string myxmlpp::Node::_strIndent(std::size_t indent) {
    std::string tab;

    for (std::size_t i = 0; i < indent; ++i)
        tab += '\t';
    return tab;
}

std::string myxmlpp::Node::_dumpAttrs() const noexcept {
    std::string format;
    bool firstAttr = true;

    for (auto &a : _attributes) {
        if (firstAttr) {
            format += ' ';
            firstAttr = false;
        }
        format += a->asString();
    }
    return format;
}


std::string myxmlpp::Node::_dumpAttrsF() const noexcept {
    std::string format;

    for (auto &a : _attributes) {
        format += ' ';
        format += a->asString();
    }
    return format;
}



std::string myxmlpp::Node::asString(bool includeChildren) const noexcept {
    std::string str("<");

    str += _tag;
    str += _dumpAttrs();
    if (!includeChildren) {
        str += "/>";
        return str;
    }
    if (!empty()) {
        str += ">";
        for (auto &c : _children)
            str += c->asString();
        str += std::string("</") + _tag + ">";
    } else
        str += "/>";
    return str;
}

std::string
myxmlpp::Node::asFString(size_t indent, bool includeChildren) const noexcept {
    std::string str = includeChildren ? _strIndent(indent) + "<" : "<";

    str += _tag;
    str += _dumpAttrsF();
    if (!includeChildren) {
        str += "/>\n";
        return str;
    }
    if (!empty()) {
        str += ">\n";
        for (auto &c : _children)
            str += c->asFString(indent + 1);
        str += _strIndent(indent)
               + std::string("</")
               + _tag
               + (_parent ? ">\n" : ">");
    } else
        str += _parent ? "/>\n" : "/>";
    return str;
}
