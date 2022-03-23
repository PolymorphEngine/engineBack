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

Test(Node_findChild, not_exist)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");
    
    try {
        d.getRoot()->findChild("!exist");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChild, not_found_sub_child)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChild("Block1");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChild, found_empty_inline_child)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChild("EmptyNode");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}


Test(Node_findChild, found_empty_data_child)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChild("EmptyBlock");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChild, found_last_empty_data_child)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChild("Tail");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChild, found_last_empty_inline_child)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChild("EmptyNode2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}