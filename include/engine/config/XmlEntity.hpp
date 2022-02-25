/*
** EPITECH PROJECT, 2020
** XmlEntity.hpp.h
** File description:
** header for XmlEntity.c
*/

#ifndef ENGINE_XMLENTITY_HPP
#define ENGINE_XMLENTITY_HPP

#include "XmlComponent.hpp"

namespace Polymorph::Config
{
    class XmlEntity
    {
        public:
            XmlEntity(XmlNode *node, XmlEntity *parent, Engine &engine);
            std::string getName();
            bool isActive();
            std::vector<std::string> getTags();
            std::string getLayer();
            std::shared_ptr<Entity> makeInstance(std::shared_ptr<Entity> &parent);
            std::shared_ptr<Entity> makeInstance();

        private:
            std::vector<std::shared_ptr<XmlComponent>> _components;
            std::vector<std::shared_ptr<XmlEntity>> _children;
            Engine &_engine;
            XmlNode *node;
    };
}


#endif //ENGINE_XMLENTITY_HPP
