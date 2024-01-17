#include "managers/window.h"
#include "SDL.h"

#include <iostream>

using namespace std;

namespace Richard::Managers {
	// Public methods
	
	Window::Window() {
		window = nullptr;
	} 

	Window::~Window() {
		if (window) {
			Shutdown();
		}
	}

	int Window::Initialize() {
		window = SDL_CreateWindow("RichardGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		if (!window) {
			cout << "Error creating window: " << SDL_GetError() << endl;
			return -1;
		}
		return 0;
	}

	void Window::Shutdown() {
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	int Window::HandleEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return QUIT;
			default:
				break;
			}
		}

		return DEFAULT;
	}
}