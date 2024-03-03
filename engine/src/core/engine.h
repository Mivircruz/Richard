#pragma once

#include "window.h"
#include "renderer/renderer.h"
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
        Subsystems::Renderer* GetRenderer();

        /*
        * Run() is the game loop.
        * It initializes all the necessary managers to run the game.
        * It also receives the OS events and handles them.
        * When this method returns, the game is over.
        */
        void Run();

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
        static Engine* Instance;

        /* 
        * Window that will handle input events
        */
        Managers::Window mWindow;

        /*
        * Render class that will execute the render commands.
        */
        Subsystems::Renderer mRenderer;

        /*Methods*/

        /*
        * Private constructor as an instance of this class can only be accessed by GetInstance() method.
        */
        inline Engine() {};

        /*
        * Initialize() initializes the SDL library and initializes all the necessary managers.
        * It returns 0 in case of success and a non-zero value otherwise.
        * Error codes:
        * E_INTIALIZE_SDL_FAIL      In case that SDL initizialazation fails.
        * E_INTIALIZE_WINDOW_FAIL   In case that Window Manager initizialazation fails.
        */
        int Initialize();

        /*
        * Shutdown() cleans up SDL2 and all the initiliazed managers.
        */
        void Shutdown();
    };

}