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
#include "Utilities/safe_ptr.hpp"
#include "Core/scene/Scene.hpp"

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
     * @class SceneManager An utility class used to manipulate scenes
     * @category GameObject : static functions used to browse game objects in current scene
     * @category Scene : static functions used to manipulate different scenes
     */
    class SceneManager
    {

///////////////////////////// PROPERTIES ////////////////////////////////
        public: // Properties
            static inline std::shared_ptr<Scene> Current = nullptr;
            static inline Engine *Game = nullptr;
            static inline std::vector<std::shared_ptr<Entity>> KeepOnLoad;
        private:
            static inline bool _sceneLoading = false;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public: // GameObject Section

            /**
             * @details Fetch all actual entities in scene
             * @returns A vector of references to the actual entities
             */
            static std::vector<GameObject> getAll();

            /**
             * @details Finds the first occurrence of a game object in scene by name
             * @param name: The name of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject find(const std::string &name);

            /**
             * @details Finds all occurrences of game objects in scene by name
             * @param name: The name of the game objects to find
             * @returns A vector of smart pointers (safe_ptr) of game objects found (empty vector if not found)
             */
            static std::vector<GameObject> findAll(const std::string &name);

            /**
             * @details Finds a game object in scene by its unique id
             * @param id: The unique id of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject findById(const std::string &id);

            /**
             * @details Finds the first occurrence of a game object in scene by tag
             * @param tag: The tag of the game object to find
             * @returns A smart pointer (safe_ptr) of the entity found (empty safe_ptr if not found)
             */
            static GameObject findByTag(const std::string &tag);

            /**
             * @details Finds all occurrences of game objects in scene by tag
             * @param tag: The tag which is used to filter game objects
             * @returns A vector of smart pointers (safe_ptr) of game objects found (empty vector if not found)
             */
            static std::vector<GameObject> findAllByTag(const std::string &tag);

            template<class T>
            static std::vector<safe_ptr<T>> getAlComponents()
            {
                return Current->getComponentsInScene<T>();
            }

            /**
              * @details Destroy's a game object from the scene
              * @param gameObject: The game object to destroy
              */
            static void destroy(GameObject &gameObject);

            /**
              * @details Destroy's a game object from the scene
              * @param gameObject: The game object to destroy
              * @param delay: The delay in seconds before destroying it
              */
            static void destroy(GameObject gameObject, float delay);

            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @returns the instantiated game object
             */
            static GameObject
            instantiate(GameObject &gameObject, bool isParent = true);

            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param position: the position at which the game object is instantiated
             * @returns the instantiated game object
             */
            static GameObject
            instantiate(GameObject gameObject, const Vector3 &position,
                        bool isParent = true);

            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param parent: the parent transform on which the instantiated object will depend on
             * @returns the instantiated game object
             */
            static GameObject
            instantiate(GameObject gameObject, Transform parent,
                        bool isParent = true);

            /**
             * @details Instantiate a game object in scene (makes a clone of it)
             * @param gameObject: the game object to clone
             * @param parent: the parent transform on which the instantiated object will depend on
             * @param offset: the offset position from the parent object
             * @returns the instantiated game object
             */
            static GameObject
            instantiate(GameObject gameObject, Transform parent, Vector3 offset,
                        bool isParent = true);

            /**
             * @details Set the position of a parent entity at the front of the scene entities list
             * @param gameObject the game object to move at front
             */
            static void setAtFront(GameObject gameObject);

            /**
             * @details Set the position of a parent entity a the desired index in the scene entities list
             * @param gameObjectthe game object to move
             * @param idx the index to move the game object at
             */
            static void setAtIdx(GameObject gameObject, std::size_t idx);

            /**
             * @details Set the position of a parent entity at the back of the scene entities list
             * @param gameObject: the game object to move to back
             */
            static void setAtBack(GameObject gameObject);

            // End of GameObject Section


        public: // Scene Section

            /**
             * @details Loads the requested scene and replace the current scene by the
             *          newly loaded one.
             * @param name: Name of the scene to load
             */
            static void loadScene(std::string name);

            static bool isSceneUnloaded();

            static void resetLoading();

            /**
             * @details Creates an empty scene (runtime only)
             * @param name: Name of the scene to load
             */
            static void createScene(std::string name);

            /**
             * @details Keep a reference to the requested game object to clone it when loading
             *          a new scene
             * @useless Passing a prefab (which is always accessible in any scenes)
             * @param gameObject: The game object to keep upon loading
             */
            static void dontDestroyOnLoad(GameObject gameObject);

            //  End of Scene Section
//////////////////////--------------------------/////////////////////////

    };
}
#endif //ENGINE_SCENEMANAGER_HPP
