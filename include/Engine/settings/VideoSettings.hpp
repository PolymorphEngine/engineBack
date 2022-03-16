/*
** EPITECH PROJECT, 2020
** VideoSettings.hpp
** File description:
** header for VideoSettings.c
*/

#ifndef ENGINE_VIDEOSETTINGS_HPP
#define ENGINE_VIDEOSETTINGS_HPP

#include "myxmlpp.hpp"
#include "Vector.hpp"

namespace Polymorph::Settings {
    using XmlNode = myxmlpp::Node;

    class VideoSettings {

///////////////////////////////// Constructors /////////////////////////////////

        public:
            VideoSettings(const std::shared_ptr<XmlNode> &node);

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties /////////////////////////////////

        private:
            bool _defaultMode = false;
            int _maxFps = 60;
            bool _fullscreen = false;
            bool _resizable = false;
            int _bitsPerPixel = 32;
            Vector2 _resolution;

            const std::shared_ptr<XmlNode> &_node;

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Methods /////////////////////////////////

        private:
            bool _initBoolVal(const std::string &attrName);

            int _initIntVal(const std::string &attrName);

            Vector2 _initResolution() const;

            static void _saveToAttribute(const std::shared_ptr<XmlNode> &node, const std::string &attrName, float value);

        public:
            bool getDefaultMode() const;

            int getMaxFps() const;

            bool getFullscreen() const;

            bool getResizable() const;

            int getBitsPerPixel() const;

            Vector2 getResolution() const;

            void setDefaultMode(bool mode);

            void setMaxFps(int fps);

            void setFullscreen(bool fullscreen);

            void setResizable(bool resizable);

            void setBitsPerPixel(int bitsPerPixel);

            void setResolution(Vector2 resolution);

///////////////////////////--------------------------///////////////////////////

    };
}


#endif //ENGINE_VIDEOSETTINGS_HPP
