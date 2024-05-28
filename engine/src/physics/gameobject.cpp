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

	void GameObject::Move(std::pair<double, double> direction) {
		mPosition.first += direction.first;
		mPosition.second += direction.second;
	}

	void GameObject::SetSize(std::pair<double, double> size) {
		mSize = size;
	}
}