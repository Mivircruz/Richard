#include "window.h"
#include "constants.h"
#include "engine.h"
#include "events/mouse.h"
#include "tools/logger.h"
#include "SDL.h"
#include "glad/glad.h"

#include <iostream>
#include <string>

using namespace std;

namespace Richard::Managers {
	/*Public methods*/
	
	Window::Window() {
		mWindow = nullptr;
		mGLContext = nullptr;
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

		return W_INTIALIZE_OK;
	}

	void Window::Shutdown() {
		SDL_DestroyWindow(mWindow);
		SDL_GL_DeleteContext(mGLContext);
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

		// Update mouse input
		Events::Periphericals::Mouse::Update();

		// Log mouse info to check that is reading the mouse input
		Tools::Logger::Info("X: " + to_string(Events::Periphericals::Mouse::GetXCurrentPosition()) +
		", Y: " + to_string(Events::Periphericals::Mouse::GetYCurrentPosition()) +
		", Left button: " + to_string(Events::Periphericals::Mouse::GetButtonCurrentState(MOUSE_BUTTON_LEFT)) +
		", Middle button: " + to_string(Events::Periphericals::Mouse::GetButtonCurrentState(MOUSE_BUTTON_MIDDLE)) +
		", Right button: " + to_string(Events::Periphericals::Mouse::GetButtonCurrentState(MOUSE_BUTTON_RIGHT)) +
		", X1 button: " + to_string(Events::Periphericals::Mouse::GetButtonCurrentState(MOUSE_BUTTON_X1)) +
		", X2 button: " + to_string(Events::Periphericals::Mouse::GetButtonCurrentState(MOUSE_BUTTON_X2))
		);

		return EVENT_DEFAULT;
	}

	void Window::BeginRender() {
		// Clear frames
		Engine::GetInstance()->GetRenderer()->Clear();
	}

	void Window::EndRender() {
		// Updates the window with OpenGL rendering
		SDL_GL_SwapWindow(mWindow);
	}
}