/*
** EPITECH PROJECT, 2022
** MeshRenderer.cpp
** File description:
** MeshRenderer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>
#include "MeshRendererComponent.hpp"


namespace Polymorph
{

    MeshRendererComponent::MeshRendererComponent(GameObject gameObject)
            : ADrawable3dComponent("MeshRenderer", gameObject)
    {

    }

    void MeshRendererComponent::start()
    {
        mesh->setTexture(texture);
        mesh->setScale(transform->getScale());
    }

    void MeshRendererComponent::draw()
    {
        mesh->setPosition(Vector3(transform->getPosition()) + offset);
        if (transform->getRotation().x != 0) {
            mesh->setRotationAxis(Vector3(1, 0, 0));
            mesh->setRotationAngle(360 * transform->getRotation().x);
        } else if (transform->getRotation().y != 0) {
            mesh->setRotationAxis(Vector3(0, 1, 0));
            mesh->setRotationAngle(360 * transform->getRotation().y);
        } else if (transform->getRotation().z != 0) {
            mesh->setRotationAxis(Vector3(0, 0, 1));
            mesh->setRotationAngle(360 * transform->getRotation().z);
        }
        mesh->setScale(transform->getScale());
        mesh->draw();
    }

    void MeshRendererComponent::setTexture(const std::shared_ptr<TextureModule> &texture)
    {
        this->texture = texture;
        mesh->setTexture(texture);
    }

}