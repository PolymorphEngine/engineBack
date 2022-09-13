/*
** EPITECH PROJECT, 2020
** TextModule.hpp
** File description:
** header for TextModule.c
*/


#pragma once

#include <myxmlpp.hpp>
#include <memory>
#include "Polymorph/Types.hpp"
#include "isModules/interfaces/ITextModule.hpp"
#include "Config/XmlComponent.hpp"

namespace Polymorph
{
	class TextModule
	{

	////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

		public:
            explicit TextModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager);
            TextModule(std::string str, float size);
			~TextModule() = default;


	//////////////////////--------------------------/////////////////////////



	///////////////////////////// PROPERTIES ////////////////////////////////
		public:


		private:
            using TextModuleLoader = is::ITextModule *(*)(const std::string &text);
            using FontModuleLoader = is::IFontModule *(*)(const std::string &filepath);
            static inline TextModuleLoader _c_text = nullptr;
            static inline FontModuleLoader _c_font = nullptr;

			std::unique_ptr<is::ITextModule> _text;
			std::unique_ptr<is::IFontModule> _font;
			std::string _textString;
            std::string _fontFilepath;
			float _fontSize;
			float _lineSpacing;
			Color _color;

	//////////////////////--------------------------/////////////////////////



	/////////////////////////////// METHODS /////////////////////////////////
		public:
			void setPosition(Vector2 position);

			void setString(const std::string &content);

			std::string getString();

			void setFont(const std::string &fontPath);

			void setFontSize(float fontSize);

			float getFontSize();

			void setSpacing(float lineSpacing);

			float getSpacing();

			void setColor(Color color);

			Color getColor();

			void draw();


		private:
            void _loadModules();

	//////////////////////--------------------------/////////////////////////

	};
}
