/*
** EPITECH PROJECT, 2022
** InputFieldInitializer.cpp
** File description:
** Initializer for the component InputField
*/

#include "Polymorph/Factory.hpp"
#include "Polymorph/Core.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"

namespace Polymorph
{
    InputFieldInitializer::InputFieldInitializer(Config::XmlComponent &data,
                                                   GameObject entity)
            : AComponentInitializer("InputField", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void InputFieldInitializer::build()
    {
        data.setProperty("Type", component->Type);
    }

    // Called after all components/scripts have been built
    void InputFieldInitializer::reference()
    {
        data.setProperty("PlaceHolder", component->PlaceHolder);
			data.setProperty("Target", component->Target);
			data.setProperty("OnSubmit", component->OnSubmit);
			data.setProperty("OnValueChanged", component->OnValueChanged);
			data.setProperty("OnExitFocus", component->OnExitFocus);
    }
}