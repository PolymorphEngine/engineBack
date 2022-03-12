/*
** EPITECH PROJECT, 2020
** XmlComponentRef.hpp
** File description:
** header for XmlComponentRef.c
*/

#ifndef ENGINE_XMLCOMPONENTREF_HPP
#define ENGINE_XMLCOMPONENTREF_HPP

#include "XmlEntityRef.hpp"

namespace Polymorph::Config
{
    
    template<typename T>
    class XmlComponentRef : public XmlEntityRef
    {
        public:
            explicit XmlComponentRef(XmlNode &node);
            safe_ptr<T> getComponentReference();

    };
}

#endif //ENGINE_XMLCOMPONENTREF_HPP
