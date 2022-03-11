/*
** EPITECH PROJECT, 2020
** XmlEntity.hpp.h
** File description:
** header for XmlEntity.c
*/

#ifndef ENGINE_XMLENTITY_HPP
#define ENGINE_XMLENTITY_HPP

#include <memory>
#include "XmlComponent.hpp"

namespace Polymorph
{
    class Engine;
    class Entity;
    namespace Config
    {

        class XmlEntity
        {
            public:
                XmlEntity(std::shared_ptr<XmlNode> &node, std::shared_ptr<Engine> &engine);
                std::string &getName() const;
                bool isActive() const;
                std::string &getId() const;
                [[nodiscard]] std::vector<std::string> getTags() const;
                std::string getLayer() const;
                std::shared_ptr<Entity> makeInstance();

            private:
                std::vector<std::shared_ptr<XmlComponent>> _components;
                std::vector<std::shared_ptr<XmlEntity>> _children;
                std::shared_ptr<Engine> _engine;
                std::shared_ptr<XmlNode> _node;
        };
    }

}


#endif //ENGINE_XMLENTITY_HPP
