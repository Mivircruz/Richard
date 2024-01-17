#pragma once

#include "managers/window.h"

namespace Richard {

    class Engine {

    public:
        // Methods

        /*
        * GetInstance() is a static method that returns an instance of the class Engine when it is invoked. 
        * It returns the same instance if it is invoked more than once as an instance of Engine class is already created. 
        */
        static Engine* GetInstance();

        Engine(const Engine& instance) = delete; // Engine class cannot be cloneable.

        void operator=(const Engine&) = delete; // Engine class cannot be asignable.

        /*
        * Run() is the game loop
        * It initializes all the necessary managers to run the game.
        * It also receives the OS events and handles them.
        * When this method returns, the game is over.
        */
        void Run();



    private:
        // Member variables

        /*Static pointer which will points to the instance of this class.*/
        static Engine* Instance;

        /* Window that will handle input events*/
        Richard::Managers::Window window;


        // Methods

        inline Engine() {}; // Private constructor as an instance of this class can only be accessed by GetInstance() method.

        /*
        * Initialize() initializes the SDL library and creates all the necessary managers.
        * It returns 0 in case of success and a non-zero value otherwise.
        */
        int Initialize();

        /*
        * Shutdown() cleans up all SDL initiliazed subsystems
        */
        void Shutdown();
    };

}