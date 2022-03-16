/*
** EPITECH PROJECT, 2020
** XmlScene.cpp.cc
** File description:
** header for XmlScene.c
*/

#include "config/XmlScene.hpp"
#include "config/XmlEntity.hpp"
#include "factory/ComponentInitializer.hpp"
#include "Entity.hpp"
#include "Engine.hpp"
#include "exceptions/Exception.hpp"
#include "Log/Logger.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"

namespace Polymorph
{
    Config::XmlScene::XmlScene(std::shared_ptr<myxmlpp::Node> &node,
                               Engine &engine) : _engine(engine)
    {
        _projectNode = node;

        try {
            _name = _projectNode->findAttribute("name")->getValue();
            _id = _projectNode->findAttribute("id")->getValue();
            _path =engine.getProjectPath() + "/" + _projectNode->findAttribute("path")->getValue();
            _sceneDoc = std::make_shared<myxmlpp::Doc>(_path + "/" + _name + ".pcf.scene");
            _first = _sceneDoc->getRoot()->findAttribute("first")->getValueBool("True", "False");
        } catch (myxmlpp::Exception &e) {
            throw ConfigurationException( e.what(), Logger::MAJOR);
        }
        _loadEntities();
    }

    std::vector<std::shared_ptr<Entity>> Config::XmlScene::getEntities()
    {
        std::vector<std::shared_ptr<Entity>> entities;
        for (auto &i: _entities)
            entities.push_back(i->makeInstance());
        return entities;
    }

    std::string Config::XmlScene::getId()
    {
        return _id;
    }

    std::string Config::XmlScene::getName()
    {
        return _name;
    }

    bool Config::XmlScene::isFirst()
    {
        return _first;
    }

    void Config::XmlScene::_loadEntities()
    {

        std::shared_ptr<myxmlpp::Node> list;

        try {
            list = _sceneDoc->getRoot()->findChild("Entities");
        } catch (myxmlpp::Exception &e) {
            if (_first)
                throw ConfigurationException( "Scene named '"+ _name +"' with id '" +_id+ "' (which is first scene to load) is empty: "
                + std::string(e.what()), Logger::MAJOR);
            else {
                Logger::log("Scene named '" + _name + "' with id '" + _id +
                            "' is empty: ", Logger::MINOR);
                return;
            }
        }

        if (list->empty()) {
            Logger::log("Scene named '" + _name + "' with id '" + _id +
                        "' is empty: ", Logger::MINOR);
            return;
        }
        for (auto &e: *list)
            _entities.push_back(std::make_shared<Config::XmlEntity>(e, _engine, _path));
    }
}
