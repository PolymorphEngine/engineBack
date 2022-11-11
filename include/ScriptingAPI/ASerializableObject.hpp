/*
** EPITECH PROJECT, 2020
** ISerializableObject.hpp
** File description:
** header for ISerializableObject.c
*/

#ifndef ENGINE_ASERIALIZABLEOBJECT_HPP
#define ENGINE_ASERIALIZABLEOBJECT_HPP

#include <string>
#include <utility>

namespace polymorph::engine
{
    class ASerializableObject
    {
        public:
            explicit ASerializableObject(std::string type) : _type(std::move(type)) {} ;
            virtual ~ASerializableObject() = default;
            
            [[nodiscard]] virtual std::string getType() const {return _type;};
            
        private:
            std::string _type;
    };
}

#endif //ENGINE_ASERIALIZABLEOBJECT_HPP
