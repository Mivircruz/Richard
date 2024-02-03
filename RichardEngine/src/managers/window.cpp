#include "window.h"
#include "constants.h"
#include "tools/logger.h"
#include "SDL.h"
#include "glad/glad.h"

#include <iostream>

using namespace std;


/*
* Constants related to the glad version downloaded
*/
const int GLAD_MAJOR_VERSION = 4;
const int GLAD_MINOR_VERSION = 6;

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
		// Set OpenGL Window attributes before window creation
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GLAD_MAJOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GLAD_MINOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Window creation
		window = SDL_CreateWindow("RichardGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_OPENGL);
		if (!window) {
			Tools::Logger::Error("Error creating window: " + string(SDL_GetError()));
			return W_INTIALIZE_SDL_WINDOW_FAIL;
		}

		// Set the minimum size of a window's client area.
		SDL_SetWindowMinimumSize(window, WINDOW_MIN_WIDTH, WINDOW_MIN_HEIGHT);

		mGLContext = SDL_GL_CreateContext(window);
		if(!mGLContext) {
			Tools::Logger::Error("Error creating OpenGL Context: " + string(SDL_GetError()));
			return W_INITIALIZE_OPENGL_CONTEXT_FAIL;
		}

		gladLoadGLLoader(SDL_GL_GetProcAddress);

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