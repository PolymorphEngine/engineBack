/*
** EPITECH PROJECT, 2020
** TransformInitializer.hpp.h
** File description:
** header for TransformInitializer.c
*/

#ifndef ENGINE_TRANSFORMINITIALIZER_HPP
#define ENGINE_TRANSFORMINITIALIZER_HPP

#include "factory/ComponentInitializer.hpp"
#include "XmlComponent.hpp"
#include "XmlEntityRef.hpp"
#include "default/TransformComponent.hpp"

namespace Polymorph
{
    class TransformInitializer : public AComponentInitializer
    {
        public:

            TransformInitializer(Config::XmlComponent &data, Entity &entity)
            : AComponentInitializer( "Transform", data, entity){
                component = std::shared_ptr<Component>(new TransformComponent(entity));
            };

            std::shared_ptr<Component> &build() final
            {
                TransformBase &trm = dynamic_cast<TransformBase&>(*component);
                trm->position = data.getVector3Property("position");
                trm->rotation = data.getVector3Property("rotation");
                trm->scale = data.getVector3Property("scale");
                return component;
            };
            void reference() final {
                TransformBase &trm = dynamic_cast<TransformBase&>(*component);
                for (auto &ref: data.getListOfTemplatedProperty<Config::XmlEntityRef>("Children"))
                {
                    GameObject child = ref.getReference();
                    (*child)->transform->SetParent(trm);
                }
            }

    };
}

#endif //ENGINE_TRANSFORMINITIALIZER_HPP
