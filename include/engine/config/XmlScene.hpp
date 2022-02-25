/*
** EPITECH PROJECT, 2020
** XmlScene.hpp.h
** File description:
** header for XmlScene.c
*/

#ifndef ENGINE_XMLSCENE_HPP
#define ENGINE_XMLSCENE_HPP

#include "XmlEntity.hpp"

namespace Polymorph::Config
{

    class XmlScene {
        public:
            std::vector<std::shared_ptr<Entity>> getEntities();
            void generate();


        private:
            static void bind_references(std::vector<std::shared_ptr<Entity>> &entities, Engine &game);
            std::vector<std::shared_ptr<XmlEntity>> _entities;
            Engine &_engine;
    };
}


#endif //ENGINE_XMLSCENE_HPP
