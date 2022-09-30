/*
** EPITECH PROJECT, 2020
** IBoxModule
** File description:
** header for IBoxModule.cpp
*/

#pragma once

namespace Polymorph
{
    class ISphereModule;
    class IBoxModule;
    class ITextureModule;

	class IBoxModule
	{
		public:
			virtual ~IBoxModule() = default;

			virtual void setSize(float x, float y, float z) = 0;
			virtual void setOrigin(float x, float y, float z) = 0;

            virtual float getXSize() = 0;
            virtual float getYSize() = 0;
            virtual float getZSize() = 0;

            virtual float getXOrigin() = 0;
            virtual float getYOrigin() = 0;
            virtual float getZOrigin() = 0;

            virtual void setTexture(ITextureModule &texture) = 0;

            virtual bool collideWithBox(const IBoxModule &box) const = 0;
			virtual bool collideWithSphere(const ISphereModule &sphere) const = 0;
			virtual void draw() = 0;
			virtual void drawWires() = 0;
	};



}