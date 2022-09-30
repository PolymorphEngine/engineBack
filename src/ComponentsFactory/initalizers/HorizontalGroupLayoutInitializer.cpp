/*
** EPITECH PROJECT, 2022
** HorizontalGroupLayoutInitializer.cpp
** File description:
** Initializer for the component HorizontalGroupLayout
*/

#include "Polymorph/Factory.hpp"
#include "Polymorph/Core.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"

namespace Polymorph
{
    HorizontalGroupLayoutInitializer::HorizontalGroupLayoutInitializer(Config::XmlComponent &data,
                                                   GameObject entity)
            : AComponentInitializer("HorizontalGroupLayout", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void HorizontalGroupLayoutInitializer::build()
    {
        data.setProperty("ScaleViewPortWidth", component->ScaleViewPortWidth);
			data.setProperty("Spacing", component->Spacing);
			data.setProperty("LeftPadding", component->LeftPadding);
			data.setProperty("RightPadding", component->RightPadding);
			data.setProperty("TopPadding", component->TopPadding);
			data.setProperty("DownPadding", component->DownPadding);
			data.setProperty("ControlChildWidth", component->ControlChildWidth);
			data.setProperty("ControlChildHeight", component->ControlChildHeight);
    }

    // Called after all components/scripts have been built
    void HorizontalGroupLayoutInitializer::reference()
    {
        data.setProperty("ViewPort", component->ViewPort);
    }
}