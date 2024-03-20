#include "engine.h"
#include "constants.h"
#include "events/mouse.h"
#include "events/keyboard.h"
#include "renderer/mesh.h"
#include "renderer/rendermesh.h"
#include "renderer/shader.h"
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

    Subsystems::Renderer* Engine::GetRenderer() {
        return &mRenderer;
    }

    void Engine::Run(Application* app) {
        // Initialize all the managers
        if (Initialize() < 0) {
            Tools::Logger::Error("Error running game loop");
            return;
        }

        // Check application provided
        if(mApp) {
            Tools::Logger::Warning("Richard Engine already has an application defined. This one will be replaced");
        } else if(!app) {
            Tools::Logger::Error("No Application provided for the engine to run.");
            return;
        }

        // Initialize the client-defined application
        mApp = app;
        mApp->Initialize();

        // Start game loop
        int eventType = EVENT_DEFAULT;
        while (!eventType) {
            eventType = Update();
            Render();
        }
        
        // Shutdown all the managers and quit SDL2
        Shutdown();
    }



    /*Private methods and member variables*/

    // Initialize the pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    Engine::Engine() {
        mApp = nullptr;
    }

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
        if (mWindow.Initialize() < 0) {
            Tools::Logger::Error("Error initializing Window Manager. Shutting down engine.");
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return E_INTIALIZE_WINDOW_FAIL;
        }

        // Periphericals Initialization
        Events::Periphericals::Mouse::Initialize();
        Events::Periphericals::Keyboard::Initialize();

        // Renderer initialization
        mRenderer.Initialize();

        return E_INTIALIZE_OK;
    }

    int Engine::Update() {
        int eventType = mWindow.HandleEvents();
        mApp->Update();
        return eventType;
    }

    void Engine::Render() {
        mWindow.BeginRender();
        mApp->Render();
        mWindow.EndRender();
    }

    void Engine::Shutdown() {
        //Shutdown systems in reverse order
        mApp->Shutdown();
        mRenderer.Shutdown();
        mWindow.Shutdown();
        SDL_Quit();
        Tools::Logger::Shutdown();
    }
}