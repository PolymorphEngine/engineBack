/*
** EPITECH PROJECT, 2020
** TextureModule.hpp
** File description:
** header for TextureModule.c
*/


#pragma once

#include <myxmlpp.hpp>
#include <memory>
#include "Polymorph/Types.hpp"
#include "isModules/interfaces/ITextureModule.hpp"
#include "isModules/interfaces/IImageModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{
	class TextureModule
	{
		friend class GraphicalAPI;

	////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

		public:
			explicit TextureModule(const std::string &path);
			explicit TextureModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager);

			~TextureModule() = default;


	//////////////////////--------------------------/////////////////////////



	///////////////////////////// PROPERTIES ////////////////////////////////
		public:
            Vector2 scale = Vector2(1, 1);


		private:
            using TextureModuleLoader = is::ITextureModule *(*)(const std::string &filepath);
            using TextureModuleFromImageLoader = is::ITextureModule *(*)(const is::IImageModule &image);
            using ImageModuleLoader = is::IImageModule *(*)(const std::string &filepath);
            using ImageModuleFromTextureLoader = is::IImageModule *(*)(const is::ITextureModule &texture);
            static inline TextureModuleLoader _c_texture = nullptr;
            static inline TextureModuleFromImageLoader _c_texture_from_image = nullptr;
            static inline ImageModuleLoader _c_image = nullptr;
            static inline ImageModuleFromTextureLoader _c_image_from_texture = nullptr;

			std::unique_ptr<is::ITextureModule> _texture;
			std::unique_ptr<is::IImageModule> _image;
            Rect _crop;
			std::string _filepath;
			Color _color;

	//////////////////////--------------------------/////////////////////////



	/////////////////////////////// METHODS /////////////////////////////////
		public:
			void setPosition(Vector2 position);

			void setScale(Vector2 scale);

			void setCrop(Rect crop);

            Rect getCrop();
     //       Vector2 getSize();
     //       Vector2 getScale();

            is::ITextureModule &getTexture() const;

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