/*
** EPITECH PROJECTNode 2022
** Node_findChildBySPath.cpp
** File description:
** Node_findChildBySPath.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildBySPath, not_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("path/fictive/!exist");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildBySPath, half_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("Blocks/fictive/Block1");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildBySPath, starting_from_nowhere_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("MiddleSub2Block1/MiddleSub3Block2");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildBySPath, hard_good_path) { 
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildBySPath, hard_2_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildBySPath("TailBlock/SubBlock2/Sub2Block1/Sub3Block2/DepthTest");
        if (n->findAttribute("d")->getValue() != "Last")
            cr_expect(0);
        else
            cr_expect(1);
    } catch (myxmlpp::Exception &e) {
        cr_expect(0);
    }
}
