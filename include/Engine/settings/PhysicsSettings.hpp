/*
** EPITECH PROJECT, 2020
** PhysicsSettings.hpp
** File description:
** header for PhysicsSettings.c
*/

#ifndef ENGINE_PHYSICSSETTINGS_HPP
#define ENGINE_PHYSICSSETTINGS_HPP

#include "myxmlpp.hpp"
#include "Vector.hpp"

namespace Polymorph::Settings
{
    using XmlNode = myxmlpp::Node;

    class PhysicsSettings {
        enum gravityMode {TWO_D, THREE_D};

        public:
            explicit PhysicsSettings(const std::shared_ptr<XmlNode>& node);

        private:
            const std::shared_ptr<XmlNode> &_node;
            Vector2 _2DGravity = {0, -9.81};
            Vector3 _3DGravity = {0, 0, -9.81};

            void _init2DGravity();
            void _init3DGravity();
            void _createDefault2DGrav();
            void _createDefault3DGrav();
            static void _saveToAttribute(const std::shared_ptr<XmlNode> &node, const std::string &dimension, const std::string &attrName, float value);

        public:
            Vector2 getGravity2D();
            Vector3 getGravity3D();

            void setGravity2D(Vector2 newGrav);
            void setGravity2D(float newYGrav);

            void setGravity3D(Vector3 newGrav);
            void setGravity3D(float newZGrav);
    };
}


#endif //ENGINE_PHYSICSSETTINGS_HPP
