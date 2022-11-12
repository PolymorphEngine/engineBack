/*
** EPITECH PROJECT, 2020
** XmlEntity.hpp.h
** File description:
** header for XmlEntity.c
*/

#ifndef ENGINE_XMLENTITY_HPP
#define ENGINE_XMLENTITY_HPP

#include <memory>
#include <myxmlpp.hpp>

namespace polymorph::engine
{
    class Engine;

    class Entity;
    namespace Config
    {
        class XmlComponent;

        using XmlNode = myxmlpp::Node;

        class XmlEntity
        {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            public:
                XmlEntity(std::shared_ptr<XmlNode> &node, Engine &engine,
                          std::string projectPath);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            private:
                std::vector<std::shared_ptr<XmlComponent>> _components;
                std::vector<std::shared_ptr<XmlEntity>> _children;
                std::shared_ptr<Entity> instance;
                Engine &_engine;
                std::shared_ptr<XmlNode> _node;
                std::string _path;
                std::string _fileName;
                std::shared_ptr<myxmlpp::Doc> _entity;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            public:
                std::string getName() const;

                bool isActive() const;

                bool isPrefab();

                bool wasPrefab();

                std::string getPrefabId();

                std::string getId() const;

                [[nodiscard]] std::vector<std::string> getTags() const;

                std::string getLayer() const;

                std::shared_ptr<Entity>
                makeInstance(bool wasPrefab = false, bool isPrefab = false);

            private:
                void _loadComponents(bool isPrefab);
//////////////////////--------------------------/////////////////////////

        };
    }

}


#endif //ENGINE_XMLENTITY_HPP
