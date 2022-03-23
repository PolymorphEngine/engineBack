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

Test(Node_popChild, not_exist)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChild("!exist");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_popChild, simple)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChild("Head");
        d.getRoot()->findChild("Head");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}