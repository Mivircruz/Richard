#include "Shader.h"

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "tools/errorchecker.h"
#include "tools/logger.h"

namespace Richard::Graphics {
	/*Public methods*/

	Shader::Shader(const char* vertexPath, const char* fragmentPath) {
		// Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// Ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			// Open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;

			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			// Close file handlers
			vShaderFile.close();
			fShaderFile.close();

			// Convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure& e) {
			(void)e;
			string shaderMsg = "Shader could not read files. Error: ";
			const char* errorMsg = e.what();
			string logMsg = shaderMsg + errorMsg;
			Tools::Logger::Error(logMsg);
		}

		// Create vertex shader
		int vertexShaderId = CreateShader(vertexCode, "Vertex", GL_VERTEX_SHADER);
		if (!vertexShaderId) {
			Tools::Logger::Error("Shader creation failed. Error creating Vertex shader.");
			return;
		}

		// Create fragment shader
		int fragmentShaderId = CreateShader(fragmentCode, "Fragment", GL_FRAGMENT_SHADER);
		if (!fragmentShaderId) {
			Tools::Logger::Error("Shader creation failed. Error creating Fragment shader");
			return;
		}

		// Start the program and attach shaders
		mShaderProgram = glCreateProgram(); RICHARD_CHECK_GL_ERROR;
		glAttachShader(mShaderProgram, vertexShaderId); RICHARD_CHECK_GL_ERROR;
		glAttachShader(mShaderProgram, fragmentShaderId); RICHARD_CHECK_GL_ERROR;


		// Link program
		glLinkProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;

		// Check link error status
		int status;
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status); RICHARD_CHECK_GL_ERROR;
		if (status != GL_TRUE) {
			// Get link error message length
			GLint length;
			glGetProgramiv(mShaderProgram, GL_INFO_LOG_LENGTH, &length); RICHARD_CHECK_GL_ERROR;

			// Get link error message and log it
			string errorLog(length, ' ');
			glGetProgramInfoLog(mShaderProgram, length, &length, &errorLog[0]); RICHARD_CHECK_GL_ERROR;
			Tools::Logger::Error("Error linkin shaders: " + errorLog);

			// Delete program
			glDeleteProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;

			// Set an invalid program ID
			mShaderProgram = -1;
			return;
		}

		// Delete the shaders as the shaders are already in the program
		// Therefore, they are no longer needed
		glDeleteShader(vertexShaderId); RICHARD_CHECK_GL_ERROR;
		glDeleteShader(fragmentShaderId); RICHARD_CHECK_GL_ERROR
	}

	Shader::~Shader() {
		// Unbind program so it is not in use anymore
		// This allows the program to be deleted
		glUseProgram(0); RICHARD_CHECK_GL_ERROR;
		glDeleteProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::Bind() {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::Unbind() {
		glUseProgram(0); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::SetUniformInt(const string& name, int value) {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
		glUniform1i(glGetUniformLocation(mShaderProgram, name.c_str()), value); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::SetUniformFloat1(const string& name, float value) {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
		glUniform1f(glGetUniformLocation(mShaderProgram, name.c_str()), value); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::SetUniformFloat2(const string& name, float value1, float value2) {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
		glUniform2f(glGetUniformLocation(mShaderProgram, name.c_str()), value1, value2); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::SetUniformFloat3(const string& name, float value1, float value2, float value3) {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
		glUniform3f(glGetUniformLocation(mShaderProgram, name.c_str()), value1, value2, value3); RICHARD_CHECK_GL_ERROR;
	}

	void Shader::SetUniformFloat4(const string& name, float value1, float value2, float value3, float value4) {
		glUseProgram(mShaderProgram); RICHARD_CHECK_GL_ERROR;
		glUniform4f(glGetUniformLocation(mShaderProgram, name.c_str()), value1, value2, value3, value4); RICHARD_CHECK_GL_ERROR;
	}





	/*Private methods*/

	int Shader::CreateShader(const string& source, const string shaderName, uint32_t shaderType) {
		// Copy the vertex into an OpenGL compatible form type
		const GLchar* glSource = source.c_str();

		// Create vertex shader and compile it
		uint32_t shaderId = glCreateShader(shaderType); RICHARD_CHECK_GL_ERROR;
		glShaderSource(shaderId, 1, &glSource, NULL); RICHARD_CHECK_GL_ERROR;
		glCompileShader(shaderId); 

		// Check if compilation was successful
		GLint isShaderCompiled;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isShaderCompiled); RICHARD_CHECK_GL_ERROR;
		if (isShaderCompiled != GL_TRUE) {
			// Get compilation error message length
			GLint length;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length); RICHARD_CHECK_GL_ERROR;

			// Get compilation error message and log it
			string errorLog(length, ' ');
			glGetShaderInfoLog(shaderId, length, &length, &errorLog[0]); RICHARD_CHECK_GL_ERROR;
			Tools::Logger::Error("Error compiling " + shaderName + " shader: " + errorLog);

			// Delete failed shader
			glDeleteShader(shaderId); RICHARD_CHECK_GL_ERROR;

			return -1;
		}

		return shaderId;
	}
}