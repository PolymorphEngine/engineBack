/*
** EPITECH PROJECTNode 2022
** Node_findAttribute.cpp
** File description:
** Node_findAttribute.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "Node.hpp"
#include "AttributeNotFoundException.hpp"

Test(Node_findAttribute, not_exist)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("!exist");
        cr_expect(0);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findAttribute, first_attr)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("key");
        cr_expect(1);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findAttribute, second_attr)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("key2");
        cr_expect(1);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        cr_expect(0);
    }
}