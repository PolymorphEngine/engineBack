/*
** EPITECH PROJECT, 2022
** MonoMeshAnimator.cpp
** File description:
** MonoMeshAnimator.cpp
*/

#include "Core/Component/builtins/animation/MonoMeshAnimatorComponent.hpp"
#include "Core/Component/builtins/animation/MeshFrame.hpp"
#include "Core/Component/builtins/colliders/ColliderMesh3d.hpp"
#include <Polymorph/Components.hpp>


Polymorph::MonoMeshAnimatorComponent::MonoMeshAnimatorComponent(GameObject gameObject):
Component("MonoMeshAnimator", gameObject)
{
//    _changedAnim = false;
}

void Polymorph::MonoMeshAnimatorComponent::start()
{
    //_collider = target->gameObject->getComponent<ColliderMesh3dComponent>();
    setAnimation(currentAnimationName);
}

void Polymorph::MonoMeshAnimatorComponent::update()
{
    if (!animEnabled)
        return;
    _currentAnimation->update(target->mesh);
    /*if (_changedAnim && !!_collider)
    {
        _collider->regenBox();
        _changedAnim = false;
    }*/
}

void Polymorph::MonoMeshAnimatorComponent::addAnimCallBack(
    const Polymorph::MeshAnimation::AnimationCallBack& callback)
{
    _currentAnimation->addAnimCallBack(callback);
}



void Polymorph::MonoMeshAnimatorComponent::setAnimation(const std::string& animationName)
{
    currentAnimationName = animationName;
    auto it = std::find_if(anims.begin(), anims.end(),
        [animationName](const std::shared_ptr<MeshAnimationModule>& anim) {
            return anim->name == animationName;
        });
    if (it == anims.end()) {
        animEnabled = false;
        throw ExceptionLogger("Animation not found");
    }
    _currentAnimation = *it;
    _currentAnimation->begin();
    //_changedAnim = true;
}
