#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "glm/glm.hpp"

using namespace std;

/*
* shader_initialize_response represents all the possible Initialize() scenarios.
* It is possible that Initialize() succeeds or that fails
* due to some internal initialization failing.
*/
enum shader_initialize_response {
	S_INTIALIZE_OK = 0,
	S_INITIALIZE_VERTEX_COMPILATION_FAILED = -1,
	S_INITIALIZE_FRAGMENT_COMPILATION_FAILED = -2,
	S_INITIALIZE_SHADER_LINK_FAILED = -3
};

namespace Richard::Graphics {
	class Shader {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Shader.
		* It also initializes the Vertex Shader and the Fragment Shader.
		*/
		Shader(const char* vertexPath, const char* fragmentPath);

		/*
		* Destructor. It cleans up all the subsystems
		* initialized by Initialize() and destroys the object.
		*/
		~Shader();

		/*
		Bind() binds the program that contains both Vertex Shader and Fragment Shader.
		*/
		void Bind();

		/*
		Unbind() binds the program that contains both Vertex Shader and Fragment Shader.
		*/
		void Unbind();

		/*
		* The following methods specify the value of a uniform variable for the current program object.
		* The difference between them is the type and amount of argument they receive.
		* Using these methods we can actually assign a location value, known as texture unit,	
		* to the texture sampler so we can set multiple textures at once in a fragment shader.
		* The default texture unit for a texture is 0 which is the default active texture unit,
		* so is not necessary to assign a location if there is only one texture to be rendered.
		*/
		void SetUniformInt(const string& name, int value);
		void SetUniformFloat1(const string& name, float value);
		void SetUniformFloat2(const string& name, float value1, float value2);
		void SetUniformFloat3(const string& name, float value1, float value2, float value3);
		void SetUniformFloat4(const string& name, float value1, float value2, float value3, float value4);

		void SetUniformFloat2(const string& name, const glm::vec2& values);
		void SetUniformFloat3(const string& name, const glm::vec3& values);
		void SetUniformFloat4(const string& name, const glm::vec4& values);

		void SetUniformMat3(const string& name, const glm::mat3& matrix);
		void SetUniformMat4(const string& name, const glm::mat4& matrix);



	private:
		/*Member variables*/
		uint32_t mShaderProgram;


		/*Methods*/

		/*
		* CreateShader creates the shader using the source given.
		* It returns the Shader ID if it succeeded or an invalid ID in case of failure.
		*/
		int CreateShader(const string& source, const string shaderName, uint32_t shaderType);
	};
}

#endif