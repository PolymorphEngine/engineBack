/*
** EPITECH PROJECT, 2020
** CameraInitalizer.cpp
** File description:
** CameraInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

CameraInitializer::CameraInitializer(Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("Camera", data, entity)
{

}

void CameraInitializer::build()
{
    data.setProperty("camera", component->camera);
    data.setProperty("TargetType", component->TargetType);
    data.setProperty("PointTarget", component->PointTarget);
}

void CameraInitializer::reference()
{
    data.setProperty("ObjectTarget", component->ObjectTarget);
}
