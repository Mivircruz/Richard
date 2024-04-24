#include "keyboard.h"
#include "tools/logger.h"

namespace Richard::Input {
    // Static member creation initialization
    map<int, Button> Keyboard::mKeys = {};

    /*Public methods*/

    Keyboard::Keyboard() {}

    Keyboard::~Keyboard() {}

    void Keyboard::Initialize() {
        for (int i = KEYBOARD_KEY_A; i <= mKeysAmount + 1; i++) {
            mKeys[i] = Button();
        }
    }

    void Keyboard::Shutdown() {
        mKeys.clear();
    }

    void Keyboard::Update() {
       /* const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
        for (int i = KEYBOARD_KEY_A; i <= mKeysAmount; i++) {
            mKeys.at(i).Update(keyboardState[i]);
        }*/
    }

    int Keyboard::GetKeyCurrentState(int keyName) {
        return mKeys.at(keyName).GetCurrentState();
    }

    int Keyboard::GetKeyPreviousState(int keyName) {
        return mKeys.at(keyName).GetCurrentState();
    }
}