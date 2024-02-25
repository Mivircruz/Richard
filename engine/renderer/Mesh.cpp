#include "mesh.h"

#include "glad/glad.h"

namespace Richard::Renderer {
	/*Public methods*/

	Mesh::Mesh() {
		mVertexCount = 0;
		mVAO = 0;
		mPositionVBO = 0;
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &mPositionVBO);
		glDeleteVertexArrays(1, &mVAO);
	}

	/*
	* RAI is used to set this up. RAI stands for Resource Acquisition Initialization.
	* This means that the lifetime of this mesh object is going to define the data,
	* so when this object dies, so does the data.
	*/
	int Mesh::Initialize(float* vertexArray, uint64_t vertexCount, uint64_t dimensions) {
		mVertexCount = (uint32_t)vertexCount;

		// Generate the Vertex Array Object and make it active
		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		// Generate the Vertex Bufffer Object and make it active
		glGenBuffers(1, &mPositionVBO);
		glBindBuffer(GL_ARRAY_BUFFER, mPositionVBO);

		// Upload the data from the CPU to the GPU so it can be used for rendering
		// This vertex can be deleted from the CPU after this function is called -> ToDo: responsibility of the creator of this mesh!!!!!!!!!
		glBufferData(GL_ARRAY_BUFFER, vertexCount * dimensions * sizeof(float), vertexArray, GL_STATIC_DRAW);

		// Map the VBO to an attribute for a shader to use
		glEnableVertexAttribArray(0);

		// Specify how to interpret the VBO Data.
		glVertexAttribPointer(0, (GLint)dimensions, GL_FLOAT, GL_FALSE, 0, 0);

		// Once the buffers settings are done, disable and unbind
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return 0;
	}

	void Mesh::Bind() {
		glBindVertexArray(mVAO);
		glEnableVertexAttribArray(0);
	}

	void Mesh::Unbind() {
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}