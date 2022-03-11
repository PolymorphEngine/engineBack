/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_popChildrenR, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("!exists");
        cr_expect(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_popChildrenR, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("Head");

        cr_expect_eq(children.size(), 1);
        cr_expect(children[0]->getTag() == "Head");
        auto found = d.getRoot()->findChildrenR("Head");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_popChildrenR, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("DepthTest");

        cr_expect_eq(children.size(), 6);
        cr_expect(children[0]->getTag() == "DepthTest");
        auto found = d.getRoot()->findChildrenR("DepthTest");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}