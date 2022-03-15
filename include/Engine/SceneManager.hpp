/*
** EPITECH PROJECT, 2020
** SceneManager.hpp
** File description:
** header for SceneManager.c
*/

#ifndef ENGINE_SCENEMANAGER_HPP
#define ENGINE_SCENEMANAGER_HPP

#include <vector>
#include <memory>
#include "safe_ptr.hpp"

namespace Polymorph
{
    class Entity;
    class TransformComponent;
    
    using GameObject = safe_ptr<Entity>;
    using Transform = safe_ptr<TransformComponent>;
    class Vector3;
    class Engine;
    
    class Scene;
    /**
     * @class An utility class used to manipulate scenes
     * @category GameObject : static functions used to browse game objects in current scene
     * @category Scene : static functions used to manipulate different scenes
     */
    class SceneManager
    {
        public: // GameObject Section
            
            /**
             * @details Fetch all actual entities in scene
             * @returns A vector of references to the actual entities
             */
            static std::vector<GameObject> GetAll();

            /**
             * @details Finds the first occurrence of a game object in scene by name
             * @param name: The name of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject Find(std::string name);

            /**
             * @details Finds all occurrences of game objects in scene by name
             * @param name: The name of the game objects to find
             * @returns A vector of smart pointers (safe_ptr) of game objects found (empty vector if not found)
             */
            static std::vector<GameObject> FindAll(std::string name);

            /**
             * @details Finds a game object in scene by its unique id
             * @param id: The unique id of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject FindById(std::string id);
            /**
             * @details Finds the first occurrence of a game object in scene by tag
             * @param tag: The tag of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject FindByTag(std::string tag);

            /**
             * @details Finds all occurrences of game objects in scene by tag
             * @param tag: The tag which is used to filter game objects 
             * @returns A vector of smart pointers (safe_ptr) of game objects found (empty vector if not found)
             */
            static std::vector<GameObject> FindAllByTag(std::string tag);



            /**
              * @details Destroy's a game object from the scene
              * @param gameObject: The game object to destroy 
              */
            static void Destroy(GameObject gameObject);


            /**
              * @details Destroy's a game object from the scene
              * @param gameObject: The game object to destroy 
              * @param delay: The delay in seconds before destroying it
              */
            static void Destroy(GameObject gameObject, float delay);


            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @returns the instantiated game object
             */
            static GameObject Instantiate(GameObject gameObject);

            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param position: the position at which the game object is instantiated
             * @returns the instantiated game object
             */
            static GameObject Instantiate(GameObject gameObject, Vector3 position);
            
            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param parent: the parent transform on which the instantiated object will depend on
             * @returns the instantiated game object
             */
            static GameObject Instantiate(GameObject gameObject, Transform parent);
            
            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param parent: the parent transform on which the instantiated object will depend on
             * @param offset: the offset position from the parent object
             * @returns the instantiated game object
             */
            static GameObject Instantiate(GameObject gameObject, Transform parent, Vector3 offset);
            
        // End of GameObject Section
        
        
        public: // Scene Section

            /**
             * @details Loads the requested scene and replace the current scene by the
             *          newly loaded one.
             * @param name: Name of the scene to load
             */
            static void LoadScene(std::string name);


            /**
             * @details Creates an empty scene (runtime only)
             * @param name: Name of the scene to load
             */
            static void CreateScene(std::string name);


            /**
             * @details Keep a reference to the requested game object to clone it when loading
             *          a new scene
             * @useless Passing a prefab (which is always accessible in any scenes)
             * @param gameObject: The game object to keep upon loading
             */
            static void DontDestroyOnLoad(GameObject gameObject);

        //  End of Scene Section

        public: // Properties
            static inline std::shared_ptr<Scene> Current = nullptr;
            static inline std::shared_ptr<Engine> Game = nullptr;
            static inline std::vector<std::shared_ptr<Entity>> KeepOnLoad;
    };
}
#endif //ENGINE_SCENEMANAGER_HPP
