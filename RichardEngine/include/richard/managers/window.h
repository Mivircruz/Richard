#pragma once

/*
* A WINDOW_EVENT represents the OS events that the method HandleEvents() may receive.
* It is used to indicate those functions that call HandleEvents() which event
* was popped out and processed.
*/
enum WINDOW_EVENT {
	DEFAULT = 0,
	QUIT = 1
};

/*
* We forward declare this struct so every file that imports this header,
* will not have to import anything SDL_Window related.
* 
* For example, engine.h will not need to import this struct
* and neither will RichardEditor/src/main.cpp, as it imports engine.h
*/
struct SDL_Window;


namespace Richard::Managers {
	class Window {
	public:
		// Methods
		Window();
		~Window();

		int Initialize();
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
		SDL_Window* window;
	};
}