/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_popChildren, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("!exists");
        cr_expect(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_popChildren, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("Head");

        cr_expect_eq(children.size(), 1);
        cr_expect(children[0]->getTag() == "Head");
        auto found = d.getRoot()->findChildren("Head");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_popChildren, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("EmptyNode");

        cr_expect_eq(children.size(), 5);
        cr_expect(children[0]->getTag() == "EmptyNode");
        auto found = d.getRoot()->findChildren("EmptyNode");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}