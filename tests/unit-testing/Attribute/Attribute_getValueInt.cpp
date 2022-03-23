/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <criterion/criterion.h>
#include "Attribute.hpp"
#include "IllegalValueException.hpp"

Test(Attribute_getValueInt, positive)
{
    std::string k = "key";
    std::string v = "1";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueInt() == 1;

    cr_expect(res);
}

Test(Attribute_getValueInt, negative)
{
    std::string k = "key";
    std::string v = "-1";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueInt() == -1;

    cr_expect(res);
}

Test(Attribute_getValueInt, zero)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueInt() == 0;

    cr_expect(res);
}

Test(Attribute_getValueInt, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);
    
    try {
        int i = a.getValueInt();
        cr_expect(0);
    } catch (const myxmlpp::IllegalValueException) {
        cr_expect(1);
    }
}