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
		mWindow = nullptr;
	} 

	Window::~Window() {
		if (mWindow) {
			Shutdown();
		}
	}

	int Window::Initialize() {
		// Window creation
		mWindow = SDL_CreateWindow("RichardGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		if (!mWindow) {
			Tools::Logger::Error("Error creating window: " + string(SDL_GetError()));
			return W_INTIALIZE_SDL_WINDOW_FAIL;
		}

		// Set OpenGL Window attributes
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GLAD_MAJOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GLAD_MINOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Set the minimum size of a window's client area.
		SDL_SetWindowMinimumSize(mWindow, WINDOW_MIN_WIDTH, WINDOW_MIN_HEIGHT);

		mGLContext = SDL_GL_CreateContext(mWindow);
		if(!mGLContext) {
			Tools::Logger::Error("Error creating OpenGL Context: " + string(SDL_GetError()));
			return W_INITIALIZE_OPENGL_CONTEXT_FAIL;
		}

		gladLoadGLLoader(SDL_GL_GetProcAddress);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Sets background color
		glClearColor(0.0,0.0,1.0,0.0);

		return W_INTIALIZE_OK;
	}

	void Window::Shutdown() {
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
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

	void Window::Render() {
		// Clears the color of the screen (color buffer) and
		// any cached information about the depth of what the window just rendered (depth buffer)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(mWindow);
	}
}