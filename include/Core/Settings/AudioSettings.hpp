/*
** EPITECH PROJECT, 2020
** AudioSettings.hpp
** File description:
** header for AudioSettings.c
*/

#ifndef ENGINE_AUDIOSETTINGS_HPP
#define ENGINE_AUDIOSETTINGS_HPP

#include <myxmlpp/myxmlpp.hpp>

namespace polymorph::engine::Settings
{
    using XmlNode = myxmlpp::Node;

    class AudioSettings
    {

///////////////////////////////// Constructors /////////////////////////////////
        public:
            /**
             * Construct an AudioSettings by passing the AudioSettings XML
             * node from the configuration file
             * @param node The AudioSettings node
             */
            explicit AudioSettings(const std::shared_ptr<XmlNode> &node);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties /////////////////////////////////

        private:
            const std::shared_ptr<XmlNode> &_node;

            float _masterVolume = 0;
            float _musicVolume = 0;
            float _sfxVolume = 0;
            static inline AudioSettings *_instance = nullptr;

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Methods /////////////////////////////////

        private:
            float _getVolume(const std::string &attrName);

        public:
            /**
             * Get the master volume as a percentage
             * @return The master volume
             */
            static float getMasterVolume();

            /**
             * Get the music volume as a percentage
             * @return The music volume
             */
            static float getMusicVolume();

            /**
             * Get the sfx volume as a percentage
             * @return The sfx volume
             */
            static float getSfxVolume();

            static void setMasterVolume(float vol);

            static void setMusicVolume(float vol);

            static void setSfxVolume(float vol);

///////////////////////////--------------------------///////////////////////////

    };
}


#endif //ENGINE_AUDIOSETTINGS_HPP
