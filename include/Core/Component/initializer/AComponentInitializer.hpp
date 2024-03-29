/*
** EPITECH PROJECT, 2020
** IComponentInitializer.hpp.h
** File description:
** header for IComponentInitializer.c
*/

#ifndef ENGINE_ACOMPONENTINITIALIZER_HPP
#define ENGINE_ACOMPONENTINITIALIZER_HPP

#include <iostream>
#include <memory>
#include "IComponentInitializer.hpp"
#include <polymorph/Config.hpp>

namespace polymorph::engine
{
    namespace Config
    {
        class XmlComponent;
    }
    class Entity;

    class Component;

    template<typename T>
    class AComponentInitializer : public IComponentInitializer
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            AComponentInitializer(std::string type, Config::XmlComponent &data,
                                  GameObject entity)
                    :
                    data(data), type(std::move(type)),
                    component(std::make_shared<T>(entity))
            {
                component->enabled = data.isEnabled();
            };

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        protected:
            std::shared_ptr<T> component;
            Config::XmlComponent &data;
            std::string type;


        public:
            void build() override = 0;

            void reference() override = 0;

            std::shared_ptr<Component> get() final
            {
                return std::dynamic_pointer_cast<Component>(component);
            }

            std::shared_ptr<Component> operator*() final
            {
                return get();
            }

            std::string getType() const final
            {
                return type;
            }

            void update() override
            {
                component->update();
            }

            void onAwake() override
            {
                component->onAwake();
            }

            void start() override
            {
                component->start();
            }

            bool isAwaked() const override
            {
                return component->isAwaked();
            }

            void setAsStarted() override
            {
                component->setAsStarted();
            }

            void setAsAwaked() override
            {
                component->setAsAwaked();
            }

            bool isStarted() const override
            {
                return component->isStarted();
            }

            bool isEnabled() const override
            {
                return component->enabled;
            }

///////////////////////////--------------------------///////////////////////////
    };


}
#endif //ENGINE_ACOMPONENTINITIALIZER_HPP
