#include <string>

namespace arcade
{
    class ITextModule
    {
        public:
            virtual ~ITextModule() = default;

            // USED ONLY IN WRAPPER
            // MUST : return the text object to draw
            virtual void *getText() = 0;

            // MUST: set the text value
            virtual void setText(std::string text) = 0;

            // MUST: Set the text position;
            virtual void setPosition(float x, float y) = 0;

            // MUST: move the text
            virtual void move(float x, float y) = 0;

            // ALL FILE TYPES MUST BE AT THE PATH SPECIFIED
            // MUST: loads and set a text font
            //ex SFML:
            // assetPath = ./Assets/Pacman/enemy/font
            // real path = ./Assets/Pacman/enmey/font.ttf
            virtual void setFont(std::string font) = 0;

            // MUST: Set the text color
            virtual void
            setColor(unsigned char r, unsigned char g, unsigned char b) = 0;

            // MUST: Set the text size
            virtual void setSize(int size) = 0;
    };
}