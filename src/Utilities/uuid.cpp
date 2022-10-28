/*
** EPITECH PROJECT, 2022
** Uuid.cpp
** File description:
** Uuid.cpp
*/


#include <polymorph/Types.hpp>

std::string polymorph::engine::uuid::uuid()
{
    std::stringstream ss;
    ss << std::hex;
    for (int i = 0; i < 10; i++)
        ss << dis(gen);
    return ss.str();
}