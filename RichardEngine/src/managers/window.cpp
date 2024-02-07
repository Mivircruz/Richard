#include "window.h"
#include "constants.h"
#include "tools/logger.h"
#include "SDL.h"
#include "glad/glad.h"

#include <iostream>

using namespace std;

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
		// Before the window creation, we specify the OpenGL version and the profile that we want
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GLAD_MAJOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GLAD_MINOR_VERSION);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		// Graphic specifications: 
		// Window updates twice as often and has 24 bits for the color
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, GLAD_DEPTH_SIZE);

		// Window creation for our platform
		mWindow = SDL_CreateWindow("RichardGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		if (!mWindow) {
			Tools::Logger::Error("Error creating window: " + string(SDL_GetError()));
			return W_INTIALIZE_SDL_WINDOW_FAIL;
		}
	
		// Set the minimum size of a window's client area.
		SDL_SetWindowMinimumSize(mWindow, WINDOW_MIN_WIDTH, WINDOW_MIN_HEIGHT);

		// OpenGL Context creation
		// It sets up the graphics context
		mGLContext = SDL_GL_CreateContext(mWindow);
		if(!mGLContext) {
			Tools::Logger::Error("Error creating OpenGL Context: " + string(SDL_GetError()));
			return W_INITIALIZE_OPENGL_CONTEXT_FAIL;
		}

		// Set up the funcion pointers
		gladLoadGLLoader(SDL_GL_GetProcAddress);

		// Set the background color
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

		// Updates the window with OpenGL rendering.
		SDL_GL_SwapWindow(mWindow);
	}
}