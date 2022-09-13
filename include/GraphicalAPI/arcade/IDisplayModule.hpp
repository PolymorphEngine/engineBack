#pragma once

#include <string>

namespace arcade
{
    class ISpriteModule;

    class ITextModule;

    enum KeyCode
    {
        A,              //     The A key.
        B,              //     The B key.
        C,              //     The C key.
        D,              //     The D key.
        E,              //     The E key.
        F,              //     The F key.
        G,              //     The G key.
        H,              //     The H key.
        I,              //     The I key.
        J,              //     The J key.
        K,              //     The K key.
        L,              //     The L key.
        M,              //     The M key.
        N,              //     The N key.
        O,              //     The O key.
        P,              //   The P key.
        Q,              //   The Q key.
        R,              //   The R key.
        S,              //   The S key.
        T,              //   The T key.
        U,              //   The U key.
        V,              //   The V key.
        W,              //   The W key.
        X,              //   The X key.
        Y,              //   The Y key.
        Z,              //     The Z key.
        ArrowUp,        // The Arrow Up key.
        ArrowRight,     // The Arrow Right key.
        ArrowDown,      // The Arrow Down key.
        ArrowLeft,      // The Arrow Left key.
        Enter,          // The Enter key.
        Backspace,      // The Backspace key.
        KeyCount,       //    Keep last – the total number of keyboard keys.
        MouseButton1,   //    Left Click
        MouseButton2,   //    RightClick
        MouseButton3,   //    MiddleClick

    };

    class IDisplayModule
    {
        public:
            virtual ~IDisplayModule() = default;

        public:
            // INPUTS :

            // MUST: tell if the key is pressed (if held down must only tell once)
            virtual bool isKeyPressed(KeyCode Code) = 0;

            // MUST: return the actual x position of the mouse
            virtual int getMouseXPosition() = 0;

            // MUST: return the actual y position of the mouse
            virtual int getMouseYPosition() = 0;

            // MUST : Stores inputs (must be called once per frame, ex: before any logic calls to use them of course)
            virtual void fetchInputs() = 0;
            // ex: a map of key codes that says if they are pressed or not

            /////////////////////////////////////////////////////////




        public:
            // WINDOW :

            // MUST : sets resolution (does what you want in ncurse)
            virtual void setResolution(int x, int y) = 0;

            // MUST : return the width of the window
            virtual unsigned int getWindowWidth() = 0;

            // MUST : return the height of the window
            virtual unsigned int getWindowHeight() = 0;

            // MUST : sets Fps (if possible)
            virtual void setFps(int fps) = 0;

            // MUST : sets the window title (if possible)
            virtual void setWindowTitle(std::string title) = 0;

            // MUST : sets the display in fullscreen or not (does what you want in ncurse)
            virtual void setFullScreen(bool fullScreen) = 0;

            // MUST : tell if the window / program is still running
            virtual bool isOpen() = 0;

            // MUST : tell if the display is type text or not
            virtual bool isTextMode() = 0;

            // MUST:  clears the window
            virtual void clearWindow() = 0;

            // MUST: display the content
            virtual void displayWindow() = 0;

            //MUST: close the window and set the isOpen() return to false
            virtual void closeWindow() = 0;

            /////////////////////////////////////////////////////////



        public:
            // DRAW LOGIC:

            // MUST : draw a sprite module
            virtual void draw(ISpriteModule *sprite) = 0;

            // MUST : draw a text module
            virtual void draw(ITextModule *text) = 0;

            /////////////////////////////////////////////////////////
    };
}
