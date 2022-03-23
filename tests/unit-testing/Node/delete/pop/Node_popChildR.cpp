/*
** EPITECH PROJECTNode 2022
** Node_findChild.cpp
** File description:
** Node_findChild.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "Node.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_popChildR, not_exist)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChildR("!exist");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_popChildR, simple)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        auto before = d.getRoot()->findChildrenR("DepthTest");
        d.getRoot()->popChildR("DepthTest");
        auto after = d.getRoot()->findChildrenR("DepthTest");
        cr_expect_eq(before.size() - 1, after.size());
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}