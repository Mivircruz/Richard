#pragma once

#ifndef MESH_H
#define MESH_H

#include <cstdint>

/*
* Class where all the VBOs, VAOs and EBOs are gonna get set up
*/
namespace Richard::Graphics {
	class Mesh {
	public:
		/*
		* Constructor. It creates the object Mesh.
		* This constructor is used to create a Mesh with a vertex that only contains positions.
		* It initializes the VAO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* dimensions: the dimension that is going to be used (2D with only x, y coordinates or 3D with x, y, z)
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t dimensions);

		/*
		* Constructor. It creates the object Mesh.
		* This constructor is used to create a Mesh with a vertex that contains positions and colors.
		* It initializes the VAO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* posDimensions: the dimension of the position vertices (2D with only x, y coordinates or 3D with x, y, z)
		* colorDimensions: the dimension of the color vertices
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions);

		/*
		* Constructor. It creates the object Mesh.
		* This constructor is used to create a Mesh with a vertex that contains positions, colors and textures.
		* It initializes the VAO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* posDimensions: the dimension of the position vertices (2D with only x, y coordinates or 3D with x, y, z)
		* colorDimensions: the dimension of the colors.
		* textureDimensions: the dimension of the texture coordinates.
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions, uint32_t textureDimensions);

		/*
		* Constructor. It creates the object Mesh.
		* This constructor is used to create a Mesh with a vertex that contains positions, colors and textures.
		* Besides, it recevies an index array.
		* It initializes the VAO, the VBO and the EBO. It takes the following arguments:
		* vertexArray: the array of vertex, the size of this array may vary.
		* vertexAmount: the amount of vertices in the vertexArray.
		* posDimensions: the dimension of the position vertices (2D with only x, y coordinates or 3D with x, y, z)
		* colorDimensions: the dimension of the colors.
		* textureDimensions: the dimension of the  texture coordinates.
		* indexArray: the array of elements, the size of this array may vary.
		* indexAmount: the amount of elements in the elementArray.
		* Although this engine will work only with 2D dimension, the z coordinate can help with sorting and graphic-related issues.
		*/
		Mesh(float* vertexArray, uint32_t vertexAmount, uint32_t posDimensions, uint32_t colorDimensions, uint32_t textureDimensions, uint32_t* indexArray, uint32_t indexAmount);
		
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
		* GetIndexAmount() returns the amount of elements stored in the EBO.
		*/
		uint32_t GetIndexAmount();



	private:
		/*Methods*/

		/*
		* CreateVAO() creates a VAO and makes it active.
		*/
		void CreateVAO();

		/*
		* CreateVBO() creates a VBO and makes it active.
		* It also uploads the data from the CPU to the GPU.
		*/
		void CreateVBO(float* vertexArray, uint32_t dimensions);


		/*Member variables*/

		/*
		* Amount of vertex in VAO.
		*/
		uint32_t mVertexAmount;

		/*
		* Amount of elements
		*/
		uint32_t mIndexAmount;

		/*
		* Collection of VBOs and EBOs.
		*/
		uint32_t mVAO;

		/*
		* Elements buffer.
		*/
		uint32_t mEBO;

		/*
		* Vertices buffer. It contains the position of the vertices.
		*/
		uint32_t mVBO;
	};
}

#endif