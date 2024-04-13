#include "mesh.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"

namespace Richard::Graphics {
	/*Public methods*/

	/*
	* RAI is used to set this up. RAI stands for Resource Acquisition Initialization.
	* This means that the lifetime of this mesh object is going to define the data,
	* so when this object dies, so does the data.
	*/
	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions) {
		mVertexAmount = vertexAmount;

		// Generate the Vertex Array Object and make it active
		glGenVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;

		// Generate the Vertex Bufffer Object and make it active
		glGenBuffers(1, &mPositionVBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ARRAY_BUFFER, mPositionVBO); RICHARD_CHECK_GL_ERROR;

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
	}

	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions, uint32_t* elementArray, uint32_t elementAmount) 
		: Mesh(vertexArray, vertexAmount, dimensions) {
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
	}

	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions, float* textureCoordinates, uint32_t* elementArray, uint32_t elementAmount)
		: Mesh(vertexArray, vertexAmount, dimensions, elementArray, elementAmount) {
		// Generate the Vertex Array Object and make it active
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;

		// Generate the Vertex Bufffer Object and make it active
		glGenBuffers(1, &mTextureVBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ARRAY_BUFFER, mTextureVBO); RICHARD_CHECK_GL_ERROR;

		// Upload the data from the CPU to the GPU so it can be used for rendering
		// This vertex can be deleted from the CPU after this function is called -> ToDo: responsibility of the creator of this mesh!!!!!!!!!
		// The dimension per vertex in this case is 2 because texture coordinates are usually in two dimensions
		glBufferData(GL_ARRAY_BUFFER, vertexAmount * 2 * sizeof(float), textureCoordinates, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;

		// Map the VBO to an attribute for a shader to use
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Specify how to interpret the VBO Data.
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, disable and unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &mPositionVBO); RICHARD_CHECK_GL_ERROR;
		if (mEBO) {
			glDeleteBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;
		}
		glDeleteVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
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
	uint32_t Mesh::GetElementsAmount() {
		return mElementsAmount;
	}
}