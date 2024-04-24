#include "engine.h"
#include "input/mouse.h"
#include "input/keyboard.h"
#include "graphics/mesh.h"
#include "graphics/rendermesh.h"
#include "graphics/shader.h"
#include <iostream>
#include <string>

using namespace std;

namespace Richard {
    /*Public methods*/

    Engine* Engine::GetInstance() {
        if (!pInstance) {
            pInstance = new Engine();
        }

        return pInstance;
    }

    Graphics::Renderer* Engine::GetRenderer() {
        return &mRenderer;
    }

    void Engine::Run(Application* app) {
        // Initialize all the managers
        if (Initialize() < 0) {
            Tools::Logger::Error("Error running game loop");
            return;
        }

        // Check application provided
        if(pApp) {
            Tools::Logger::Warning("Richard Engine already has an application defined. This one will be replaced");
        } else if(!app) {
            Tools::Logger::Error("No Application provided for the engine to run.");
            return;
        }

        // Initialize the client-defined application
        pApp = app;
        pApp->Initialize();

        // Start game loop
        while (!mWindow.WindowShouldClose()) {
            Update();
            Render();
        }
        
        // Shutdown all the managers and quit SDL2
        Shutdown();
    }



    /*Private methods and member variables*/

    // Initialize the pointer that will point to the instance class
    Engine* Engine::pInstance = nullptr;

    Engine::Engine() {
        pApp = nullptr;
    }

    int Engine::Initialize() {
        // Logger initialization
        Tools::Logger::Initialize();

        // Window Initialization
        if (mWindow.Initialize() < 0) {
            Tools::Logger::Error("Error initializing Window Manager. Shutting down engine.");
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return E_INTIALIZE_WINDOW_FAIL;
        }

        // Input handlers initialization
        Input::Mouse::Initialize();
        Input::Keyboard::Initialize();

        // Renderer initialization
        mRenderer.Initialize();

        return E_INTIALIZE_OK;
    }

    void Engine::Update() {
        mWindow.HandleEvents();
        pApp->Update();
    }

    void Engine::Render() {
        mWindow.BeginRender();
        pApp->Render();
        mWindow.EndRender();
    }

    void Engine::Shutdown() {
        //Shutdown systems in reverse order
        pApp->Shutdown();
        mRenderer.Shutdown();
        Input::Keyboard::Shutdown();
        Input::Mouse::Shutdown();
        mWindow.Shutdown();
        Tools::Logger::Shutdown();
    }
}