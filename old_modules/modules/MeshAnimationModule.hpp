/*
** EPITECH PROJECT, 2020
** MeshAnimationModule.hpp
** File description:
** header for MeshAnimationModule.c
*/


#pragma once

#include <string>
#include <memory>
#include <myxmlpp/myxmlpp.hpp>
#include "GraphicalAPI/GraphicalInterfaces/IModelAnimationModule.hpp"
#include "Config/XmlComponent.hpp"
#include "MeshModule.hpp"
#include "GraphicalAPI/GraphicalInterfaces/IModelAnimationModule.hpp"
#include "Core/Component/builtins/animation/MeshAnimation.hpp"

namespace Polymorph
{
    class MeshAnimationModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit MeshAnimationModule(std::shared_ptr<myxmlpp::Node> &data,
                                         Config::XmlComponent &manager);

            ~MeshAnimationModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::vector<float> frameTimes;
            std::string name;


        private:
            using MeshAnimationModuleLoader = Polymorph::IModelAnimationModule *(*)(
                    const std::string &filepath);
            static inline MeshAnimationModuleLoader _c_MeshAnimation = nullptr;

            std::vector<float>::iterator _currentFrameTime;
            unsigned int _currentFrameCounter;
            Timer _timer;
            std::string _filePath;
            std::unique_ptr<Polymorph::IModelAnimationModule> _meshAnimation;
            std::vector<MeshAnimation::AnimationCallBack> _callbacks;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void begin();

            void update(const std::shared_ptr<Polymorph::MeshModule> &mesh);

            void
            addAnimCallBack(const MeshAnimation::AnimationCallBack &callback);

        private:
            void _loadModule();

            void _invokeCallBacks();

//////////////////////--------------------------/////////////////////////

    };
}
