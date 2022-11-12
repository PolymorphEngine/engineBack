/*
** EPITECH PROJECT, 2020
** MeshModule.hpp
** File description:
** header for MeshModule.c
*/


#pragma once

#include <myxmlpp/myxmlpp.hpp>
#include <memory>
#include "Polymorph/Types.hpp"
#include "Config/XmlComponent.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IModelModule.hpp"

namespace Polymorph
{
    class MeshModule
    {
            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MeshModule() = default;

            explicit MeshModule(const std::string &path);

            explicit MeshModule(std::shared_ptr<myxmlpp::Node> &data,
                                Config::XmlComponent &manager);

            ~MeshModule() = default;


            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using MeshModuleLoader = Polymorph::IModelModule *(*)(
                    const std::string &objFilepath);
            static inline MeshModuleLoader _c_model = nullptr;

            std::unique_ptr<Polymorph::IModelModule> _model;
            std::string _filepath;
            float _rotationAngle;
            Color _color;
            std::shared_ptr<TextureModule> _internalTexture;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void setPosition(Vector3 position);

            void setScale(Vector3 scale);

            void setRotationAxis(Vector3 rotationAxis);

            void setRotationAngle(float rotationAngle);

            float getRotationAngle() const;

            void setColor(Color color);

            Color getColor() const;

            void setTexture(const std::shared_ptr<TextureModule> &texture);

            void draw();

            Polymorph::IModelModule &getMesh() const;

            BoxModule getBoundingBox() const;

            bool collideWithBox(const BoxModule &box) const;

            bool collideWithSphere(const SphereModule &sphere) const;

            bool colliderWithMesh(const Polymorph::MeshModule &mesh) const;

        private:
            void _loadModule();

            //////////////////////--------------------------/////////////////////////

    };
}