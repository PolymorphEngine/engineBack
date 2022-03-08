/*
** EPITECH PROJECT, 2020
** Entity.hpp.h
** File description:
** header for Entity.c
*/

#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP


#include <vector>
#include <map>
#include <unordered_map>

#include "safe_ptr.hpp"

namespace Polymorph
{
    class Component;
    class AComponentInitializer;
    class Engine;
    class TransformComponent;
    namespace Config{
        class XmlEntity;
        class XmlComponent;
    }

    using EntityId = std::size_t;

    inline EntityId getEntityId()
    {
        static size_t lastId = 0;
        ++lastId;
        return lastId;
    }

    class Entity
    {
        public:
            Entity();
            Entity(const Config::XmlEntity &data, std::shared_ptr<Engine> &game);
            std::shared_ptr<TransformComponent> transform;
            std::string name;
            ~Entity();

            void setActive(bool active);
            bool hasTag(const std::string &tag) const;
            void addTag(const std::string &tag);
            void deleteTag(const std::string &tag);

            void Update();
            void Draw();
            void Awake();
            void DrawChildren(TransformComponent &trm);
            void referenceComponents();


            template <typename T>
            safe_ptr<T> GetComponent();

            void addComponent(std::string &component, Config::XmlComponent &config);
            template<typename T>
            safe_ptr<T> AddComponent();

            template <typename T>
            bool componentExist() const;

            template <typename T>
            bool DeleteComponent();
            
            std::string getName() const{return name;};
            std::string &getId() {return _stringId;};

            bool operator==(Entity &e)
            {
                return (e.getId() == this->getId());
            }
            bool operator!=(Entity &e)
            {
                return (e.getId() != this->getId());
            }
            
            bool operator==(std::string &id)
            {
                return (this->getId() == id);
            }
            
            bool operator!=(std::string &id)
            {
                return (this->getId() != id);
            }

        private:
            bool componentExist(std::string &type);
            bool _isPrefab;
            bool _active;
            std::string _stringId;
            std::vector<std::string> _tags;
            std::string _layer;
            std::shared_ptr<Engine> _game;
            std::vector<std::string> _order;
            std::unordered_map<std::string, std::vector<std::shared_ptr<AComponentInitializer>>> _components;


    };
    using GameObject = safe_ptr<Entity>;

    // getComponent<MyScripType>();
    // addComponent<MyScripType>();
    // deleteComponent<MyScripType>();
    // componentExist<MyScripType>();
}


#endif //ENGINE_ENTITY_HPP
