/*
** EPITECH PROJECTNode 2022
** Node_findChildByPath.cpp
** File description:
** Node_findChildByPath.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildByPath, not_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("path/fictive", "!exist");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildByPath, half_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("Blocks/fictive", "Block1");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildByPath, starting_from_nowhere_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("MiddleSub2Block1", "MiddleSub3Block2");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildByPath, hard_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1", "MiddleSub3Block2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildByPath, hard_2_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildByPath("TailBlock/SubBlock2/Sub2Block1/Sub3Block2", "DepthTest");
        if (n->findAttribute("d")->getValue() != "Last")
            cr_expect(0);
        else
            cr_expect(1);
    } catch (myxmlpp::Exception &e) {
        cr_expect(0);
    }
}
