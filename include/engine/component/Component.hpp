/*
** EPITECH PROJECT, 2020
** Component.hpp.h
** File description:
** header for Component.c
*/

#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include "IComponent.hpp"
#include "safe_ptr.hpp"


namespace Polymorph
{
    // COMPONENT TYPES
    class TransformComponent;


    class Entity;
    class Component : public IComponent
    {
        public:
            explicit Component(Entity &game_object);
            Component(const std::string &type, Entity &game_object);

            TransformComponent &transform;
            Entity &gameObject;
            bool enabled = true;

            void Update()override;
            void OnAwake()override;
            void Start()override;
            void Draw() override;
            void SetAsStarted() final {started = true;};
            void SetAsAwaked() final {awaked = true;};
            bool IsAwaked() const final {return awaked;}
            bool IsStarted() const final {return started;}
            std::string getType() const final {return _type;}

        protected:
            std::string name;
            std::string _type;
            bool awaked = false;
            bool started = false;

            //  Entity Re-define
        public:
            void setActive(bool active) override;

            template <typename T>
            safe_ptr<T> GetComponent();
            template <typename T>
            safe_ptr<T> AddComponent();
            template <typename T>
            bool DeleteComponent();
            template <typename T>
            bool ComponentExist();
            
    };

}


#endif //ENGINE_COMPONENT_HPP
