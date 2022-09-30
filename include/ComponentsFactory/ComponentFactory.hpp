/*
** EPITECH PROJECT, 2020
** ComponentFactory.hpp.h
** File description:
** header for ComponentFactory.c
*/

// @TEMPLATE:
//                  {"*", [](Config::XmlComponent &data, Entity &entity) -> Initializer{ return Initializer(new *Initializer(data, entity));}},

#ifndef ENGINE_COMPONENTFACTORY_HPP
#define ENGINE_COMPONENTFACTORY_HPP

#include <iostream>
#include <map>

#include <functional>
#include <vector>
#include <memory>

// @COMPONENTS: (add components include here)
#include "ComponentsFactory/initializers/TransformInitializer.hpp"
#include "ComponentsFactory/initializers/MeshAnimatorInitializer.hpp"
#include "ComponentsFactory/initializers/SpriteRendererInitializer.hpp"
#include "ComponentsFactory/initializers/TextRendererInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderCircle2dInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderRect2dInitializer.hpp"
#include "ComponentsFactory/initializers/SoundPlayerInitializer.hpp"
#include "ComponentsFactory/initializers/MusicPlayerInitializer.hpp"
#include "ComponentsFactory/initializers/CameraInitializer.hpp"
#include "ComponentsFactory/initializers/MeshRendererInitializer.hpp"
#include "ComponentsFactory/initializers/BoxColliderInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderMesh3dInitializer.hpp"
#include "ComponentsFactory/initializers/SphereRendererInitializer.hpp"
#include "ComponentsFactory/initializers/ColliderSphere3dInitializer.hpp"
#include "ComponentsFactory/initializers/BoxRendererInitializer.hpp"
#include "ComponentsFactory/initializers/CanvasInitializer.hpp"
#include "ComponentsFactory/initializers/ButtonInitializer.hpp"
#include "ComponentsFactory/initializers/HorizontalGroupLayoutInitializer.hpp"
#include "ComponentsFactory/initializers/InputFieldInitializer.hpp"
#include "ComponentsFactory/initializers/VerticalGroupLayoutInitializer.hpp"
#include "ComponentsFactory/initializers/MonoMeshAnimatorInitializer.hpp"
#include "ComponentsFactory/initializers/SpriteAnimatorInitializer.hpp"


namespace Polymorph
{
    class IComponentInitializer;

    class ComponentFactory
    {
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;
///////////////////////////////// Constructors /////////////////////////////////

        public:
            static Initializer
            create(std::string &type, Config::XmlComponent &data,
                   GameObject entity);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////

        private:
            static const inline std::map<std::string,
                    std::function<Initializer(Config::XmlComponent &data,
                                              GameObject entity)>>
                    _buildables =
                    {
                            // @INITIALIZERS: (add Component Initializers here)
                            // @TRANSFORM:
                            {
                                    {"Button", [](Config::XmlComponent &data,
                                                  GameObject entity) -> Initializer { return Initializer(
                                            new ButtonInitializer(data,
                                                                  entity));
                                    }},
                                    {"HorizontalGroupLayout",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new HorizontalGroupLayoutInitializer(
                                                     data, entity));
                                     }},
                                    {"InputField",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new InputFieldInitializer(data,
                                                                       entity));
                                     }},
                                    {"VerticalGroupLayout",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new VerticalGroupLayoutInitializer(
                                                     data, entity));
                                     }},
                                    {"Transform", [](Config::XmlComponent &data,
                                                     GameObject entity) -> Initializer { return Initializer(
                                            new TransformInitializer(data,
                                                                     entity));
                                    }},
                                    {"ColliderCircle2d",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new ColliderCircle2dInitializer(
                                                     data, entity));
                                     }},
                                    {"ColliderRect2d",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new ColliderRect2dInitializer(data,
                                                                           entity));
                                     }},
                                    {"SpriteRenderer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new SpriteRendererInitializer(data,
                                                                           entity));
                                     }},
                                    {"TextRenderer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new TextRendererInitializer(data,
                                                                         entity));
                                     }},
                                    {"SoundPlayer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new SoundPlayerInitializer(data,
                                                                        entity));
                                     }},
                                    {"MusicPlayer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new MusicPlayerInitializer(data,
                                                                        entity));
                                     }},
                                    {"MeshRenderer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new MeshRendererInitializer(data,
                                                                         entity));
                                     }},
                                    {"Camera", [](Config::XmlComponent &data,
                                                  GameObject entity) -> Initializer { return Initializer(
                                            new CameraInitializer(data,
                                                                  entity));
                                    }},
                                    {"BoxCollider",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new BoxColliderInitializer(data,
                                                                        entity));
                                     }},
                                    {"ColliderMesh3d",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new ColliderMesh3dInitializer(data,
                                                                           entity));
                                     }},
                                    {"ColliderSphere3d",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new ColliderSphere3dInitializer(
                                                     data, entity));
                                     }},
                                    {"SphereRenderer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new SphereRendererInitializer(data,
                                                                           entity));
                                     }},
                                    {"Canvas", [](Config::XmlComponent &data,
                                                  GameObject entity) -> Initializer { return Initializer(
                                            new CanvasInitializer(data,
                                                                  entity));
                                    }},
                                    {"BoxRenderer",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new BoxRendererInitializer(data,
                                                                        entity));
                                     }},
                                    {"MeshAnimator",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new MeshAnimatorInitializer(data,
                                                                         entity));
                                     }},
                                    {"MonoMeshAnimator",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new MonoMeshAnimatorInitializer(
                                                     data, entity));
                                     }},
                                    {"SpriteAnimator",
                                     [](Config::XmlComponent &data,
                                        GameObject entity) -> Initializer { return Initializer(
                                             new SpriteAnimatorInitializer(data,
                                                                           entity));
                                     }},
                            },
                    };
///////////////////////////--------------------------///////////////////////////

    };
}

#endif //ENGINE_COMPONENTFACTORY_HPP
