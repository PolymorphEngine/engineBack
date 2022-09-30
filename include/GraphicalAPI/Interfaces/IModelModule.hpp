/*
** EPITECH PROJECT, 2020
** IModelModule.hpp
** File description:
** header for IModelModule.hpp.cpp
*/

#ifndef B_YEP_400_PAR_4_1_INDIESTUDIO_ALEXANDRE_JUBLOT_IMODELMODULE_HPP
#define B_YEP_400_PAR_4_1_INDIESTUDIO_ALEXANDRE_JUBLOT_IMODELMODULE_HPP

#include "ISphereModule.hpp"
#include "IBoxModule.hpp"

namespace Polymorph
{
    class IModelModule
    {
        public:
            virtual ~IModelModule() = default;

            virtual void setPosition(float x, float y, float z) = 0;
            virtual void setScale(float x, float y, float z) = 0;
            virtual void setRotationAxis(float x, float y, float z) = 0;
            virtual void setRotationAngle(float angle) = 0;
            virtual void setColor(unsigned char r, unsigned char g,
                                  unsigned char b, unsigned char a) = 0;
            virtual bool collideWithBox(const IBoxModule &box) = 0;
            virtual bool collideWithSphere(const ISphereModule &box) = 0;
            virtual bool collideWithModel(const IModelModule &model) = 0;
            virtual void setTexture(ITextureModule &texture) = 0;
            virtual void draw() = 0;
    };
}

#endif //B_YEP_400_PAR_4_1_INDIESTUDIO_ALEXANDRE_JUBLOT_IMODELMODULE_HPP
