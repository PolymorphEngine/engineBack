/*
** EPITECH PROJECT, 2022
** Uuid.cpp
** File description:
** Uuid.cpp
*/


#include "uuid.hpp"

std::string Polymorph::uuid::uuid() {
    std::stringstream ss;
    ss << std::hex;
    for (int i = 0; i < 10; i++)
        ss << dis(gen);
    return ss.str();
}