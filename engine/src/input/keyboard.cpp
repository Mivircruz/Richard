#include "keyboard.h"

#include "glfw/glfw3.h"

#include "core/engine.h"
#include "graphics/window.h"
#include "tools/logger.h"

namespace Richard::Input {

    /*Public methods*/

    Keyboard::Keyboard() {}

    Keyboard::~Keyboard() {}

    bool Keyboard::IsKeyPressed(int keyName) {
        // Get key state
       auto window = static_cast<GLFWwindow*>(Engine::GetWindow()->Get());
       auto state = glfwGetKey(window, keyName);

       // It will return true if the key is pressed or being held down
       return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
}