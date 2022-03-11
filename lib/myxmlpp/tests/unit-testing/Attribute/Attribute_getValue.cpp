/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <criterion/criterion.h>
#include "Attribute.hpp"

Test(Attribute_getValue, simple)
{
    std::string k = "key";
    std::string v = "value";
    myxmlpp::Attribute a(k, v);
    bool res = a.getValue() == "value";

    cr_expect(res);
}