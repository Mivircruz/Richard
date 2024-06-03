#pragma once

#include <memory>

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "physics/gameobject.h"

using namespace Richard;
using namespace std;

class Ball : public Physics::GameObject {
public:

	Ball(pair<double, double> position, pair<double, double> size);

	void Render() override;

	void Update() override;

	void HandleCollision(pair<double, double> collisionObjectPos, double collisionObjectHeight);

	void ChangeDirectionX();

	void ChangeDirectionY();

	void Reset();
};