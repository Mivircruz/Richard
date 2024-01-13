#pragma once

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



    private:
        // Member variables

        static Engine* Instance; //  Static pointer which will points to the instance of this class.


        // Methods

        Engine() {}; // Private constructor as an instance of this class can only be accessed by GetInstance() method.

        /*
        * Initialize() initializes the SDL library.
        * It returns 0 in case of success and a non-zero value otherwise.
        */
        int Initialize();

        /*
        * Shutdown() clenas up all SDL initiliazed subsystems
        */
        void Shutdown();

    };

}