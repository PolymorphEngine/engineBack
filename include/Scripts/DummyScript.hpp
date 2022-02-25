/*
** EPITECH PROJECT, 2020
** DummyScript.hpp.h
** File description:
** header for DummyScript.c
*/

#ifndef ENGINE_DUMMYSCRIPT_HPP
#define ENGINE_DUMMYSCRIPT_HPP

#include "Rect.hpp"
#include "default/TransformComponent.hpp"
#include "config/XmlComponent.hpp"
#include "Component.hpp"

namespace Polymorph
{
    // @Serializable
    class SerializableProperty
    {
        public:
            SerializableProperty(Config::XmlNode *node)
            {

            };
            GameObject object;
            int rank;
    };

    class DummyScript : public Polymorph::Component
    {
        public:
            int integerProperty;
            float floatProperty;
            bool BoolProperty;
            std::string stringProperty;
            Vector2 vector2Property;
            Vector3 vector3Property;
            Rect RectProperty;
            GameObject gameObjectReferenceProperty;
            Transform componentReferenceProperty;
            SerializableProperty serializableProperty;
            std::vector<GameObject> gameObjectListReferenceProperty;

    };
}



#endif //ENGINE_DUMMYSCRIPT_HPP
