#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include <memory>

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "physics/gameobject.h"

using namespace Richard;
using namespace std;

class Paddle : public Physics::GameObject {
public:

	Paddle(std::pair<double, double> position, std::pair<double, double> size, int upKey, int downKey);

	void Render() override;

	void Update() override;

private:
	int mUpKey, mDownKey;
};