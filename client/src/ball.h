#pragma once

#include <memory>

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "physics/gameobject.h"

using namespace Richard;
using namespace std;

class Ball : public Physics::GameObject {
public:

	Ball(std::pair<double, double> position, std::pair<double, double> size);

	void Render() override;

	void Update() override;

	void ChangeDirectionX();

	void ChangeDirectionY();
};