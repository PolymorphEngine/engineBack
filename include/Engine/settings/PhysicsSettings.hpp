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
            Vector2 _2DGravity;
            Vector3 _3DGravity;

            void _init2DGravity(const std::shared_ptr<XmlNode>& node);
            void _init3DGravity(const std::shared_ptr<XmlNode>& node);

        public:
            Vector2 getGravity2D();
            Vector3 getGravity3D();
    };
}


#endif //ENGINE_PHYSICSSETTINGS_HPP
