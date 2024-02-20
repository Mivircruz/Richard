#pragma once

#include <cstdint>

/*
* Class where all the VBOs, VAOs and EBOs are gonna get set up
*/
namespace Richard::Renderer {
	class Mesh {
	public:

		/*
		* Constructor. It creates the object Mesh.
		*/
		Mesh();

		/*
		* Destructor. It deletes the VAO and the VBO initialized by Initialize() and destroys the object.
		*/
		~Mesh();

		/*
		* Initialize() initializes the VAO and the VBO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexCount: the amount of vertices in the vertexArray.
		* dimensions: the dimension that is going to be used (2D with only x, y coordinates or 3D with x, y, z)
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		int Initialize(float* vertexArray, uint64_t vertexCount, uint64_t dimensions);

		/*
		* Bind() enables the VAO for its usage and it binds it.
		*/
		void Bind();

		/*
		* Unbind() disables the VAO and it unbinds it.
		*/
		void Unbind();


	private:
		/*Member variables*/

		/*
		* Amount of vertex in VAO.
		*/
		uint32_t mVertexCount;

		/*
		* Array of vertices.
		*/
		uint32_t mVAO;

		/*
		* Useful to know what to bind, what to unbind, what to delete.
		*/
		uint32_t mPositionVBO;
	};
}
