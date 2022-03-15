/*
** EPITECH PROJECT, 2020
** AudioSettings.hpp
** File description:
** header for AudioSettings.c
*/

#ifndef ENGINE_AUDIOSETTINGS_HPP
#define ENGINE_AUDIOSETTINGS_HPP

#include "myxmlpp.hpp"

namespace Polymorph::Settings {
    using XmlNode = myxmlpp::Node;
    class AudioSettings {
        public:
            /**
             * Construct an AudioSettings by passing the AudioSettings XML
             * node from the configuration file
             * @param node The AudioSettings node
             */
            AudioSettings(std::shared_ptr<XmlNode> node);

        private:
            int _masterValue = 0;
            int _musicVolume = 0;
            int _sfxVolume = 0;

            int _getVolume(std::shared_ptr<XmlNode> node, const std::string &attrName);

        public:
            /**
             * Get the master volume as a percentage
             * @return The master volume
             */
            int getMasterVolume();

            /**
             * Get the music volume as a percentage
             * @return The music volume
             */
            int getMusicVolume();

            /**
             * Get the sfx volume as a percentage
             * @return The sfx volume
             */
            int getSfxVolume();
    };
}


#endif //ENGINE_AUDIOSETTINGS_HPP
