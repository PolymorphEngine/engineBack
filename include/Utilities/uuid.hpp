/*
** EPITECH PROJECT, 2020
** Uuid.hpp
** File description:
** header for Uuid.c
*/

#ifndef ENGINE_UUID_HPP
#define ENGINE_UUID_HPP

#include <random>
#include <sstream>

namespace Polymorph {
    namespace uuid {
        static inline std::random_device              rd;
        static inline std::mt19937                    gen(rd());
        static inline std::uniform_int_distribution<> dis(0, 15);

        std::string uuid();
    }
}


#endif //ENGINE_UUID_HPP
