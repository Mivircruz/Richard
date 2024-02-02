#include "window.h"
#include "constants.h"
#include "tools/logger.h"
#include "SDL.h"

#include <iostream>

using namespace std;

namespace Richard::Managers {
	/*Public methods*/
	
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
			Tools::Logger::Error("Error creating window: " + string(SDL_GetError()));
			return W_INTIALIZE_FAIL;
		}
		return W_INTIALIZE_OK;
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
				return EVENT_QUIT;
			default:
				break;
			}
		}

		return EVENT_DEFAULT;
	}
}