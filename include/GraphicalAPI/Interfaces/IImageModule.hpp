/*
** EPITECH PROJECT, 2020
** IImageModule.hpp
** File description:
** header for IImageModule.hpp.cpp
*/

#pragma once

namespace Polymorph
{
	class IImageModule
	{
		public:
			virtual ~IImageModule() = default;

			virtual void setScale(float x, float y) = 0;
			virtual void crop(float x, float y, float width, float height) = 0;
            virtual float getWCrop() = 0;
            virtual float getHCrop() = 0;
	};
}

