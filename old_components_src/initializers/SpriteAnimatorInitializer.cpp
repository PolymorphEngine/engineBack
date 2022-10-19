/*
** EPITECH PROJECT, 2020
** TextRendererInitializer.cpp
** File description:
** TextRendererInitializer.cpp
*/

#include "Polymorph/Factory.hpp"
#include "Polymorph/Config.hpp"
#include "ComponentsFactory/initializers/SpriteAnimatorInitializer.hpp"
#include "Core/component/builtins/animation/SpriteAnimatorScript.hpp"

namespace Polymorph
{
    SpriteAnimatorInitializer::SpriteAnimatorInitializer(
            Config::XmlComponent &data, GameObject entity)
            : AComponentInitializer("SpriteAnimator", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void SpriteAnimatorInitializer::build()
    {
        data.setProperty("currentAnimation", component->currentAnimation);
        data.setProperty("animations", component->animations);
    }

    // Called after all components/scripts have been built
    void SpriteAnimatorInitializer::reference()
    {
        data.setProperty("targetGraphics", component->targetGraphics);
    }
}