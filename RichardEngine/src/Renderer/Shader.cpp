#include "Shader.h"
#include "glad/glad.h"
#include "tools/logger.h"

namespace Richard::Renderer {
	/*Public methods*/

	Shader::Shader() {
		// Start the program
		mProgramId = glCreateProgram();
	}

	Shader::~Shader() {
		// Unbind program so it is not in use anymore
		// This allows the program to be deleted
		glUseProgram(0);
		glDeleteProgram(mProgramId);
	}

	int Shader::Initialize(const string& vertex, const string& fragment) {
		// Create vertex shader
		int vertexShaderId = CreateShader(vertex, "Vertex");
		if (!vertexShaderId) {
			Tools::Logger::Error("Shader creation failed. Vertex shader could not be created");
			return S_INITIALIZE_VERTEX_COMPILATION_FAILED;
		}

		// Create fragment shader
		int fragmentShaderId = CreateShader(fragment, "Fragment");
		if (!fragmentShaderId) {
			Tools::Logger::Error("Shader creation failed. Fragment shader could not be created");
			return S_INITIALIZE_FRAGMENT_COMPILATION_FAILED;
		}

		// Link program (TodO: que pingo significa estoooo)
		glLinkProgram(mProgramId);
		glValidateProgram(mProgramId);

		// Check link error status
		int status;
		glGetProgramiv(mProgramId, GL_LINK_STATUS, &status);
		if (status != GL_TRUE) {
			// Get link error message length
			GLint length;
			glGetProgramiv(mProgramId, GL_INFO_LOG_LENGTH, &length);

			// Get link error message
			string errorLog(length, ' ');
			glGetProgramInfoLog(mProgramId, length, &length, &errorLog[0]);

			// Log message
			Tools::Logger::Error("Error linkin shaders: " + errorLog);

			// Delete program
			glDeleteProgram(mProgramId);

			// Set an invalid program ID
			mProgramId = -1;

			return S_INITIALIZE_SHADER_LINK_FAILED;
		}

		// Delete the shaders as the shaders are already in the program
		// Therefore, they are no longer needed
		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);

		return S_INTIALIZE_OK;
	}

	void Shader::Bind() {
		glUseProgram(mProgramId);
	}

	void Shader::Unbind() {
		glUseProgram(0);
	}

	void Shader::SetUniformInt(const string& name, int value) {
		glUseProgram(mProgramId);
		glUniform1i(glGetUniformLocation(mProgramId, name.c_str()), value);
	}

	void Shader::SetUniformFloat1(const string& name, float value) {
		glUseProgram(mProgramId);
		glUniform1f(glGetUniformLocation(mProgramId, name.c_str()), value);
	}

	void Shader::SetUniformFloat2(const string& name, float value1, float value2) {
		glUseProgram(mProgramId);
		glUniform2f(glGetUniformLocation(mProgramId, name.c_str()), value1, value2);
	}

	void Shader::SetUniformFloat3(const string& name, float value1, float value2, float value3) {
		glUseProgram(mProgramId);
		glUniform3f(glGetUniformLocation(mProgramId, name.c_str()), value1, value2, value3);
	}

	void Shader::SetUniformFloat4(const string& name, float value1, float value2, float value3, float value4) {
		glUseProgram(mProgramId);
		glUniform4f(glGetUniformLocation(mProgramId, name.c_str()), value1, value2, value3, value4);
	}





	/*Private methods*/

	int Shader::CreateShader(const string& source, const string shaderName) {
		// Copy the vertex into an OpenGL compatible form type
		const GLchar* glSource = source.c_str();

		// Create vertex shader
		uint32_t shaderId = glCreateShader(GL_VERTEX_SHADER);

		//ToDo: ver que hace??
		glShaderSource(shaderId, 1, &glSource, NULL);

		// Compile vertex shader
		glCompileShader(shaderId);

		// Check if compilation was successful
		GLint isShaderCompiled;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isShaderCompiled);

		// If the compilation failed, handle the error
		if (isShaderCompiled != GL_TRUE) {
			// Get compilation error message length
			GLint length;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);

			// Get compilation error message
			string errorLog(length, ' ');
			glGetShaderInfoLog(shaderId, length, &length, &errorLog[0]);

			// Log message
			Tools::Logger::Error("Error compiling " + shaderName + " shader: " + errorLog);

			// Delete failed shader
			glDeleteShader(shaderId);

			return -1;
		}

		glAttachShader(mProgramId, shaderId);

		return shaderId;
	}
}