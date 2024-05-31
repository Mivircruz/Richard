#include "gameobject.h"

#include "glm/gtc/matrix_transform.hpp"

namespace Richard::Physics {

	GameObject::GameObject(std::pair<double, double> position, std::pair<double, double> size, shared_ptr<Graphics::Mesh> mesh, shared_ptr<Graphics::Shader> shader) {
		mPosition = position;
		mSize = size;
		mMesh = mesh;
		mShader = shader;
	}

	void GameObject::SetPosition(std::pair<double, double> position) {
		mPosition = position;
	}

	void GameObject::SetSize(std::pair<double, double> size) {
		mSize = size;
	}
	void GameObject::SetVelocity(std::pair<double, double> speed) {
		mSpeed = speed;
	}

	void GameObject::Move(std::pair<double, double> direction) {
		mPosition.first += direction.first;
		mPosition.second += direction.second;
	}

	void GameObject::MoveWithConstantVelocity() {
		mPosition.first += mSpeed.first;
		mPosition.second += mSpeed.second;
	}

	void GameObject::MoveUp() {
		pair <double, double> directionUp(0.f, mSpeed.second);
		Move(directionUp);
	}

	void GameObject::MoveDown() {
		pair <double, double> directionDown(0.f, -mSpeed.second);
		Move(directionDown);
	}

	void GameObject::MoveLeft() {
		pair <double, double> directionLeft(-mSpeed.first, 0.f);
		Move(directionLeft);
	}

	void GameObject::MoveRight() {
		pair <double, double> directionRight(mSpeed.first, 0.f);
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