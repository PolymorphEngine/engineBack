/*
** EPITECH PROJECT, 2022
** CanvasInitializer.cpp
** File description:
** Initializer for the component Canvas
*/

#include "Polymorph/Factory.hpp"
#include "Polymorph/Core.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"

namespace Polymorph
{
    CanvasInitializer::CanvasInitializer(Config::XmlComponent &data,
                                                   GameObject entity)
            : AComponentInitializer("Canvas", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void CanvasInitializer::build()
    {
        
    }

    // Called after all components/scripts have been built
    void CanvasInitializer::reference()
    {
        data.setProperty("Target", component->Target);
    }
}