/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildrenBySPath, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildrenBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2/NotFound");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildrenBySPath, good_path)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2/MiddleSub4Block");

        cr_expect_eq(children.size(), 4);
        cr_expect(children[3]->findAttribute("d")->getValue() == "last");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}