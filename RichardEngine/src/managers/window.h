#pragma once

/*
* We forward declare this struct so every file that imports this header,
* will not have to import anything SDL_Window related.
* 
* For example, engine.h will not need to import this struct
* and neither will RichardEditor/src/main.cpp, as it imports engine.h
*/
struct SDL_Window;

/*
* We forward declare this typo
*/
using SDL_GLContext = void*;

namespace Richard::Managers {
	class Window {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Window.
		*/
		Window();

		/*
		* Destructor. It cleans up all the subsystems 
		* initialized by Initialize() and destroys the object.
		*/
		~Window();

		/*
		* Initialize() initializes all the Window member variables.
		* It returns 0 in case of success or a non-zero value otherwise.
		* * Error codes:
        * E_INTIALIZE_FAIL      In case that SDL Window creation fails.
		*/
		int Initialize();

		/*
		* Shutdown() cleans all the Window member variables 
		* initialized by Initialize().
		*/
		void Shutdown();

		/*
		* HandleEvents() pops out the OS events from the queue and, 
		* depending on the type of event, performs diferent actions.
		* 
		* It also receives a boolean that indicates whether the queue 
		* is not empty or not.
		*/
		int HandleEvents();



	private:

		/*Member variables*/

		/*
		* Pointer that points to the window that will receive the OS events.
		*/
		SDL_Window* window;

		/*
		* To use OpenGL within SDL, we need to capture the OpenGL Context
		*/	
		SDL_GLContext mGLContext;
	};
}