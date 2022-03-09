/*
** EPITECH PROJECT, 2020
** CollectorPtr.hpp.h
** File description:
** header for CollectorPtr.c
*/

#ifndef ENGINE_REF_PTR_HPP
#define ENGINE_REF_PTR_HPP

#include <memory>
#include <map>
#include <vector>
#include <iostream>

namespace Polymorph
{
    template <typename T>
    class ref_ptr : public std::reference_wrapper<T>
    {
        public:
            ref_ptr() : std::reference_wrapper<T>(){};
            explicit ref_ptr(T data) : std::reference_wrapper<T>(data){};

            T &operator*()
            {
                return this->get();
            }
    };
}

#endif //ENGINE_REF_PTR_HPP
