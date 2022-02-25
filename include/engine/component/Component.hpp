/*
** EPITECH PROJECT, 2020
** Component.hpp.h
** File description:
** header for Component.c
*/

#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include "IComponent.hpp"
#include "Entity.hpp"
#include "safe_ptr.hpp"


namespace Polymorph
{
    // COMPONENT TYPES
    class TransformComponent;


    class Entity;
    class Component : public IComponent
    {
        public:
            explicit Component(const std::string &type, Entity &game_object)
            : _type(type), gameObject(game_object), transform(*game_object.transform), name(game_object.name)
            {};
            TransformComponent &transform;
            Entity &gameObject;
            bool enabled;

            virtual void Update();
            virtual void OnAwake();
            virtual void Start();
            bool IsAwaked() const final {return awaked;}
            bool IsStarted() const final {return started;}
            virtual std::string getType() const;

        protected:
            std::string name;
            std::string _type;
            bool awaked;
            bool started;

            //  Entity Re-define
        public:
            void setActive(bool active) override;
            virtual bool componentExist(const std::string &type) const;
            virtual bool deleteComponent(const std::string &type);
            virtual bool deleteComponent(IComponent &component);

            template <typename T>
            safe_ptr<T> GetComponent();
            template <typename T>
            safe_ptr<T> AddComponent();

        protected:
            virtual void Destroy();
            virtual void Destroy(float delayInSeconds);

    };

}


#endif //ENGINE_COMPONENT_HPP
