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
            AComponentInitializer(std::string type, Config::XmlComponent &data, Entity &entity);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        protected:
            std::shared_ptr<Component> component;
            Config::XmlComponent &data;
            std::string type;


        public:
            virtual std::shared_ptr<Component> &build() = 0;

            virtual void reference() = 0;

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
#endif //ENGINE_ACOMPONENTINITIALIZER_HPP
