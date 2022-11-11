/*
** EPITECH PROJECT, 2020
** FACTORY_ICLS.hpp
** File description:
** header for FACTORY_ICLS.c
*/

#ifndef ENGINE_FACTORY_ICLS_HPP
#define ENGINE_FACTORY_ICLS_HPP

#include "../Core/Component/builtins/CameraComponent.hpp"

#include "../Core/Component/builtins/ui/CanvasComponent.hpp"
#include "../Core/Component/builtins/ui/ButtonComponent.hpp"
#include "../Core/Component/builtins/ui/HorizontalGroupLayoutComponent.hpp"
#include "../Core/Component/builtins/ui/InputFieldComponent.hpp"
#include "../Core/Component/builtins/ui/VerticalGroupLayoutComponent.hpp"

//  Drawables
#include "../Core/Component/base/ADrawable2dComponent.hpp"
#include "../Core/Component/base/ADrawable3dComponent.hpp"
#include "../Core/Component/builtins/drawables/SpriteRendererComponent.hpp"
#include "../Core/Component/builtins/animation/SpriteAnimatorScript.hpp"
#include "../Core/Component/builtins/drawables/TextRendererComponent.hpp"
#include "../Core/Component/builtins/drawables/MeshRendererComponent.hpp"
#include "../Core/Component/builtins/drawables/BoxRendererComponent.hpp"
#include "../Core/Component/builtins/drawables/SphereRendererComponent.hpp"
#include "../Core/Component/builtins/animation/MeshAnimatorComponent.hpp"
#include "../Core/Component/builtins/animation/MonoMeshAnimatorComponent.hpp"

//  Colliders
#include "../Core/Component/base/ACollider2d.hpp"
#include "../Core/Component/base/ACollider3d.hpp"
#include "../Core/Component/builtins/colliders/ColliderCircle2d.hpp"
#include "../Core/Component/builtins/colliders/ColliderRect2d.hpp"
#include "../Core/Component/builtins/colliders/ColliderMesh3d.hpp"
#include "../Core/Component/builtins/colliders/ColliderSphere3d.hpp"
#include "../Core/Component/builtins/colliders/BoxCollider.hpp"

#include "Core/Component/builtins/sound/SoundPlayerComponent.hpp"
#include "Core/Component/builtins/sound/MusicPlayerComponent.hpp"


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


{"Button", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ButtonInitializer(data, entity));}},
{"HorizontalGroupLayout", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new HorizontalGroupLayoutInitializer(data, entity));}},
{"InputField", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new InputFieldInitializer(data, entity));}},
{"VerticalGroupLayout", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new VerticalGroupLayoutInitializer(data, entity));}},
{"ColliderCircle2d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderCircle2dInitializer(data, entity));}},
{"ColliderRect2d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderRect2dInitializer(data, entity));}},
{"SpriteRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new SpriteRendererInitializer(data, entity));}},
{"TextRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new TextRendererInitializer(data, entity));}},
{"SoundPlayer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new SoundPlayerInitializer(data, entity));}},
{"MusicPlayer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new MusicPlayerInitializer(data, entity));}},
{"MeshRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new MeshRendererInitializer(data, entity));}},
{"Camera", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new CameraInitializer(data, entity));}},
{"BoxCollider", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new BoxColliderInitializer(data, entity));}},
{"ColliderMesh3d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderMesh3dInitializer(data, entity));}},
{"ColliderSphere3d", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ColliderSphere3dInitializer(data, entity));}},
{"SphereRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new SphereRendererInitializer(data, entity));}},
{"Canvas", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new CanvasInitializer(data, entity));}},
{"BoxRenderer", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new BoxRendererInitializer(data, entity));}},
{"MeshAnimator", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new MeshAnimatorInitializer(data, entity));}},
{"MonoMeshAnimator", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new MonoMeshAnimatorInitializer(data, entity));}},
{"SpriteAnimator", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new SpriteAnimatorInitializer(data, entity));}},


#endif //ENGINE_FACTORY_ICLS_HPP
