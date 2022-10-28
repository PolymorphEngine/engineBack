/*
** EPITECH PROJECT, 2020
** InstanceStore.hpp
** File description:
** header for InstanceStore.c
*/


#pragma once

#include <vector>
#include "Utilities/safe_ptr.hpp"

namespace polymorph::engine
{
    template<class T>
    class InstanceStore
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            InstanceStore() = default;

            ~InstanceStore() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            std::vector<safe_ptr<T>> _instances;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void registerInstance(safe_ptr<T> instance)
            {
                _instances.push_back(instance);
            }

            void updateInstances()
            {
                auto istIt = std::find_if(_instances.begin(), _instances.end(),
                                          [](safe_ptr<T> instance) { return !instance; });
                while (istIt != _instances.end())
                {
                    _instances.erase(istIt);
                    istIt = std::find_if(_instances.begin(), _instances.end(),
                                         [](safe_ptr<T> instance) { return !instance; });
                }
            }

            const std::vector<safe_ptr<T>> &getInstances()
            {
                return _instances;
            }


        private:


//////////////////////--------------------------/////////////////////////

    };

} // polymorph
