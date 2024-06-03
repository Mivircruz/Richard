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
		GameObject(pair<double, double> position, pair<double, double> size, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader);

		/*
		* Constructor. It creates the object Gameobject.
		* It receives the size and the position of the object and the mesh and shader necessary to render the object.
		* It also receives the velocity
		*/
		GameObject(pair<double, double> position, pair<double, double> size, pair<double, double> velocity, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader);

		/*
		* Constructor. It creates the object Gameobject.
		* It receives the size and the position of the object and the mesh and shader necessary to render the object.
		* It also receives the velocity and the acceleration
		*/
		GameObject(pair<double, double> position, pair<double, double> size, pair<double, double> velocity, pair<double, double> acceleration, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader);


		/*
		* SetPosition() sets the object position.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void SetPosition(pair<double, double> position);

		/*
		* GetPosition() returns the object position.
		*/
		pair<double, double> GetPosition();

		/*
		* GetPosition() returns the object initial position.
		*/
		pair<double, double> GetInitialPosition();

		/*
		* SetSize() sets the object size.
		* The first element represents the widht and the second one, the height.
		*/
		void SetSize(pair<double, double> size);

		/*
		* GetSize() returns the object size.
		*/
		pair<double, double> GetSize();

		/*
		* GetInitialSize() returns the object initial size.
		*/
		pair<double, double> GetInitialSize();

		/*
		* SetVelocity() sets the object velocity.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void SetVelocity(pair<double, double> speed);

		/*
		* GetVelocity() returns the object velocity.
		*/
		pair<double, double> GetVelocity();

		/*
		* GetVelocityModule() returns the module of the velocity.
		*/
		double GetVelocityModule();

		/*
		* IncreaseVelocity() increases the velocity of the object without changing its direction.
		* Every time the loop iterates, it increases the velocity multiplying the factor.
		*/
		void IncreaseVelocity(double factor);

		/*
		* SetAcceleration() sets the object acceleration.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void SetAcceleration(pair<double, double> acceleration);

		/*
		* GetAcceleration() returns the object acceleration.
		*/
		pair<double, double> GetAcceleration();

		/*
		* GetAccelerationModule() returns the module of the acceleration.
		*/
		double GetAccelerationModule();

		/*
		* Move() moves the object position in the direction given.
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		void Move(pair<double, double> direction);

		/*
		* MoveWithConstantVelocity() moves the object position to the direction given by the velocity.
		* Every game loop updates the velocity.
		* To control the velocity using time, we can use MoveWithULM() or MoveWithUALM()
		*/
		void MoveWithConstantVelocity();

		/*
		* MoveWithULM() moves the object position to the direction given by the velocity set.
		* It receives the time as an argument.
		* It follows the ULM formula: x=x0+v0*t, where
		* x0 = the initial position
		* v0 = the initial velocity
		* t = the time given
		*/
		void MoveWithULM(double time);

		/*
		* MoveWithUALM() moves the object position to the direction given by the velocity set.
		* It receives the time as an argument.
		* It follows the UALM formula: x=x0+v0*t+0.5*a*t^2, where 
		* x0 = the initial position
		* v0 = the initial velocity
		* a = the acceleration attribute
		* t = the time given
		*/
		void MoveWithUALM(double time);

		/*
		* MoveUp() moves the object up.
		* It will move one unit of mVelocity.
		*/
		void MoveUp();

		/*
		* MoveDown() moves the object down.
		* It will move an unit of mVelocity.
		*/
		void MoveDown();

		/*
		* MoveLeft() moves the object left.
		* It will move an unit of mVelocity.
		*/
		void MoveLeft();

		/*
		* MoveRight() moves the object right.
		* It will move an unit of mVelocity.
		*/
		void MoveRight();

		/*
		* GetTop() returns the top of the object.
		* The object is supossed to have its maximum lenght in the center.
		*/
		double GetTop();

		/*
		* GetBottom() returns the bottom of the object.
		* The object is supossed to have its minimum lenght in the center.
		*/
		double GetBottom();

		/*
		* GetLeftEdge() returns the left edge of the object.
		* The object is supossed to have its minimum left-lenght in the center.
		*/
		double GetLeftEdge();

		/*
		* GetRightEdge() returns the left edge of the object.
		* The object is supossed to have its maximum right-lenght in the center.
		*/
		double GetRightEdge();

		/*
		* Each class should handle its own rendering.
		*/
		virtual void Render() {}

		/*
		* Each class should handle its own update.
		*/
		virtual void Update() {}

		/*
		* IsCollidingWith() returns true if the objects is colliding with the given object.
		* False otherwise.
		*/
		bool IsCollidingWith(shared_ptr<GameObject> gameobject);



	protected:
		/*Member variables*/

		/*
		* Object position
		* The first element represents the x-axis and the second one, the y-axis.
		*/
		pair<double, double> mPosition, mInitialPosition;

		/*
		* Object size
		* The first element represents the widht and the second one, the height.
		*/
		pair<double, double> mSize, mInitialSize;

		/*
		* Object speed.
		* It has a module and a direction.
		*/
		pair<double, double> mVelocity;

		/*
		* Object acceleration
		* It has a module and a direction.
		*/
		pair<double, double> mAcceleration;

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