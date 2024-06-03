#include "paddle.h"

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

Paddle::Paddle(std::pair<double, double> position, std::pair<double, double> size, int upKey, int downKey)
	: GameObject(position, size, make_pair(0.f, 0.00099f), nullptr, nullptr) {
	mMesh = make_shared<Graphics::Mesh>(&Vertices[0], 4, 3, &Indices[0], 6);
	mShader = make_shared<Graphics::Shader>("resources/shaders/pong_vs.txt", "resources/shaders/pong_fs.txt");
	mUpKey = upKey;
	mDownKey = downKey;
}

void Paddle::Render() {
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

void Paddle::Update() {
	if (Input::Keyboard::IsKeyPressed(mUpKey) && GetTop() < 1.f) {
		MoveUp();
	}

	if (Input::Keyboard::IsKeyPressed(mDownKey) && GetBottom() > -1.f) {
		MoveDown();
	}
}
