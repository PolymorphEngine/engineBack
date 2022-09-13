/*
** EPITECH PROJECT, 2020
** Components.hpp
** File description:
** header for Components.c
*/


#pragma once

#include "../Core/component/base/Component.hpp"

#include "../Core/component/builtins/TransformComponent.hpp"
#include "../Core/component/builtins/CameraComponent.hpp"

#include "../Core/component/builtins/ui/CanvasComponent.hpp"
#include "../Core/component/builtins/ui/ButtonComponent.hpp"
#include "../Core/component/builtins/ui/HorizontalGroupLayoutComponent.hpp"
#include "../Core/component/builtins/ui/InputFieldComponent.hpp"
#include "../Core/component/builtins/ui/VerticalGroupLayoutComponent.hpp"

//  Drawables
#include "../Core/component/base/ADrawable2dComponent.hpp"
#include "../Core/component/base/ADrawable3dComponent.hpp"
#include "../Core/component/builtins/drawables/SpriteRendererComponent.hpp"
#include "../Core/component/builtins/drawables/TextRendererComponent.hpp"
#include "../Core/component/builtins/drawables/MeshRendererComponent.hpp"
#include "../Core/component/builtins/drawables/BoxRendererComponent.hpp"
#include "../Core/component/builtins/drawables/SphereRendererComponent.hpp"
#include "../Core/component/builtins/animation/MeshAnimatorComponent.hpp"
#include "../Core/component/builtins/animation/MonoMeshAnimatorComponent.hpp"

//  Colliders
#include "../Core/component/base/ACollider2d.hpp"
#include "../Core/component/base/ACollider3d.hpp"
#include "../Core/component/builtins/colliders/ColliderCircle2d.hpp"
#include "../Core/component/builtins/colliders/ColliderRect2d.hpp"
#include "../Core/component/builtins/colliders/ColliderMesh3d.hpp"
#include "../Core/component/builtins/colliders/ColliderSphere3d.hpp"
#include "../Core/component/builtins/colliders/BoxCollider.hpp"

#include "Core/component/builtins/sound/SoundPlayerComponent.hpp"
#include "Core/component/builtins/sound/MusicPlayerComponent.hpp"