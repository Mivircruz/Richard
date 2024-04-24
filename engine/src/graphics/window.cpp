#include "window.h"
#include "core/engine.h"
#include "input/mouse.h"
#include "input/keyboard.h"
#include "tools/logger.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <string>

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
		pWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "RichardEngine", NULL, NULL);
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

	void Window::Shutdown() {
		glfwTerminate();
	}

	void Window::HandleEvents() {
		// input
		ProcessInput();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(pWindow);
		glfwPollEvents();

		// Update mouse input
		//Input::Mouse::Update(); //ToDo: cambiar esto
		//Input::Keyboard::Update(); //ToDo: cambiar esto
	}

	bool Window::WindowShouldClose() {
		return glfwWindowShouldClose(pWindow);
	}

	void Window::BeginRender() {
		// Clear frames
		Engine::GetInstance()->GetRenderer()->Clear();
	}

	void Window::EndRender() {
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