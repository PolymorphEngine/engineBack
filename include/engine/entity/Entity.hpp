/*
** EPITECH PROJECT, 2020
** Entity.hpp.h
** File description:
** header for Entity.c
*/

#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP


#include <vector>
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
            Entity(const Config::XmlEntity &data, Engine &game);
            Entity(Config::XmlEntity &data, std::shared_ptr<Entity> &parent);
            Entity(Config::XmlEntity &data);
            std::shared_ptr<TransformComponent> transform;
            std::string name;
            static Entity Empty;

            void setActive(bool active);
            bool hasTag(const std::string &tag) const;
            void addTag(const std::string &tag);
            void deleteTag(const std::string &tag);


            template <typename T>
            std::shared_ptr<T> &GetComponent();

            void addComponent(std::string &component, Config::XmlComponent &config);
            template<typename T>
            std::shared_ptr<T> &AddComponent();


            [[nodiscard]] bool componentExist(const std::string &type) const;

            virtual bool deleteComponent(const std::string &type) const;

            virtual void Destroy();

            virtual std::string getName() const;
            virtual std::string getId() const;
            std::vector<std::shared_ptr<AComponentInitializer>> &getComponents();


            bool operator==(const Entity &e) const
            {
                return (e.getId() == this->getId());
            }
            bool operator!=(const Entity &e) const
            {
                return (e.getId() != this->getId());
            }

        private:
            EntityId _id;
            bool _isPrefab;
            std::string _stringId;
            std::vector<std::string> _tags;
            std::string _layer;
            Engine &_game;
            std::vector<std::shared_ptr<AComponentInitializer>> _components;


    };
    using GameObject = safe_ptr<Entity>;

    // getComponent<MyScripType>();
    // addComponent<MyScripType>();
    // deleteComponent<MyScripType>();
    // componentExist<MyScripType>();
}


#endif //ENGINE_ENTITY_HPP
