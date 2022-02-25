/*
** EPITECH PROJECT, 2020
** PolymorphXml.hpp.h
** File description:
** header for PolymorphXml.c
*/

#ifndef ENGINE_POLYMORPHXML_HPP
#define ENGINE_POLYMORPHXML_HPP

#include <any>
#include "Entity.hpp"
#include "Rect.hpp"
#include "Vector.hpp"

namespace Polymorph::Config
{
    using XmlNode = void;

    class IXmlProperty
    {
        public:
            virtual std::any get() = 0;
    };

    template <typename T>
    class XmlProperty : virtual public IXmlProperty
    {
        public:
            explicit XmlProperty(XmlNode * node);
            virtual T &getValue() = 0;
            virtual void setValue(T &) = 0;
            virtual std::any get() = 0;

        private:
            std::string name;
            std::string type;
            XmlNode *node;
    };

    template <typename T>
    class XmlPropertyList : public XmlProperty<std::vector<T>>
    {
        public:
            virtual std::vector<T> &getValue() = 0;
    };


    class XmlPropertyString : public XmlProperty<std::string>
    {
        public:
            std::string &getValue() final;
    };
}



#endif //ENGINE_POLYMORPHXML_HPP
