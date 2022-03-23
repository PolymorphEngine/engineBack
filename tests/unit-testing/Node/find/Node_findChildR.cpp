/*
** EPITECH PROJECTNode 2022
** Node_findChildR.cpp
** File description:
** Node_findChildR.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildR, not_existR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("!exist");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildR, found_sub_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Block1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, not_exist_sub_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Block5");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildR, found_empty_inline_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyNode");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}


Test(Node_findChildR, found_empty_data_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyBlock");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_last_empty_data_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Tail");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_last_empty_inline_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyNode2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth1_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSubBlock1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth1_wchildren_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSubBlock2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth2_wchildren_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub2Block1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth2_last_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub2Block3");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth3_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub3Block2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth4_childR) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub4Block1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth1_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("SubBlock1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth1_wchildren_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("SubBlock2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth2_wchildren_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub2Block1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth2_last_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub2Block3");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth3_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub3Block2");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, found_subnode_depth4_childR_Hard) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub4Block1");
        cr_expect(1);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, subnode_depth_test_0) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("DepthTest", 0);
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildR, subnode_depth_test_1) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 1);
        if (n->findAttribute("d")->getValue() == "0")
            cr_expect(1);
        else
            cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, subnode_depth_test_2) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 2);
        if (n->findAttribute("d")->getValue() == "0")
            cr_expect(1);
        else
            cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, subnode_depth_test_3) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 3);
        if (n->findAttribute("d")->getValue() == "0")
            cr_expect(1);
        else
            cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, subnode_depth_test_4) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 4);
        if (n->findAttribute("d")->getValue() == "0")
            cr_expect(1);
        else
            cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildR, depth4_child_but_lower_max_depth) 
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub4Block2", 2);
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}