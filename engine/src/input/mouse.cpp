#include "mouse.h"

#include "glfw/glfw3.h"

#include "core/engine.h"
#include "graphics/window.h"
#include "tools/logger.h"

namespace Richard::Input {
	// Static member creation initialization

	Mouse::Mouse() {}

	Mouse::~Mouse() {}

	std::pair<float, float> Mouse::GetPosition() {
		// Get key state
		auto window = static_cast<GLFWwindow*>(Engine::GetWindow()->Get());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return std::pair{(float)xPos, (float)yPos};
	}
	bool Mouse::IsButtonPressed(int buttonName) {
		// Get button state
		auto window = static_cast<GLFWwindow*>(Engine::GetWindow()->Get());
		auto state = glfwGetMouseButton(window, buttonName);
		return state == GLFW_PRESS;
	}
}
