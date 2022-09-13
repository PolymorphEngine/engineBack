/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** header for Input.c
*/

#include <Polymorph/Debug.hpp>
#include <Polymorph/Core.hpp>
#include <Polymorph/Types.hpp>
#include "GraphicalAPI/modules/Input.hpp"


void Polymorph::Input::init()
{
    if (_initialized)
        return;
    _keyDown = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("keyDown");
    _keyUp = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("keyUp");
    _keyReleased = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("keyReleased");
    _keyPressed = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("keyPressed");
    _mouseDown = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("mouseDown");
    _mouseUp = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("mouseUp");
    _mouseReleased = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("mouseReleased");
    _mousePressed = DynamicLibLoader::loadSymbol<InputModule, GraphicalAPI>("mousePressed");
    _getKey = DynamicLibLoader::loadSymbol<InputGetterKey, GraphicalAPI>("getKey");
    _getChar = DynamicLibLoader::loadSymbol<InputGetterChar, GraphicalAPI>("getChar");
    _setExit = DynamicLibLoader::loadSymbol<InputSetterExit, GraphicalAPI>("setExit");
    _getMouseX = DynamicLibLoader::loadSymbol<InputGetMousePos, GraphicalAPI>("getMouseX");
    _getMouseY = DynamicLibLoader::loadSymbol<InputGetMousePos, GraphicalAPI>("getMouseY");
    _setMousePos = DynamicLibLoader::loadSymbol<InputSetMousePos, GraphicalAPI>("setMousePos");
    _setMouseOffset = DynamicLibLoader::loadSymbol<InputSetMousePos, GraphicalAPI>("setMouseOffset");
    _setMouseScale = DynamicLibLoader::loadSymbol<InputSetMouseScale, GraphicalAPI>("setMouseScale");
    _getMouseWheelMove = DynamicLibLoader::loadSymbol<InputGetMouseWheel, GraphicalAPI>("getMouseWheelMove");
    _showCursor = DynamicLibLoader::loadSymbol<VV_Func, GraphicalAPI>("showCursor");
    _hideCursor = DynamicLibLoader::loadSymbol<VV_Func, GraphicalAPI>("hideCursor");
    _lockCursor = DynamicLibLoader::loadSymbol<VV_Func, GraphicalAPI>("lockCursor");
    _unlockCursor = DynamicLibLoader::loadSymbol<VV_Func, GraphicalAPI>("unlockCursor");
    _isHidden = DynamicLibLoader::loadSymbol<b_Func, GraphicalAPI>("isHidden");
    _isOnScreen = DynamicLibLoader::loadSymbol<b_Func, GraphicalAPI>("isOnScreen");
    _initialized = true;
}

bool Polymorph::Input::isKeyDown(KeyCode code)
{
    return _keyDown(code);
}

bool Polymorph::Input::isKeyUp(KeyCode code)
{
    return _keyUp(code);
}

bool Polymorph::Input::isKeyReleased(KeyCode code)
{
    return _keyReleased(code);
}

bool Polymorph::Input::isKeyPressed(KeyCode code)
{
    return _keyPressed(code);
}

Polymorph::Input::KeyCode Polymorph::Input::getKeyPressed(void)
{
    return static_cast<KeyCode>(_getKey());
}

char Polymorph::Input::getCharPressed(void)
{
    return static_cast<char>(_getChar());
}

void Polymorph::Input::setExitKey(KeyCode code)
{
    _setExit(code);
}

bool Polymorph::Input::isMouseButtonPressed(MouseButton button)
{
    return _mousePressed(button);
}

bool Polymorph::Input::isMouseButtonDown(MouseButton button)
{
    return _mouseDown(button);
}

bool Polymorph::Input::isMouseButtonReleased(MouseButton button)
{
    return _mouseReleased(button);

}

bool Polymorph::Input::isMouseButtonUp(MouseButton button)
{
    return _mouseUp(button);
}

Polymorph::Vector2 Polymorph::Input::getMousePosition()
{
    return {static_cast<float>(_getMouseX()), static_cast<float>(_getMouseY())};
}

void Polymorph::Input::setMousePosition(Vector2 position)
{
    _setMousePos(static_cast<int>(position.x), static_cast<int>(position.y));
}

void Polymorph::Input::setMouseOffset(Vector2 offset)
{
    _setMouseOffset(static_cast<int>(offset.x), static_cast<int>(offset.y));
}

void Polymorph::Input::setMouseScale(Vector2 scale)
{
    _setMouseScale(scale.x, scale.y);
}

float Polymorph::Input::getMouseWheelMove(void)
{
    return _getMouseWheelMove();
}

void Polymorph::Input::showCursor(void)
{
    _showCursor();
}

