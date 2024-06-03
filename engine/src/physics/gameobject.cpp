#include "gameobject.h"

#include "glm/gtc/matrix_transform.hpp"
#include <cmath>

namespace Richard::Physics {

	GameObject::GameObject(pair<double, double> position, pair<double, double> size, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader) {
		mPosition = position;
		mInitialPosition = mPosition;
		mSize = size;
		mInitialSize = mSize;
		mMesh = mesh;
		mShader = shader;
		mVelocity = make_pair(0.f, 0.f);
		mAcceleration = make_pair(0.f, 0.f);
	}

	GameObject::GameObject(pair<double, double> position, pair<double, double> size, pair<double, double> velocity, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader)
	: GameObject(position, size, mesh, shader) {
		mVelocity = velocity;
	}

	GameObject::GameObject(pair<double, double> position, pair<double, double> size, pair<double, double> velocity, pair<double, double> acceleration, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader)
	: GameObject(position, size, velocity, mesh, shader) {
		mAcceleration = acceleration;
	}

	void GameObject::SetPosition(pair<double, double> position) {
		mPosition = position;
	}

	pair<double, double> GameObject::GetPosition() {
		return mPosition;
	}

	pair<double, double> GameObject::GetInitialPosition() {
		return mInitialPosition;
	}

	void GameObject::SetSize(pair<double, double> size) {
		mSize = size;
	}

	pair<double, double> GameObject::GetSize() {
		return mSize;
	}

	pair<double, double> GameObject::GetInitialSize() {
		return mInitialSize;
	}

	void GameObject::SetVelocity(pair<double, double> speed) {
		mVelocity = speed;
	}

	pair<double, double> GameObject::GetVelocity() {
		return mVelocity;
	}

	double GameObject::GetVelocityModule()
	{
		return sqrt(pow(mVelocity.first, 2) + pow(mVelocity.second, 2));
	}

	void GameObject::IncreaseVelocity(double factor) {
		mVelocity.first *= factor;
		mVelocity.second *= factor;
	}

	void GameObject::SetAcceleration(pair<double, double> acceleration) {
		mAcceleration = acceleration;
	}

	pair<double, double> GameObject::GetAcceleration() {
		return mAcceleration;
	}

	double GameObject::GetAccelerationModule() {
		return sqrt(pow(mAcceleration.first, 2) + pow(mAcceleration.second, 2));
	}

	void GameObject::Move(pair<double, double> direction) {
		mPosition.first += direction.first;
		mPosition.second += direction.second;
	}

	void GameObject::MoveWithConstantVelocity() {
		mPosition.first += mVelocity.first;
		mPosition.second += mVelocity.second;
	}

	void GameObject::MoveWithULM(double time) {
		mPosition.first += mVelocity.first * time;
		mPosition.second += mVelocity.second * time;
	}

	void GameObject::MoveWithUALM(double time) {
		mPosition.first += mVelocity.first * time + 0.5 * mAcceleration.first * pow(time,2);
		mPosition.second += mVelocity.second * time + 0.5 * mAcceleration.second * pow(time, 2);
	}

	void GameObject::MoveUp() {
		pair <double, double> directionUp(0.f, mVelocity.second);
		Move(directionUp);
	}

	void GameObject::MoveDown() {
		pair <double, double> directionDown(0.f, -mVelocity.second);
		Move(directionDown);
	}

	void GameObject::MoveLeft() {
		pair <double, double> directionLeft(-mVelocity.first, 0.f);
		Move(directionLeft);
	}

	void GameObject::MoveRight() {
		pair <double, double> directionRight(mVelocity.first, 0.f);
		Move(directionRight);
	}

	double GameObject::GetTop() {
		return mPosition.second + (mSize.second / 2);
	}

	double GameObject::GetBottom() {
		return mPosition.second - (mSize.second / 2);
	}

	double GameObject::GetLeftEdge() {
		return mPosition.first - (mSize.first / 2);
	}

	double GameObject::GetRightEdge() {
		return mPosition.first + (mSize.first / 2);
	}

	bool GameObject::IsCollidingWith(shared_ptr<GameObject> gameobject) {
		return ((max(this->GetLeftEdge(), gameobject->GetLeftEdge()) <= min(this->GetRightEdge(), gameobject->GetRightEdge())) && 
			(max(this->GetBottom(), gameobject->GetBottom()) <= min(this->GetTop(), gameobject->GetTop())));
	}
}