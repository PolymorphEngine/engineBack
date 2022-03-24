/*
** EPITECH PROJECT, 2020
** CollectorPtr.hpp.h
** File description:
** header for CollectorPtr.c
*/

#ifndef ENGINE_SAFE_PTR_HPP
#define ENGINE_SAFE_PTR_HPP

#include <memory>

namespace Polymorph
{
    template <typename T>
    class safe_ptr : public std::weak_ptr<T>
    {
        public:
            safe_ptr() : std::weak_ptr<T>(){};
            explicit safe_ptr(std::shared_ptr<T> d) : std::weak_ptr<T>(d){};

            safe_ptr<T> &operator=(std::shared_ptr<T> &t)
            {
                this->_M_assign(t);
                return *this;
            }

            std::shared_ptr<T> operator*()
            {
                return this->lock();
            }

            T *operator->()
            {
                if (this->expired() || this->lock() == nullptr)
                    throw std::runtime_error("Object reference not set to an instance");
                return this->lock().get();
            }


            bool operator!()
            {
                return this->expired() || this->lock() == nullptr;
            }

    };
}

#endif //ENGINE_SAFE_PTR_HPP