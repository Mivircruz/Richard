#pragma once

/*
* We forward declare this struct so every file that imports this header,
* will not have to import anything SDL_Window related.
* 
* For example, engine.h will not need to import this struct
* and neither will application/src/main.cpp, as it imports engine.h
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
		* It returns an int that represent what kind of event it has just been processed.
		* 0 = default event.
		* 1 = quit event.
		*/
		int HandleEvents();

		/*
		* BeginRender() starts the rendering process.
		*/
		void BeginRender();

		/*
		* EndRender() ends the rendering process.
		*/
		void EndRender();

	private:

		/*Member variables*/

		/*
		* Pointer that points to the window that will receive the OS events.
		*/
		SDL_Window* mWindow;

		/*
		* To use OpenGL within SDL, we need to capture the OpenGL Context
		*/	
		SDL_GLContext mGLContext;
	};
}