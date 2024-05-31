#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "client/application.h"
#include "graphics/window.h"
#include "graphics/renderer.h"
#include "physics/gameobjectmanager.h"
#include "tools/logger.h"

/*
* engine_initialize_response represents all the possible Initialize() scenarios.
* It is possible that Initialize() succeeds or that fails
* due to some internal initialization failing
*/
enum engine_initialize_response {
	E_INTIALIZE_OK = 0,
    E_INTIALIZE_SDL_FAIL = -1,
	E_INTIALIZE_WINDOW_FAIL = -2
};

namespace Richard {

    class Engine {

    public:
        /*Methods*/ 

        /*
        * GetInstance() is a static method that returns an instance of the class Engine when it is invoked. 
        * It returns the same instance if it is invoked more than once as an instance of Engine class is already created. 
        */
        static Engine* GetInstance();

        /*
        * GetRenderer() returns the renderer.
        */
        Graphics::Renderer* GetRenderer();

        /*
        * GetGameObjectManager() returns the game object manager.
        */
        Physics::GameObjectManager* GetGameObjectManager();

        /*
        * GetWindow() returns the window.
        */
        static Graphics::Window* GetWindow();

        /*
        * Run() is the game loop.
        * It initializes all the necessary managers to run the game.
        * It also receives the OS events and handles them.
        * When this method returns, the game is over.
        */
        void Run(Application* app);

        /*
        * Methods deleted as this class is a Singleton
        */
        Engine(const Engine& instance) = delete; // Engine class cannot be cloneable.
        void operator=(const Engine&) = delete; // Engine class cannot be asignable.



    private:
        /*Member variables*/

        /*
        * Static pointer which will points to the instance of this class.
        */
        static Engine* pInstance;

        /* 
        * Window that will handle input events
        */
        static Graphics::Window* mWindow;

        /*
        * Render class that will execute the render commands.
        */
        Graphics::Renderer mRenderer;

        /*
        * Manager that will update and render game objects.
        */
        Physics::GameObjectManager mGameObjectManager;

        /*
        * Pointer to the client-defined application.
        */
        Application* pApp;

        /*Methods*/

        /*
        * Private constructor as an instance of this class can only be accessed by GetInstance() method.
        */
        Engine();

        /*
        * Initialize() initializes the SDL library and initializes all the necessary managers.
        * It returns 0 in case of success and a non-zero value otherwise.
        * Error codes:
        * E_INTIALIZE_SDL_FAIL      In case that SDL initizialazation fails.
        * E_INTIALIZE_WINDOW_FAIL   In case that Window Manager initizialazation fails.
        */
        int Initialize();

        /*
        * Update() checks if there are new events.
        * This events can come from many sources: mouse, keyboard, etc.
        * It also executes the Update() method implemented by the client.
        */
       void Update();

       /*
       * Render() makes the rendering process.
       */
       void Render();

        /*
        * Shutdown() cleans up all the initiliazed subsystems such as Window, Logger, etc.
        */
        void Shutdown();
    };

}

#endif