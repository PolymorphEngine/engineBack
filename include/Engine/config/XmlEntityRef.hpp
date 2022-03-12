/*
** EPITECH PROJECT, 2020
** XmlEntityRef.hpp
** File description:
** header for XmlEntityRef.c
*/

#ifndef ENGINE_XMLENTITYREF_HPP
#define ENGINE_XMLENTITYREF_HPP

#include <iostream>
#include "Entity.hpp"

namespace Polymorph
{
    class Scene;

    namespace Config
    {
        class XmlEntityRef
        {
            public:
                explicit XmlEntityRef(XmlNode &node);
                GameObject getReference();


            private:
                std::string _id;
        };
    }
}

#endif //ENGINE_XMLENTITYREF_HPP
