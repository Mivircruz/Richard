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
	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions, float* textureCoordinates, uint32_t* indexArray, uint32_t indexAmount) {
		mIndexAmount = indexAmount;
		mVertexAmount = vertexAmount;

		// Generate the Vertex Array Object, the Vertex Bufffer Object and the Element Bufffer Object
		glGenVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
		glGenBuffers(1, &mVBO); RICHARD_CHECK_GL_ERROR;
		glGenBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;

		// Make the Vertex Array Object, the Vertex Bufffer Object and the Element Bufffer Object active
		// Also uploads the data from the CPU to the GPU so it can be used for rendering
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;

		glBindBuffer(GL_ARRAY_BUFFER, mVBO); RICHARD_CHECK_GL_ERROR;
		glBufferData(GL_ARRAY_BUFFER, vertexAmount * dimensions * sizeof(float), vertexArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO); RICHARD_CHECK_GL_ERROR;
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexAmount * sizeof(uint32_t), indexArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;

		// Specify how to interpret the VBO Data and map the VBO to an attribute for a shader to use

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, dimensions * sizeof(float), (void*)0); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, dimensions * sizeof(float), (void*)(3 * sizeof(float))); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(1); RICHARD_CHECK_GL_ERROR;

		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, dimensions * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &mVBO); RICHARD_CHECK_GL_ERROR;
		if (mEBO) {
			glDeleteBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;
		}
		glDeleteVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
	}

	void Mesh::Bind() {
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;
	}

	void Mesh::Unbind() {
		glDisableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}
	uint32_t Mesh::GetVertexAmount() {
		return mVertexAmount;
	}
	uint32_t Mesh::GetElementsAmount() {
		return mIndexAmount;
	}
}