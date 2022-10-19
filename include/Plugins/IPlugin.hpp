#include <iostream>
#include <memory>
#include <vector>


#pragma once
#include "myxmlpp.hpp"
#include "Utilities/safe_ptr.hpp"

namespace Polymorph
{
    class IComponentInitializer;
    class Entity;
    using GameObject = safe_ptr<Entity>;

    class Scene;
    class Engine;
    
    namespace Config
    {
        class XmlComponent;
        class XmlEntity;
        using XmlNode = myxmlpp::Node;
    }
    
    class IPlugin 
    {
        public:
            
            virtual std::string getPackageName() = 0;
    
            virtual std::shared_ptr<IComponentInitializer> createComponent(std::string &type,
            Config::XmlComponent &data, GameObject entity) = 0;
            
            virtual bool isEnabled() = 0;

            virtual bool hasComponent(std::string &type) = 0;
            
            virtual bool hasPrefab(const std::string &id) = 0;

            virtual std::shared_ptr<Config::XmlEntity> &getPrefabConf(const std::string &id) = 0;
    
            virtual std::vector<Config::XmlComponent> &getComponentTemplates() = 0;
    
            virtual void preUpdateInternalSystems(std::shared_ptr<Scene> &scene) = 0;
            
            virtual void updateInternalSystems(std::shared_ptr<Scene> &scene) = 0;
            
            virtual void postUpdateInternalSystems(std::shared_ptr<Scene> &scene) = 0;
            
            virtual void startScripts(std::shared_ptr<Scene> &scene) = 0;
            
            virtual void endScripts(std::shared_ptr<Scene> &scene) = 0;

    };

}


/*

Whats builtin ?:
    - Parsing (Polymorph::Config)
    - E.C.S (Entity, Component, Scene)


Type of data to have in a Plugin:
    - Prefabs
    - Initializers
    - Components
    - Components Templates
    - Factory
    - Modules (classes serializable)
    - Some default assets (Textures/ Fonts / ...)
    - Some internal plugin updates


Polymorph Plugins (which are namespaced, ex: Polymorph_Raylib-Core):
    
     
    - raylib-core <- render-core
    - raylib-render
    - raylib-advanced-render
    - raylib-gui
    - raylib-physics
    - raylib-audio
    - raylib-input

    - render-core <- Polymorph::WindowModule, IWindowModule
    - render-2D
    - render-3D
    - physics-2D : deps [raylib-physics, render-2D]
    - physics-3D : deps [raylib-physics, render-3D]
    - shader : deps [raylib-advanced-render, render-2D, render-3D]
    - light : deps [raylib-advanced-render, render2D, render-3D]
    - particles : deps [raylib-advanced-render, render-3D, render-2D]
    - gui : deps [raylib-gui, render-2D, render-3D]
    - audio : [raylib-audio]
    - input : [raylib-input]
    
    
    - splash-screen
    - ltunl 
    - event


*/