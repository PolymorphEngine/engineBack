/*
** EPITECH PROJECT, 2020
** TextureModule.hpp
** File description:
** header for TextureModule.c
*/


#pragma once

#include <myxmlpp/myxmlpp.hpp>
#include <memory>
#include "Polymorph/Types.hpp"
#include "GraphicalAPI/GraphicalInterfaces/ITextureModule.hpp"
#include "Config/XmlComponent.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IImageModule.hpp"

namespace Polymorph
{
    class TextureModule
    {
            friend class GraphicalAPI;

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit TextureModule(const std::string &path);

            explicit TextureModule(std::shared_ptr<myxmlpp::Node> &data,
                                   Config::XmlComponent &manager);

            ~TextureModule() = default;


            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Vector2 scale = Vector2(1, 1);


        private:
            using TextureModuleLoader = Polymorph::ITextureModule *(*)(
            const std::string &filepath);
            using TextureModuleFromImageLoader = Polymorph::ITextureModule *(*)(
            const Polymorph::IImageModule &image);
            using ImageModuleLoader = Polymorph::IImageModule *(*)(
            const std::string &filepath);
            using ImageModuleFromTextureLoader = Polymorph::IImageModule *(*)(
            const Polymorph::ITextureModule &texture);
            static inline TextureModuleLoader _c_texture = nullptr;
            static inline TextureModuleFromImageLoader _c_texture_from_image = nullptr;
            static inline ImageModuleLoader _c_image = nullptr;
            static inline ImageModuleFromTextureLoader _c_image_from_texture = nullptr;

            std::unique_ptr<Polymorph::ITextureModule> _texture;
            std::unique_ptr<Polymorph::IImageModule> _image;
            Rect _crop;
            std::string _filepath;
            Color _color;

            const std::string fallBackTexture = "missing.png";

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void setPosition(Vector2 position);

            void setScale(Vector2 scale);

            void setCrop(Rect crop);

            Rect getCrop();

            float getTextureWidth();

            float getTextureHeight();

            Polymorph::ITextureModule &getTexture() const;

            void draw();

            Color getColor() const;

            void setColor(Color color);

        private:
            void _flipTextureToImage();

            void _flipImageToTexture();

            void _loadModules();

            //////////////////////--------------------------/////////////////////////

    };
}