#include "keyboard.h"
#include "tools/logger.h"
#include "SDL_keyboard.h"

namespace Richard::Events::Periphericals {
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

    void Keyboard::Update() {
        const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
        for (int i = KEYBOARD_KEY_A; i <= mKeysAmount; i++) {
            mKeys.at(i).Update(keyboardState[i]);

            // Code added to check if the keyboard is receing the input correctly
            if (keyboardState[i]) {
                Tools::Logger::Info("Key pressed: " + to_string(i));
            }
        }
    }

    int Keyboard::GetKeyCurrentState(int keyName) {
        return mKeys.at(keyName).GetCurrentState();
    }
}