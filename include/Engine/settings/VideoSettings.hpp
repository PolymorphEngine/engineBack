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
        public:
            VideoSettings(const std::shared_ptr<XmlNode> &node);

        private:
            bool _defaultMode;
            int _maxFps;
            bool _fullscreen;
            bool _resizable;
            int _bitsPerPixel;
            Vector2 _resolution;

            static bool _initBoolVal(const std::shared_ptr<XmlNode> &node,
                              const std::string &attrName);
            static int _initIntVal(const std::shared_ptr<XmlNode> &node,
                            const std::string &attrName);
            Vector2 _initResolution(const std::shared_ptr<XmlNode> &node) const;


        public:
            bool getDefaultMode() const;

            int getMaxFps() const;

            bool getFullscreen() const;

            bool getResizable() const;

            int getBitsPerPixel() const;

            Vector2 getResolution() const;
    };
}


#endif //ENGINE_VIDEOSETTINGS_HPP
