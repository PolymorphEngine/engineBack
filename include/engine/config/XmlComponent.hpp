/*
** EPITECH PROJECT, 2020
** XmlComponent.hpp.h
** File description:
** header for XmlComponent.c
*/

#ifndef ENGINE_XMLCOMPONENT_HPP
#define ENGINE_XMLCOMPONENT_HPP

#include <vector>
#include "Vector.hpp"
#include "PolymorphXml.hpp"

namespace Polymorph::Config
{
    class XmlComponent
    {
        public:
            bool isEnabled();
            std::string getType();

            Vector3 getVector3Property(std::string name);
            Vector2 getVector2Property(std::string name);
            Rect getRectProperty(std::string name);
            std::string getStringProperty(std::string name);
            int getIntProperty(std::string name);
            float getFloatProperty(std::string name);
            bool getBoolProperty(std::string name);

            template<typename T>
            T getComponentReferenceProperty(std::string name);
            template<typename T>
            T getEntityReferenceProperty(std::string name);
            template<typename T>
            T getTemplatedProperty(std::string name);
            template<typename T>
            std::vector<T> getListOfTemplatedProperty(std::string name);

            template<typename T>
            static T getComponentReferenceProperty(XmlNode *node);
            template<typename T>
            static T getEntityReferenceProperty(XmlNode *node);
            template<typename T>
            static T getTemplatedProperty(XmlNode *node);
            template<typename T>
            static std::vector<T> getListOfTemplatedProperty(XmlNode *node);

        private:
            std::string type;
            XmlNode *node;
    };
}


#endif //ENGINE_XMLCOMPONENT_HPP
