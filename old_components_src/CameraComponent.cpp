/*
** EPITECH PROJECT, 2022
** CameraComponent.cpp
** File description:
** CameraComponent.cpp
*/

#include "Polymorph/Components.hpp"
#include "CameraComponent.hpp"


namespace Polymorph
{

    CameraComponent::CameraComponent(GameObject gameObject) : Component("Camera", gameObject)
    {
        Current = this;
    }

    bool CameraComponent::isTargetingObject()
    {
        return (TargetType == Object);
    }

    GameObject CameraComponent::getTargetObject()
    {
        return ObjectTarget;
    }

    void CameraComponent::setTargetPosition(Vector3 targetPosition)
    {
        PointTarget = targetPosition;
        camera->setTarget(PointTarget);
        TargetType = CameraComponent::Point;
    }

    void CameraComponent::setUp(Vector3 up)
    {
        camera->setUp(up);
    }

    void CameraComponent::setFov(float fov)
    {
        camera->setFOV(fov);
    }

    void CameraComponent::begin3dMode()
    {
        camera->begin3DMode();
    }

    void CameraComponent::end3dMode()
    {
        camera->end3DMode();
    }

    void CameraComponent::update()
    {
        if (TargetType == CameraTargetType::Object && !!ObjectTarget)
        {
            camera->setTarget(ObjectTarget->transform->getPosition());
        }
        else if (TargetType == Point)
        {
            camera->setTarget(PointTarget);
        }
    }

    void CameraComponent::start()
    {
        if (TargetType == CameraTargetType::Object && !!ObjectTarget)
        {
            camera->setTarget(ObjectTarget->transform->getPosition());
        }
        else if (TargetType == Point)
        {
            camera->setTarget(PointTarget);
        }
    }

    void CameraComponent::setTargetObject(GameObject object)
    {
        ObjectTarget = object;
        camera->setTarget(ObjectTarget->transform->getPosition());
        TargetType = CameraComponent::Object;
    }
}