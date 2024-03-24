#pragma once

/*
* window_event represents the OS events that the method HandleEvents() may receive.
* It is used to indicate those functions that call HandleEvents() which event
* was popped out and processed.
*/
enum window_event {
	EVENT_DEFAULT = 0,
	EVENT_QUIT = 1
};

/*
* window_initialize_response represents all the possible Initialize() scenarios.
* It is possible that Initialize() succeeds or that fails
* due to some internal initialization failing.
*/
enum window_initialize_response {
	W_INTIALIZE_OK = 0,
	W_INTIALIZE_SDL_WINDOW_FAIL = -1,
	W_INITIALIZE_OPENGL_CONTEXT_FAIL = -2
};

/*
* Constants realated to the window size
*/
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_MIN_WIDTH = 400;
const int WINDOW_MIN_HEIGHT = 200;

/*
* Constants related to the glad version downloaded
*/
const int GLAD_MAJOR_VERSION = 4;
const int GLAD_MINOR_VERSION = 6;
const int GLAD_DEPTH_SIZE = 24;

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
		SDL_Window* pWindow;

		/*
		* To use OpenGL within SDL, we need to capture the OpenGL Context
		*/	
		SDL_GLContext mGLContext;
	};
}