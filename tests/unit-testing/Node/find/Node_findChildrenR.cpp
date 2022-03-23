/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildrenR, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildrenR("!exist");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildrenR, one_level)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 1);

        cr_expect_eq(children.size(), 1);
        cr_expect(children[0]->findAttribute("d")->getValue() == "0");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_without_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest");

        cr_expect_eq(children.size(), 6);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_overkill_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 50);

        cr_expect_eq(children.size(), 6);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_depth4)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 4);

        cr_expect_eq(children.size(), 4);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_depth3)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 3);

        cr_expect_eq(children.size(), 3);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_no_search_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 0);

        cr_expect(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}