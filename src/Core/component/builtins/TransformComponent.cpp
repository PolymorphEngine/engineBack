/*
** EPITECH PROJECT, 2020
** Transfoem.cpp.c
** File description:
** Transfoem.cpp.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>

namespace Polymorph
{

    Transform TransformComponent::parent() {
        return _parent;
    }

    void TransformComponent::setParent(Transform parent_ref)
    {
        if (!!this->_parent && this->_parent->gameObject->getId() != parent_ref->gameObject->getId())
            this->_parent->removeChild(transform);
        this->_parent = parent_ref;
        setLastSibling();
    }

    Transform TransformComponent::removeChild(Transform child)
    {
        int pos = 0;

        for (auto &tchild: *this)
        {
            if (tchild->gameObject->getId() == child->gameObject->getId())
            {
                erase(pos);
                child->_parent.reset();
                //TODO: reset in scene
                return (tchild);
            }
            ++pos;
        }
        return Transform(nullptr);
    }

    void TransformComponent::setSiblingIndex(int index)
    {

        if (!_parent)
            return;
        if (index < 0)
            index = 0;
        if (index >= _parent->_children.size() && index != 0)
            index = _parent->_children.size() - 1;

        //TODO: Set index in scene !!!

        _parent->removeChild(transform);
        _parent->_children.insert(_parent->_children.begin() + index, transform);
    }

    void TransformComponent::setLastSibling()
    {
        if (!_parent)
            //TODO : Log "Tried to set sibling index on an object which hasn't a parent"
            return;
        setSiblingIndex((int) _parent->_children.size() - 1);
    }

    void TransformComponent::setFirstSibling()
    {
        setSiblingIndex(0);
    }

    TransformComponent::TransformComponent(GameObject gameObject)
            : Component("Transform", gameObject)
    {

    }

    void TransformComponent::start()
    {
    }

    void TransformComponent::update()
    {

    }

    std::size_t TransformComponent::nbChildren()
    {
        return _children.size();
    }

    bool TransformComponent::noChild()
    {
        return _children.empty();
    }

    const Vector3 &TransformComponent::getPosition() const
    {
        return _position;
    }

    void TransformComponent::setPosition(const Vector3 &position)
    {
        Vector3 diff = position - _position;

        _position = position;
        _moveChildren(diff);
    }

/*
    const Vector2 &TransformComponent::getRotation() const
    {
        return _rotation;
    }

    void TransformComponent::setRotation(const Vector2 &rotation)
    {
        _rotation = rotation;
    }

    const Vector3 &TransformComponent::getScale() const
    {
        return _scale;
    }

    void TransformComponent::setScale(const Vector3 &scale) {
        _scale = scale;
    }
*/

    void TransformComponent::setPositionX(const float posX)
    {
        Vector3 diff = {_position.x - posX, 0, 0};

        this->_position.x = posX;
        _moveChildren(diff);
    }

    void TransformComponent::setPositionY(const float posY)
    {
        Vector3 diff = { 0, _position.y - posY, 0};

        this->_position.y = posY;
        _moveChildren(diff);
    }

    void TransformComponent::setPositionZ(const float posZ)
    {
        Vector3 diff = { 0, 0, _position.z - posZ };

        this->_position.z = posZ;
        _moveChildren(diff);
    }
/*
    void TransformComponent::setRotationX(float rotationX)
    {
        this->_rotation.x = rotationX;
    }

    //Todo: center
    void TransformComponent::setRotationY(float rotationY)
    {
        this->_rotation.y = rotationY;
    }

    //Todo: center
    void TransformComponent::setScaleX(float scaleX)
    {
        Vector3 diff = { _scale.x - scaleX, 0, 0};

        this->_scale.x = scaleX;
        _scaleChildren(diff);
    }

    void TransformComponent::setScaleY(float scaleY)
    {
        Vector3 diff = { 0, _scale.y - scaleY, 0};

        this->_scale.y = scaleY;
        _scaleChildren(diff);
    }

    void TransformComponent::setScaleZ(float scaleZ)
    {
        Vector3 diff = { 0, 0, _scale.z - scaleZ};

        this->_scale.z = scaleZ;
        _scaleChildren(diff);
    }
*/
    void TransformComponent::move(const Vector3 &delta)
    {
        _position += delta;
        _moveChildren(delta);
    }

    void TransformComponent::_moveChildren(const Vector3 &delta)
    {
        for (auto &c : _children) {
            c->move(delta);
        }
    }

    /*Todo: later
    void TransformComponent::_rotateChildren(const Vector2 &delta)
    {

    }

    void TransformComponent::_scaleChildren(const Vector3 &delta)
    {
    }
     */

}
