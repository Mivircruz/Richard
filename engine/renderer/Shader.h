#pragma once

#include <string>

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

namespace Richard::Renderer {
	class Shader {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Shader.
		*/
		Shader();

		/*
		* Destructor. It cleans up all the subsystems
		* initialized by Initialize() and destroys the object.
		*/
		~Shader();
		
		/*
		* Initialize() initializes the Vertex Shader and the Fragment Shader.
		* It returns 0 in case of success or a non-zero value otherwise.
		* * Error codes:
		* S_INITIALIZE_VERTEX_COMPILATION_FAILED		In case that vertex shader compilation fails.
		* S_INITIALIZE_FRAGMENT_COMPILATION_FAILED		In case that fragment shader compilation fails.
		*/
		int Initialize(const string& vertex, const string& fragment);

		void Bind();

		void Unbind();

		void SetUniformInt(const string& name, int value);
		void SetUniformFloat1(const string& name, float value);
		void SetUniformFloat2(const string& name, float value1, float value2);
		void SetUniformFloat3(const string& name, float value1, float value2, float value3);
		void SetUniformFloat4(const string& name, float value1, float value2, float value3, float value4);

	private:
		/*Member variables*/
		uint32_t mProgramId;

		/*Methods*/

		/*
		* CreateShader creates the shader using the source given.
		* It returns the Shader ID if it succeeded or an invalid ID in case of failure.
		*/
		int CreateShader(const string& source, const string shaderName);
	};
}