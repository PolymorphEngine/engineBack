/*
** EPITECH PROJECT, 2020
** XmlEntity.cpp.cc
** File description:
** header for XmlEntity.c
*/

#include "XmlEntity.hpp"
#include "Entity.hpp"
#include <myxmlpp.hpp>
#include "Log/Logger.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"
#include "default/TransformComponent.hpp"

namespace Polymorph
{
    std::shared_ptr<Entity> Config::XmlEntity::makeInstance()
    {
        std::shared_ptr<Entity> e(new Entity(*this, this->_engine));

        for (auto &c: _components) {
            std::string t = c->getType();
            (*e).addComponent(t, *c);
        }
        e->transform = *e->GetComponent<TransformComponent>();
        if (!e->transform) {
            Logger::Log("Entity '" + e->getName() +"' has no transform. (set default Transform)" , Logger::MINOR);
            e->transform = *(*e).AddComponent<TransformComponent>();
        }
        return e;
    }

    Config::XmlEntity::XmlEntity(std::shared_ptr<XmlNode> &node,
    Engine &engine, std::string projectPath): _engine(engine)
    {
        this->_node = node;
        _path = projectPath;

        std::string name;
        try {
            name = _node->findAttribute("name")->getValue();
            _fileName = _node->findAttribute("path")->getValue();
        } catch (myxmlpp::Exception &e) {
            if (name.empty())
                name = "Unknown";
            throw ConfigurationException("Could not find path / name to load entity '"+name+"': "+e.baseWhat(), Logger::MINOR);
        }

        try {
            _entity = std::make_shared<myxmlpp::Doc>(_path + "/" +_fileName);
            _entity->getRoot();
        } catch (myxmlpp::Exception &e) {
            throw ConfigurationException("Entity at path: '"+_path + "/" +_fileName+"': does not exist", Logger::MINOR);
        }
        _loadComponents();
    }

    std::string Config::XmlEntity::getName() const
    {
        try {
            std::string name = _entity->getRoot()->findAttribute("name")->getValue();
            return name;
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as no name", Logger::DEBUG);
            return "GameObject";
        }
    }

    bool Config::XmlEntity::isActive() const
    {
        try {
            return _entity->getRoot()->findAttribute("active")->getValueBool("True", "False");
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as no state (set to false by default)", Logger::DEBUG);
            return false;
        }
    }

    std::string Config::XmlEntity::getId() const
    {
        try {
            std::string name = _entity->getRoot()->findAttribute("id")->getValue();
            return name;
        } catch (myxmlpp::Exception &e) {
            throw ConfigurationException("Entity at path: '"+_path + "/" +_fileName+"': as no id", Logger::MAJOR);
        }
    }

    std::vector<std::string> Config::XmlEntity::getTags() const
    {
        std::shared_ptr<XmlNode> tags;
        std::vector<std::string> tags_list;

        try {
            tags = _entity->getRoot()->findChild("Tags");
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as no tags", Logger::DEBUG);
            return {};
        }

        for (auto &tag: *tags) {
            try {
                tags_list.push_back(tag->findAttribute("tag")->getValue());
            } catch (myxmlpp::Exception &e) {
                Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as corrupted tag (" + e.baseWhat()+ ")", Logger::DEBUG);
            }
        }
        return tags_list;
    }

    std::string Config::XmlEntity::getLayer() const
    {
        try {
            return _entity->getRoot()->findChild("Layer")->findAttribute("layer")->getValue();
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as corrupted layer, setting default layer", Logger::DEBUG);
            return "Default";
        }
    }

    void Config::XmlEntity::_loadComponents()
    {
        std::shared_ptr<XmlNode> components;

        try {
            components = _entity->getRoot()->findChild("Components");
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as no components", Logger::MINOR);
            return;
        }
        for (auto &c: *components)
            _components.push_back(std::make_shared<Config::XmlComponent>(c));
    }

    bool Config::XmlEntity::isPrefab()
    {
        try {
            return _entity->getRoot()->findAttribute("prefab")->getValueBool("True", "False");
        } catch (myxmlpp::Exception &e) {
            Logger::Log("Entity at path: '"+_path + "/" +_fileName+"': as corrupted prefab attribute, setting default prefab to false", Logger::DEBUG);
            return false;
        }
    }
}
