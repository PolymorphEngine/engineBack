/*
** EPITECH PROJECT, 2020
** IComponentInitalizer
** File description:
** header for IComponentInitalizer.c
*/


#pragma once

#include <iostream>
#include "Core/Component/base/IComponent.hpp"

namespace polymorph::engine
{
    class Component;

    class IComponentInitializer : public IComponent
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            virtual ~IComponentInitializer() = default;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void build() = 0;

            virtual void reference() = 0;

            std::string getType() const override = 0;

            virtual std::shared_ptr<Component> operator*() = 0;

            virtual std::shared_ptr<Component> get() = 0;

            void update() override = 0;

            void onAwake() override = 0;

            void start() override = 0;

            bool isAwaked() const override = 0;

            void setAsStarted() override = 0;

            void setAsAwaked() override = 0;

            bool isStarted() const override = 0;

            virtual bool isEnabled() const = 0;

        private:

//////////////////////--------------------------/////////////////////////

    };
}



