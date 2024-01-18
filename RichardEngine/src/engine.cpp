#include "engine.h"
#include "managers/constants.h"
#include "SDL.h"
#include <iostream>

using namespace std;

namespace Richard {
    /*Public methods*/

    Engine* Engine::GetInstance() {
        if (!Instance) {
            Instance = new Engine();
        }

        return Instance;
    }

    void Engine::Run() {
        // Initialize all the managers.
        if (Initialize() < 0) {
            cout << "Error running game loop" << endl;
            return;
        }

        int eventType = EVENT_DEFAULT;

        // Start game loop.
        while (!eventType) {
            eventType = window.HandleEvents();
        }

        // Shutdown all the managers and quit SDL2
        Shutdown();
    }



    /*Private methods*/

    // Initialize the pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    int Engine::Initialize() {
        // SDL Initialization
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            cout << "Error initializing SDL2: " << SDL_GetError() << endl;
            return E_INTIALIZE_SDL_FAIL;
        }
        SDL_version version;
        SDL_VERSION(&version);
        cout << "SDL " << version.major << "." << version.minor << endl;

        // Window Initialization
        if (window.Initialize() < 0) {
            cout << "Error initializing Window Manager. Shutting down engine." << endl;
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return E_INTIALIZE_WINDOW_FAIL;
        }

        return E_INTIALIZE_OK;
    }

    void Engine::Shutdown() {
        window.Shutdown();
        SDL_Quit();
    }
}