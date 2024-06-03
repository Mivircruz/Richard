#pragma once

#ifndef WINDOW_H
#define WINDOW_H

struct GLFWwindow;

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
* Constants related to the glad version downloaded
*/
const int OPENGL_MAJOR_VERSION = 4;
const int OPENGL_MINOR_VERSION = 6;
const int GLAD_DEPTH_SIZE = 24;

/*
* Struct that represents the window size
*/
typedef struct {
	int width;
	int height;
} window_size_t;

namespace Richard::Graphics {
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
		* If a size is not specified with SetSize(), it will create a window with the default size: 800x600
		* It returns 0 in case of success or a non-zero value otherwise.
		* * Error codes:
        * E_INTIALIZE_FAIL      In case that SDL Window creation fails.
		*/
		int Initialize();

		/*
		* SetSize() sets the window size.
		* It needs to be called before starting the engine.
		*/
		void SetSize(int width, int height);

		/*
		* SetFullscreen() sets the fullscreen mode.
		*/
		void SetFullscreen();

		/*
		* Shutdown() cleans all the Window member variables 
		* initialized by Initialize().
		*/
		void Shutdown();

		/*
		* HandleEvents() pops out the OS events from the queue and, 
		* depending on the type of event, performs diferent actions.
		*/
		void HandleEvents();

		/*
		* WindowShouldClose() returns true if an escape key was pressed.
		* It returns false otherwise.
		*/
		bool WindowShouldClose();

		/*
		* BeginRender() starts the rendering process.
		*/
		void BeginRender();

		/*
		* EndRender() ends the rendering process.
		*/
		void EndRender();

		/*
		* Get() returns the pointer that points to the window.
		*/
		GLFWwindow* Get();



	private:
		/*Member variables*/

		/*
		* Pointer that points to the window that will receive the OS events.
		*/
		GLFWwindow* pWindow;

		/*
		* Window size
		*/
		window_size_t mSize;

		/*
		* Booleans that indicates whether the window is in full screen or not
		*/
		bool mIsFullScreenOn;

		/*Methods*/

		/*
		* Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly.
		*/
		void Window::ProcessInput();
	};
}

#endif