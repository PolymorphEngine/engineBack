/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <criterion/criterion.h>
#include "Attribute.hpp"
#include "IllegalValueException.hpp"

Test(Attribute_getValueBool, simple_true)
{
    std::string k = "key";
    std::string v = "true";
    myxmlpp::Attribute a(k, v);

    cr_expect(a.getValueBool());
}

Test(Attribute_getValueFalse, simple_false)
{
    std::string k = "key";
    std::string v = "false";
    myxmlpp::Attribute a(k, v);

    cr_expect(!a.getValueBool());
}

Test(Attribute_getValueBool, overriden_true_num)
{
    std::string k = "key";
    std::string v = "1";
    myxmlpp::Attribute a(k, v);

    cr_expect(a.getValueBool("1"));
}

Test(Attribute_getValueBool, overriden_false_num)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);

    cr_expect(!a.getValueBool("1", "0"));
}

Test(Attribute_getValueBool, overriden_true_str)
{
    std::string k = "key";
    std::string v = "TRUE";
    myxmlpp::Attribute a(k, v);

    cr_expect(a.getValueBool("TRUE"));
}

Test(Attribute_getValueBool, overriden_false_str)
{
    std::string k = "key";
    std::string v = "FALSE";
    myxmlpp::Attribute a(k, v);

    cr_expect(!a.getValueBool("TRUE", "FALSE"));
}

Test(Attribute_getValueBool, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);
    
    try {
        bool i = a.getValueBool();
        cr_expect(0);
    } catch (const myxmlpp::IllegalValueException) {
        cr_expect(1);
    }
}

Test(Attribute_getValueBool, illegal_overriden)
{
    std::string k = "key";
    std::string v = "true";
    myxmlpp::Attribute a(k, v);

    try {
        bool i = a.getValueBool("TRUE");
        cr_expect(0);
    } catch (const myxmlpp::IllegalValueException) {
        cr_expect(1);
    }
}