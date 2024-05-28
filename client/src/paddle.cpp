#include "paddle.h"

#include "core/engine.h"
#include "graphics/rendermesh.h"

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
	: GameObject(position, size, nullptr, nullptr) {
	mMesh = make_shared<Graphics::Mesh>(&Vertices[0], 4, 3, &Indices[0], 6);
	mShader = make_shared<Graphics::Shader>("resources/shaders/paddle_vs.txt", "resources/shaders/paddle_fs.txt");
	mUpKey = upKey;
	mDownKey = downKey;
	mSpeed = 0.01f;
}

void Paddle::Render() {
	glm::mat4 model = glm::mat4(1.f);
	model = glm::translate(model, { mPosition.first, mPosition.second, 0.f });
	model = glm::scale(model, { mSize.first, mSize.second, 1.f });

	mShader->SetUniformMat4("model", model);
	auto renderCommand = make_unique<Graphics::RenderMesh>(mMesh, mShader);
	Engine::GetInstance()->GetRenderer()->Submit(move(renderCommand));
}

void Paddle::Update() {
}