/*
** EPITECH PROJECT, 2020
** BoxModule.hpp
** File description:
** header for BoxModule.c
*/


#pragma once


#include "Node.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IModelModule.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IBoxModule.hpp"

namespace Polymorph
{
    class SphereModule;

    class MeshModule;

    class TextureModule;

    class BoxModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit BoxModule(std::shared_ptr<myxmlpp::Node> &data,
                               Config::XmlComponent &manager);

            explicit BoxModule(const MeshModule &meshModule);

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            using BoxModuleLoader = Polymorph::IBoxModule *(*)(float posX,
                                                               float posY,
                                                               float posZ);
            static inline BoxModuleLoader _c_box = nullptr;
            using BoxModuleFromMeshLoader = Polymorph::IBoxModule *(*)(
                    const Polymorph::IModelModule &model);
            static inline BoxModuleFromMeshLoader _c_box_from_model = nullptr;

            std::unique_ptr<Polymorph::IBoxModule> _box;
            Vector3 _size;
            Vector3 _origin;
            std::shared_ptr<TextureModule> _texture;



//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setSize(Polymorph::Vector3 size);

            Polymorph::Vector3 getSize() const;

            Polymorph::IBoxModule &getBox() const;

            void setOrigin(Polymorph::Vector3 origin);

            bool collideWithBox(const Polymorph::BoxModule &box) const;

            bool collideWithSphere(const SphereModule &sphere) const;

            void setTexture(const std::shared_ptr<TextureModule> &texture);

            std::shared_ptr<TextureModule> getTexture() const;

            void draw();

            void drawWires();


        private:
            void _loadModule();


//////////////////////--------------------------/////////////////////////

    };

}