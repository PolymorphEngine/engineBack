/*
** EPITECH PROJECT, 2020
** Components.hpp
** File description:
** header for Components.c
*/


#pragma once

#include "../Core/component/base/Component.hpp"

#include "../Core/component/builtins/TransformComponent.hpp"

//  Drawables
#include "../Core/component/base/ADrawableComponent.hpp"
#include "../Core/component/builtins/drawables/SpriteRendererComponent.hpp"
#include "../Core/component/builtins/drawables/TextRendererComponent.hpp"

//  Colliders
#include "../Core/component/base/ACollider2d.hpp"
#include "../Core/component/builtins/colliders/ColliderCircle2d.hpp"
#include "../Core/component/builtins/colliders/ColliderRect2d.hpp"
