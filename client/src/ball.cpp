#include "ball.h"

#include "core/engine.h"
#include "graphics/rendermesh.h"
#include "input/keyboard.h"

// Define mesh
static float Vertices[] = {
	// positions         
	 0.5f,  0.5f, 0.f,    // top right
	 0.5f, -0.5f, 0.f,    // bottom right
	-0.5f, -0.5f, 0.f,    // bottom left
	-0.5f,  0.5f, 0.f,    // top left 
};

static uint32_t Indices[]{
	0, 3, 1, // first triangle
	1, 3, 2  // second triangle
};

Ball::Ball(std::pair<double, double> position, std::pair<double, double> size) 
	: GameObject(position, size, make_pair(0.f, 0.f), nullptr, nullptr) {
	mMesh = make_shared<Graphics::Mesh>(&Vertices[0], 4, 3, &Indices[0], 6);
	mShader = make_shared<Graphics::Shader>("resources/shaders/pong_vs.txt", "resources/shaders/pong_fs.txt");
}

void Ball::Render() {
	// Create identity matrix
	glm::mat4 model = glm::mat4(1.f);

	// Make a tranlsation to move the object
	model = glm::translate(model, { mPosition.first, mPosition.second, 0.f });

	// Scale the matrix to fit the screen
	model = glm::scale(model, { mSize.first, mSize.second, 1.f });

	mShader->SetUniformMat4("model", model);
	auto renderCommand = make_unique<Graphics::RenderMesh>(mMesh, mShader);
	Engine::GetInstance()->GetRenderer()->Submit(move(renderCommand));
}

void Ball::Update() {
	if (Input::Keyboard::IsKeyPressed(KEY_C) && mVelocity.first == 0.f && mVelocity.second == 0.f) {
		mVelocity = make_pair(0.00035f, 0.00035f);
		return;
	}

	if ((GetTop() >= 1.f || GetBottom() <= -1.f) && (GetLeftEdge() > -1.f && GetRightEdge() < 1.f)) {
		ChangeDirectionY();
	}

	MoveWithConstantVelocity();
}

void Ball::HandleCollision(pair<double, double> collisionObjectPos, double collisionObjectHeight) {
	// Calcula la posición relativa de la pelota respecto al objeto
	double relativeIntersectY = collisionObjectPos.second + collisionObjectHeight / 2 - mPosition.second;

	// Calcula el ángulo de rebote en función de la posición de impacto en el objeto
	double normalizedRelativeIntersectionY = relativeIntersectY / (collisionObjectHeight / 2);
	double bounceAngle = normalizedRelativeIntersectionY * (3.14 / 4); // Ángulo máximo de rebote

	double xAngle;
	// Cambia la dirección de la pelota en función del ángulo de rebote
	if (mPosition.first > 0) { // Si la pelota se mueve hacia la derecha
		xAngle = -cos(bounceAngle); // Ajusta la velocidad en x con el ángulo de rebote
	}
	else { // Si la pelota se mueve hacia la izquierda
		xAngle = cos(bounceAngle); // Ajusta la velocidad en x con el ángulo de rebote
	}

	double yAngle = sin(bounceAngle);

	auto currentVelocity = GetVelocityModule();
	SetVelocity(make_pair(currentVelocity * xAngle, currentVelocity * yAngle));
}

void Ball::ChangeDirectionX() {
	mVelocity.first *= -1.f;
}

void Ball::ChangeDirectionY() {
	mVelocity.second *= -1.f;
}

void Ball::Reset() {
	SetPosition(make_pair(0.f, 0.f));
	SetVelocity(make_pair(0.f, 0.f));
}
