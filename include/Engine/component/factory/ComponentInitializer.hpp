/*
** EPITECH PROJECT, 2020
** IComponentInitializer.hpp.h
** File description:
** header for IComponentInitializer.c
*/

#ifndef ENGINE_COMPONENTINITIALIZER_HPP
#define ENGINE_COMPONENTINITIALIZER_HPP

#include <iostream>
#include <memory>

namespace Polymorph
{
    namespace Config {
        class XmlComponent;
    }
    class Entity;

    class Component;
    class AComponentInitializer {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            AComponentInitializer(const std::string &type, Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        protected:
            std::shared_ptr<Component> component;
            Config::XmlComponent &data;
            std::string type;
            virtual std::shared_ptr<Component> &build() = 0;
            virtual void reference() = 0;

        public:
            std::shared_ptr<Component> &get()
            {
                return component;
            }

            std::shared_ptr<Component> &operator*()
            {
                return get();
            }

            std::string getType() const
            {
                return type;
            }

        protected:
            void _init();
///////////////////////////--------------------------///////////////////////////
    };


}
#endif //ENGINE_COMPONENTINITIALIZER_HPP
