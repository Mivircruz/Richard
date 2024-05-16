#include "window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>

#include "core/engine.h"
#include "input/mouse.h"
#include "input/keyboard.h"
#include "tools/logger.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

using namespace std;

namespace Richard::Graphics {

	// Function to pass to GLFW to pass to glfwSetFramebufferSizeCallback in Initialize() method.
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height);



	/*Public methods*/
	
	Window::Window() {
		pWindow = nullptr;
		mSize.height = SCR_HEIGHT;
		mSize.width = SCR_WIDTH;
		mIsFullScreenOn = false;
	} 

	Window::~Window() {
		if (pWindow) {
			Shutdown();
		}
	}

	int Window::Initialize() {
		// GLFW initialization
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Window creation
		if (mIsFullScreenOn) {
			pWindow = glfwCreateWindow(mSize.width, mSize.height, "RichardEngine", glfwGetPrimaryMonitor(), NULL);
		}
		else {
			pWindow = glfwCreateWindow(mSize.width, mSize.height, "RichardEngine", NULL, NULL);
		}
		if (pWindow == NULL) {
			Tools::Logger::Critical("Error creating GLFW window");
			Shutdown();
			return -1;
		}
		glfwMakeContextCurrent(pWindow);
		glfwSetFramebufferSizeCallback(pWindow, FramebufferSizeCallback);

		// Load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Tools::Logger::Critical("Error initializing GLAD");
			return -1;
		}

		return W_INTIALIZE_OK;
	}

	void Window::SetSize(int width, int height) {
		mSize.height = height;
		mSize.width = width;
	}

	void Window::SetFullscreen() {
		mIsFullScreenOn = true;
	}

	void Window::Shutdown() {
		glfwTerminate();
	}

	void Window::HandleEvents() {
		ProcessInput();
	}

	bool Window::WindowShouldClose() {
		return glfwWindowShouldClose(pWindow);
	}

	void Window::BeginRender() {
		// Clear frames
		Engine::GetInstance()->GetRenderer()->Clear();
	}

	void Window::EndRender() {
		// Swap buffers and poll IO events (keys pressed/released, mouse moved, etc.)
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}

	GLFWwindow* Window::Get() {
		return pWindow;
	}



	/*Private methods*/

	void Window::ProcessInput() {
		if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(pWindow, true);
	}

	// Whenever the window size changed (by OS or user resize) this callback function executes
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
		// Make sure the viewport matches the new window dimensions.
		glViewport(0, 0, width, height);
	}
}