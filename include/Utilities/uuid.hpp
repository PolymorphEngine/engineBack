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

namespace Polymorph
{
    namespace uuid
    {
        static inline std::random_device rd;
        static inline std::mt19937 gen(rd());
        static inline std::uniform_int_distribution<> dis(0, 15);


        /**
         * @details Generate a random UUID
         * @returns a random UUID
         * @warning This function don't store any history of generated UUID.
                    there is a very very low chance that the same UUID will be generated twice
         */
        std::string uuid();
    }
}


#endif //ENGINE_UUID_HPP
