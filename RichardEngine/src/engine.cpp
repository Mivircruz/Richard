#include "engine.h"
#include "managers/constants.h"
#include "SDL.h"
#include <iostream>
#include <string>

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
            Tools::Logger::Error("Error running game loop");
            return;
        }

        int eventType = EVENT_DEFAULT;

        // Start game loop.
        while (!eventType) {
            eventType = window.HandleEvents();
            window.Render();
        }

        // Shutdown all the managers and quit SDL2
        Shutdown();
    }



    /*Private methods and member variables*/

    // Initialize the pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    int Engine::Initialize() {
        // Logger initialization
        Tools::Logger::Initialize();

        // SDL initialization
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            Tools::Logger::Error("Error initializing SDL2: " + string(SDL_GetError()));
            return E_INTIALIZE_SDL_FAIL;
        }
        SDL_version version;
        SDL_VERSION(&version);
        Tools::Logger::Info("SDL " + to_string(version.major) + "." + to_string(version.minor));

        // Window Initialization
        if (window.Initialize() < 0) {
            Tools::Logger::Error("Error initializing Window Manager. Shutting down engine.");
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return E_INTIALIZE_WINDOW_FAIL;
        }

        return E_INTIALIZE_OK;
    }

    void Engine::Shutdown() {
        window.Shutdown();
        Tools::Logger::Shutdown();
        SDL_Quit();
    }
}