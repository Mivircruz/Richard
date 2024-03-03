#include "errorchecker.h"
#include <string>
#include "logger.h"

using namespace std;

namespace Richard::Tools {
    void CheckGLError() {
        GLenum error = glGetError();
        if (error == GL_NO_ERROR) {
            return;
        }
        string errorMsg;

        switch (error) {
        case GL_INVALID_ENUM:
            errorMsg = "GL_INVALID_ENUM. " + to_string(error);
                break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            errorMsg = "GL_INVALID_FRAMEBUFFER_OPERATION. " + to_string(error);
            break;
        case GL_INVALID_INDEX:
            errorMsg = "GL_INVALID_INDEX. " + to_string(error);
            break;
        case GL_INVALID_OPERATION:
            errorMsg = "GL_INVALID_OPERATION. " + to_string(error);
            break;
        case GL_INVALID_VALUE:
            errorMsg = "GL_INVALID_VALUE. " + to_string(error);
            break;
        default:
            errorMsg = "GL_UNKNOWN_ERROR. " + to_string(error);
            break;
         }

        // After an OpenGL Error, the app should crash.
        Logger::Critical("OpenGL Fatal Error. " + errorMsg);
    }
}