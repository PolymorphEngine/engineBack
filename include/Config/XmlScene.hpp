/*
** EPITECH PROJECT, 2020
** XmlScene.hpp.h
** File description:
** header for XmlScene.c
*/

#ifndef ENGINE_XMLSCENE_HPP
#define ENGINE_XMLSCENE_HPP

#include <memory>
#include <vector>
#include <myxmlpp.hpp>

namespace Polymorph

{
    class Engine;
    class Entity;

    namespace Config
    {
        class XmlEntity;
        class XmlScene
        {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            public:
                XmlScene(std::shared_ptr<myxmlpp::Node> &node, Engine &_engine);
//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            private:
                std::vector<std::shared_ptr<XmlEntity>> _entities;
                Engine &_engine;
                std::shared_ptr<myxmlpp::Node> _projectNode;
                std::shared_ptr<myxmlpp::Doc> _sceneDoc;

                std::string _name;
                std::string _id;
                std::string _path;
                bool _first;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
           public:
                std::string getId();
                std::string getName();
                bool isFirst() const;
                std::vector<std::shared_ptr<Entity>> getEntities();

            private:
                void _loadEntities();
//////////////////////--------------------------/////////////////////////

        };
    }

}


#endif //ENGINE_XMLSCENE_HPP
