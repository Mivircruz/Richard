#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <utility>

#include "graphics/mesh.h"
#include "graphics/shader.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace std;

namespace Richard::Physics {
	class GameObject {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Gameobject withount initializing anything.
		*/
		GameObject() {}

		/*
		* Destructor. It destroys the object Gameobject.
		*/
		~GameObject() {}

		/*
		* Constructor. It creates the object Gameobject.
		* It receives the size and the position of the object and the mesh and shader necessary to render the object.
		*/
		GameObject(std::pair<double, double> position, std::pair<double, double> size, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader);

		/*
		* SetPosition() sets the object position.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void SetPosition(std::pair<double, double> position);

		/*
		* Move() moves the object position in the direction given.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void Move(std::pair<double, double> direction);

		/*
		* SetSize() sets the object size.
		* The first element represents the widht and the second one, the height.
		*/
		void SetSize(std::pair<double, double> size);

		/*
		* Each class should handle its own rendering.
		*/
		virtual void Render() {}

		/*
		* Each class should handle its own update.
		*/
		virtual void Update() {}


	protected:
		/*Member variables*/

		/*
		* Object position
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		std::pair<double, double> mPosition;

		/*
		* Object size
		* The first element represents the widht and the second one, the height.
		*/
		std::pair<double, double> mSize;

		/*
		* Object speed
		*/
		float mSpeed;

		/*
		* Mesh. 
		* Although the Render method is going to be implemented by the client,
		* a mesh is always necessary to render an object.
		*/
		shared_ptr<Richard::Graphics::Mesh> mMesh;

		/*
		* Shader.
		* Although the Render method is going to be implemented by the client,
		* a shader is always necessary to render an object.
		*/
		shared_ptr<Richard::Graphics::Shader> mShader;
	};
}

#endif