/*
** EPITECH PROJECT, 2020
** is_builtin.hpp
** File description:
** header for is_builtin.c
*/

#pragma once

#include <type_traits>

template<typename T, bool>
struct is_builtin_impl : std::false_type {};

template<typename T>
struct is_builtin_impl<T, true> : std::is_trivially_copyable<T> {};