#include "engine.h"
#include <iostream>
#include "SDL.h"

using namespace std;

namespace Richard {
    // Public methods

    Engine* Engine::GetInstance() {
        if (!Instance) {
            Instance = new Engine();
        }

        return Instance;
    }

    // Private methods

    // Initialize pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    int Engine::Initialize() {
        int initSDLResult = SDL_Init(SDL_INIT_EVERYTHING);

        if (initSDLResult < 0) {
            cout << "Error initializing SDL2: " << SDL_GetError() << endl;
        }
        else {
            SDL_version version;
            SDL_VERSION(&version);
            cout << "SDL " << version.major << "." << version.minor << endl;
        }

        return initSDLResult;

        return 0;
    }

    void Engine::Shutdown() {
        SDL_Quit();
    }
}