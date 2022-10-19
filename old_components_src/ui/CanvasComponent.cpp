/*
** EPITECH PROJECT, 2020
** CanvasScript.cpp
** File description:
** CanvasScript implementation
*/

#include "Polymorph/Core.hpp"
#include "Polymorph/Components.hpp"
#include "Core/component/builtins/ui/CanvasComponent.hpp"

namespace Polymorph
{
    CanvasComponent::CanvasComponent(GameObject gameObject)
            : Component("Canvas", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void CanvasComponent::start()
    {
        
    }

    // Called every frame by the engine
    void CanvasComponent::update()
    {

    }

}