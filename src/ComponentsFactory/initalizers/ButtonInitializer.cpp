/*
** EPITECH PROJECT, 2022
** ButtonInitializer.cpp
** File description:
** Initializer for the component Button
*/

#include "Polymorph/Factory.hpp"
#include "Polymorph/Core.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"


namespace Polymorph
{
    ButtonInitializer::ButtonInitializer(Config::XmlComponent &data,
                                                   GameObject entity)
            : AComponentInitializer("Button", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void ButtonInitializer::build()
    {
        data.setProperty("HoverTexture", component->HoverTexture);
			data.setProperty("ClickTexture", component->ClickTexture);
    }

    // Called after all components/scripts have been built
    void ButtonInitializer::reference()
    {
        data.setProperty("Target", component->Target);
			data.setProperty("onClickHandler", component->onClickHandler);
			data.setProperty("onReleaseHandler", component->onReleaseHandler);
			data.setProperty("onHoldHandler", component->onHoldHandler);
    }
}