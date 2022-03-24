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
        Num0,           //    The 0 key.
        Num1,           //    The 1 key.
        Num2,           //    The 2 key.
        Num3,           //    The 3 key.
        Num4,           //    The 4 key.
        Num5,           //    The 5 key.
        Num6,           //    The 6 key.
        Num7,           //    The 7 key.
        Num8,           //    The 8 key.
        Num9,           //    The 9 key.
        Escape,         //      The Escape key.
        LControl,       //    The left Control key.
        LShift,         //      The left Shift key.
        LAlt,           //    The left Alt key.
        LSystem,        //   The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
        RControl,       //    The right Control key.
        RShift,         //      The right Shift key.
        RAlt,           //    The right Alt key.
        RSystem,        //   The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
        Menu,           //    The Menu key.
        LBracket,       //    The [ key.
        RBracket,       //    The ] key.
        Semicolon,      //     The ; key.
        Comma,          //     The , key.
        Period,         //  The . key.
        Quote,          //     The ' key.
        Slash,          //     The / key.
        Backslash,      //     The \ key.
        Tilde,          //     The ~ key.
        Equal,          //     The = key.
        Hyphen,         //    The - key (hyphen)
        Space,          //     The Space key.
        Enter,          //     The Enter/Return keys.
        Backspace,      //     The Backspace key.
        Tab,            //  The Tabulation key.
        PageUp,         //     The Page up key.
        PageDown,       //    The Page down key.
        End,            //  The End key.
        Home,           //   The Home key.
        Insert,         //     The Insert key.
        Delete,         //     The Delete key.
        Add,            //  The + key.
        Subtract,       //    The - key (minus, usually from numpad)
        Multiply,       //    The * key.
        Divide,         //     The / key.
        Left,           //   Left arrow.
        Right,          //    Right arrow.
        Up,             //     Up arrow.
        Down,           //   Down arrow.
        Numpad0,        //   The numpad 0 key.
        Numpad1,        //   The numpad 1 key.
        Numpad2,        //   The numpad 2 key.
        Numpad3,        //   The numpad 3 key.
        Numpad4,        //   The numpad 4 key.
        Numpad5,        //   The numpad 5 key.
        Numpad6,        //   The numpad 6 key.
        Numpad7,        //   The numpad 7 key.
        Numpad8,        //   The numpad 8 key.
        Numpad9,        //   The numpad 9 key.
        F1,             //     The F1 key.
        F2,             //     The F2 key.
        F3,             //     The F3 key.
        F4,             //     The F4 key.
        F5,             //     The F5 key.
        F6,             //     The F6 key.
        F7,             //     The F7 key.
        F8,             //     The F8 key.
        F9,             //     The F9 key.
        F10,            //    The F10 key.
        F11,            //    The F11 key.
        F12,            //    The F12 key.
        F13,            //    The F13 key.
        F14,            //  The F14 key.
        F15,            //  The F15 key.
        Pause,          //    The Pause key.
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
