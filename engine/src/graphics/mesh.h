#pragma once

#include <cstdint>

/*
* Class where all the VBOs, VAOs and EBOs are gonna get set up
*/
namespace Richard::Graphics {
	class Mesh {
	public:

		/*
		* Constructor. It creates the object Mesh.
		* It initializes the VAO and the VBO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* dimensions: the dimension that is going to be used (2D with only x, y coordinates or 3D with x, y, z)
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions);

		/*
		* Constructor. It creates the object Mesh.
		* It initializes the VAO, the VBO and the EBO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* dimensions: the dimension that is going to be used (2D with only x, y coordinates or 3D with x, y, z)
		* elementArray: the array of elements, the size of this array may vary.
		* elementAmount: the amount of elements in the elementArray.
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions, uint32_t* elementArray, uint32_t elementAmount);
		
		/*
		* Destructor. Deletes the VAO and the VBO and destroys the object.
		*/
		~Mesh();

		/*
		* Bind() enables the VAO for its usage and it binds it.
		*/
		void Bind();

		/*
		* Unbind() disables the VAO and it unbinds it.
		*/
		void Unbind();

		/*
		* GetVertexAmount() returns the amount of vertices stored in the VAO.
		*/
		uint32_t GetVertexAmount();

		/*
		* GetElementsAmount() returns the amount of elements stored in the EBO.
		*/
		uint32_t GetElementsAmount();



	private:
		/*Member variables*/

		/*
		* Amount of vertex in VAO.
		*/
		uint32_t mVertexAmount;

		/*
		* Amount of elements
		*/
		uint32_t mElementsAmount;

		/*
		* Collection of VBOs and EBOs.
		*/
		uint32_t mVAO;

		/*
		* Elements buffer.
		*/
		uint32_t mEBO;

		/*
		* Vertices buffer.
		*/
		uint32_t mVBO;
	};
}
