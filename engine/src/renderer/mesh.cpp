#include "mesh.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"

namespace Richard::Subsystems::Render {
	/*Public methods*/

	Mesh::Mesh() {
		mVertexAmount = 0;
		mElementsAmount = 0;
		mVAO = 0;
		mEBO = 0;
		mVBO = 0;
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &mVBO); RICHARD_CHECK_GL_ERROR;
		if (mEBO) {
			glDeleteBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;
		}
		glDeleteVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
	}

	/*
	* RAI is used to set this up. RAI stands for Resource Acquisition Initialization.
	* This means that the lifetime of this mesh object is going to define the data,
	* so when this object dies, so does the data.
	*/
	int Mesh::Initialize(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions) {
		mVertexAmount = vertexAmount;

		// Generate the Vertex Array Object and make it active
		glGenVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;

		// Generate the Vertex Bufffer Object and make it active
		glGenBuffers(1, &mVBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ARRAY_BUFFER, mVBO); RICHARD_CHECK_GL_ERROR;

		// Upload the data from the CPU to the GPU so it can be used for rendering
		// This vertex can be deleted from the CPU after this function is called -> ToDo: responsibility of the creator of this mesh!!!!!!!!!
		glBufferData(GL_ARRAY_BUFFER, vertexAmount * dimensions * sizeof(float), vertexArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;

		// Map the VBO to an attribute for a shader to use
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Specify how to interpret the VBO Data.
		glVertexAttribPointer(0, (GLint)dimensions, GL_FLOAT, GL_FALSE, 0, 0); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, disable and unbind
		glDisableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ARRAY_BUFFER, 0); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;

		return 0;
	}

	int Render::Mesh::Initialize(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions, uint32_t* elementArray, uint32_t elementAmount) {
		Initialize(vertexArray, vertexAmount, dimensions);

		mElementsAmount = elementAmount;

		// Bind the VAO so the EBO can be added to it
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR; RICHARD_CHECK_GL_ERROR;

		// Generate the Element Bufffer Object and make it active
		glGenBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO); RICHARD_CHECK_GL_ERROR;

		// Upload the data from the CPU to the GPU so it can be used for rendering
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementAmount * sizeof(uint32_t), elementArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, disable and unbind
		// The EBO is cannot be unbined because there is only one EBO per VAO
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;

		return 0;
	}

	void Mesh::Bind() {
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;
	}

	void Mesh::Unbind() {
		glDisableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}
	uint32_t Mesh::GetVertexAmount() {
		return mVertexAmount;
	}
	uint32_t Render::Mesh::GetElementsAmount() {
		return mElementsAmount;
	}
}