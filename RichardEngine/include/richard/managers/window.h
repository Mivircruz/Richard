#pragma once

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
		void HandleEvents();

	private:
		SDL_Window* window;
	};
}