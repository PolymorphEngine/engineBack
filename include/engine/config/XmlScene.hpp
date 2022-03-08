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

namespace Polymorph

{
    class Engine;
    class Entity;

    namespace Config
    {
        class XmlEntity;
        class XmlScene {
            public:
                XmlScene(Engine &_engine);
                std::vector<std::shared_ptr<Entity>> getEntities();
                std::string &getId();


            private:
                static void bind_references(std::vector<std::shared_ptr<Entity>> &entities);
                std::vector<std::shared_ptr<XmlEntity>> _entities;
                Engine &_engine;

        };
    }

}


#endif //ENGINE_XMLSCENE_HPP