void Polymorph::Input::hideCursor(void)
{
    _hideCursor();
}

void Polymorph::Input::unlockCursor(void)
{
    _unlockCursor();
}

void Polymorph::Input::lockCursor(void)
{
    _lockCursor();
}

bool Polymorph::Input::isCursorHidden(void)
{
    return _isHidden();
}

bool Polymorph::Input::isCursorOnScreen(void)
{
    return _isOnScreen();
}

std::string Polymorph::Input::keyToString(Polymorph::Input::KeyCode code)
{
    switch (code)
    {

        case NONE:
            return "";
            break;
        case APOSTROPHE:
            return "'";
        case COMMA:
            return ",";
        case MINUS:
            return "-";
        case PERIOD:
            return "Period";
        case SLASH:
            return "/";
        case ZERO:
            return "0";
        case ONE:
            return "1";
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
            break;
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case SEMICOLON:
            return ";";
        case EQUAL:
            return "=";
        case A:
            return "A";
        case B:
            return "B";
        case C:
            return "C";
        case D:
            return "D";
        case E:
            return "E";
        case F:
            return "F";
        case G:
            return "G";
        case H:
            return "H";
        case I:
            return "I";
        case J:
            return "J";
        case K:
            return "K";
        case L:
            return "L";
        case M:
            return "M";
        case N:
            return "N";
        case O:
            return "O";
        case P:
            return "P";
        case Q:
            return "Q";
        case R:
            return "R";
        case S:
            return "S";
        case T:
            return "T";
        case U:
            return "U";
        case V:
            return "V";
        case W:
            return "W";
        case X:
            return "X";
        case Y:
            return "Y";
        case Z:
            return "Z";
        case LEFT_BRACKET:
            return "{";
        case BACKSLASH:
            return "\\";
        case RIGHT_BRACKET:
            return "}";
        case GRAVE:
            return "Grave";
        case SPACE:
            return "Space";
        case ESCAPE:
            return "Esc";
        case ENTER:
            return "Enter";
        case TAB:
            return "Tab";
        case BACKSPACE:
            return "Backspace";
        case INSERT:
            return "Insert";
        case DEL:
            return "Del";
        case RIGHT:
            return "Right";
        case LEFT:
            return "Left";
        case DOWN:
            return "Down";
        case UP:
            return "Up";
        case PAGE_UP:
            return "PageUp";
        case PAGE_DOWN:
            return "PageDown";
        case HOME:
            return "Home";
        case END:
            return "End";
        case CAPS_LOCK:
            return "CapsLock";
        case SCROLL_LOCK:
            return "ScrollLock";
        case NUM_LOCK:
            return "NumLock";
        case PRINT_SCREEN:
            return "Print";
        case PAUSE:
            return "Pause";
        case F1:
            return "F1";
        case F2:
            return "F2";
        case F3:
            return "F3";
        case F4:
            return "F4";
        case F5:
            return "F5";
        case F6:
            return "F6";
        case F7:
            return "F7";
        case F8:
            return "F8";
        case F9:
            return "F9";
        case F10:
            return "F10";
        case F11:
            return "F11";
        case F12:
            return "F12";
        case LEFT_SHIFT:
            return "LeftShift";
        case LEFT_CONTROL:
            return "LeftControl";
        case LEFT_ALT:
            return "LeftAlt";
        case LEFT_SUPER:
            return "LeftSuper";
        case RIGHT_SHIFT:
            return "RightShift";
        case RIGHT_CONTROL:
            return "RightControl";
        case RIGHT_ALT:
            return "RightAlt";
        case RIGHT_SUPER:
            return "RightSuper";
        case KB_MENU:
            return "KbMenu";
        case KP_0:
            return "KP_0";
        case KP_1:
            return "KP_1";
        case KP_2:
            return "KP_2";
        case KP_3:
            return "KP_3";
        case KP_4:
            return "KP_4";
        case KP_5:
            return "KP_5";
        case KP_6:
            return "KP_6";
        case KP_7:
            return "KP_7";
        case KP_8:
            return "KP_8";
        case KP_9:
            return "KP_9";
        case KP_DECIMAL:
            return "KP_Decimal";
        case KP_DIVIDE:
            return "KP_Divide";
        case KP_MULTIPLY:
            return "KP_Multiply";
        case KP_SUBTRACT:
            return "KP_Subtract";
        case KP_ADD:
            return "KP_Add";
        case KP_ENTER:
            return "KP_Enter";
        case KP_EQUAL:
            return "KP_Equal";
        case BACK:
            return "Back";
        case VOLUME_UP:
            return "Volume_Up";
        case VOLUME_DOWN:
            return "Volume_Down";
    }
}
