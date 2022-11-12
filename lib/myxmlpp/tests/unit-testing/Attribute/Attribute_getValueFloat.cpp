/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <criterion/criterion.h>
#include "Attribute.hpp"
#include "IllegalValueException.hpp"

Test(Attribute_getValueFloat, positive)
{
    std::string k = "key";
    std::string v = "1.5";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueFloat() == 1.5;

    cr_expect(res);
}

Test(Attribute_getValueFloat, negative)
{
    std::string k = "key";
    std::string v = "-1.5";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueFloat() == -1.5;

    cr_expect(res);
}

Test(Attribute_getValueFloat, zero)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValueFloat() == 0;

    cr_expect(res);
}

Test(Attribute_getValueFloat, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);

    try {
        (void)a.getValueFloat();
        cr_expect(0);
    } catch (const myxmlpp::IllegalValueException) {
        cr_expect(1);
    }
}