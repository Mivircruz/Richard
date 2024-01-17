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

    void Engine::Run() {
        if (Initialize() < 0) {
            cout << "Error running game loop" << endl;
            return;
        }

        int eventType = 0;

        while (!eventType) {
            eventType = window.HandleEvents();
        }

        Shutdown();
    }



    // Private methods

    // Initialize the pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    int Engine::Initialize() {
        // SDL Initialization
        int initSDLResult = SDL_Init(SDL_INIT_EVERYTHING);
        if (initSDLResult < 0) {
            cout << "Error initializing SDL2: " << SDL_GetError() << endl;
            return initSDLResult;
        }
        SDL_version version;
        SDL_VERSION(&version);
        cout << "SDL " << version.major << "." << version.minor << endl;

        // Window Initialization
        if (window.Initialize() < 0) {
            cout << "Error initializing Window. Shutting down engine..." << endl;
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return -1;
        }

        return 0;
    }

    void Engine::Shutdown() {
        window.Shutdown();
        SDL_Quit();
    }
}