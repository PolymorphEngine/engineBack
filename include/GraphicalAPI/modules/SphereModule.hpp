/*
** EPITECH PROJECT, 2020
** SphereModule.hpp
** File description:
** header for SphereModule.c
*/


#pragma once

#include "myxmlpp.hpp"
#include "Polymorph/Types.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IBoxModule.hpp"
#include "GraphicalAPI/GraphicalInterfaces/ISphereModule.hpp"
#include "GraphicalAPI/modules/BoxModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{

    class SphereModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit SphereModule(std::shared_ptr<myxmlpp::Node> &data,
                                  Config::XmlComponent &manager);

            explicit SphereModule();

            ~SphereModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using SphereModuleLoader = Polymorph::ISphereModule *(*)(float x,
                                                                     float y,
                                                                     float z,
                                                                     float radius);
            static inline SphereModuleLoader _c_sphere = nullptr;

            Polymorph::Vector3 _center;
            float _radius;
            Polymorph::Color _color;
            std::unique_ptr<Polymorph::ISphereModule> _sphere;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setCenter(Polymorph::Vector3);

            void setRadius(float radius);

            void setColor(Color color);

            bool collideWithBox(const BoxModule &box) const;

            bool collideWithSphere(const Polymorph::SphereModule &sphere) const;

            Polymorph::ISphereModule &getSphere() const;

            void draw();

            Polymorph::Vector3 getCenter() const;

            float getRadius() const;

            Polymorph::Color getColor() const;


        private:
            void _loadModule();

//////////////////////--------------------------/////////////////////////

    };
}
