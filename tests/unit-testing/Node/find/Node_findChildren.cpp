/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildren, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildren("kappa");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildren, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildren("Head");

        cr_expect_eq(children.size(), 1);
        cr_expect(children[0]->getTag() == "Head");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildren, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildren("EmptyNode");

        cr_expect_eq(children.size(), 5);
        cr_expect(children[0]->getTag() == "EmptyNode");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}