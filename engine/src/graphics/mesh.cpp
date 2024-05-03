#include "mesh.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"

namespace Richard::Graphics {
	/*Public methods*/

	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions) {
		mVertexAmount = vertexAmount;

		CreateVAO();

		CreateVBO(vertexArray, vertexAmount * dimensions);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexAmount * dimensions * sizeof(float), (void*)0); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, unbind
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}

	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions) {
		mVertexAmount = vertexAmount;

		CreateVAO();

		CreateVBO(vertexArray, vertexAmount * (posDimensions + colorDimensions));

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexAmount * posDimensions * sizeof(float), (void*)0); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexAmount * colorDimensions * sizeof(float), (void*)(posDimensions * sizeof(float))); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(1); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, unbind
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}

	/*
	* RAI is used to set this up. RAI stands for Resource Acquisition Initialization.
	* This means that the lifetime of this mesh object is going to define the data,
	* so when this object dies, so does the data.
	*/
	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions, uint32_t textureDimensions) {
		mVertexAmount = vertexAmount;

		CreateVAO();

		CreateVBO(vertexArray, vertexAmount * (posDimensions + colorDimensions + textureDimensions));

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (posDimensions + colorDimensions + textureDimensions) * sizeof(float), (void*)0); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(0); RICHARD_CHECK_GL_ERROR;

		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (posDimensions + colorDimensions + textureDimensions) * sizeof(float), (void*)(posDimensions * sizeof(float))); RICHARD_CHECK_GL_ERROR;
		glEnableVertexAttribArray(1); RICHARD_CHECK_GL_ERROR;


		// Texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, (posDimensions + colorDimensions + textureDimensions) * sizeof(float), (void*)((posDimensions + colorDimensions) * sizeof(float)));
		glEnableVertexAttribArray(2);

		// Once the buffers settings are done, unbind
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
	}

	Mesh::Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions, uint32_t textureDimensions, uint32_t* indexArray, uint32_t indexAmount)
		: Mesh(vertexArray, vertexAmount, posDimensions, colorDimensions, textureDimensions) {
		mIndexAmount = indexAmount;

		// Bind the VAO so the EBO can be added to it
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR; RICHARD_CHECK_GL_ERROR;

		// Generate the Element Bufffer Object and make it active
		glGenBuffers(1, &mEBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO); RICHARD_CHECK_GL_ERROR;

		// Upload the data from the CPU to the GPU so it can be used for rendering
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexAmount * sizeof(uint32_t), indexArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;

		// Once the buffers settings are done, unbind
		glBindVertexArray(0); RICHARD_CHECK_GL_ERROR;
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
	uint32_t Mesh::GetIndexAmount() {
		return mIndexAmount;
	}



	/* Private methods */

	void Mesh::CreateVAO() {
		// Generate the Vertex Array Object and make it active
		glGenVertexArrays(1, &mVAO); RICHARD_CHECK_GL_ERROR;
		glBindVertexArray(mVAO); RICHARD_CHECK_GL_ERROR;
	}


	void Mesh::CreateVBO(float* vertexArray, uint32_t dimensions) {
		// Generate the  Vertex Bufffer Object and make it active
		glGenBuffers(1, &mVBO); RICHARD_CHECK_GL_ERROR;
		glBindBuffer(GL_ARRAY_BUFFER, mVBO); RICHARD_CHECK_GL_ERROR;

		// Upload the data from the CPU to the GPU so it can be used for rendering
		glBufferData(GL_ARRAY_BUFFER, dimensions * sizeof(float), vertexArray, GL_STATIC_DRAW); RICHARD_CHECK_GL_ERROR;
	}
}