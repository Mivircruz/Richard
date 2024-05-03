#include "renderer.h"

#include "tools/logger.h"
#include "tools/errorchecker.h"
#include "glad/glad.h"

namespace Richard::Graphics {
	/*Public methods*/

	Renderer::Renderer() {}

	Renderer::~Renderer() {}

	int Renderer::Initialize() {

		// Set the default background color
		SetClearColor(76.0f/255.0f, 0.0f/255.0f, 155.0f/255.0f, 1.0f);

		return 0;
	}

	void Renderer::Shutdown() {
		// Empty the command queue
		while (!mRenderCommands.empty()) {
			mRenderCommands.pop();
		}
	}

	void Renderer::Clear() {
		// Empty the command queue so the new frames can be fresh
		while (!mRenderCommands.empty()) {
			Tools::Logger::Warning("Non-executed commands in queue. Clean will delete them.");
			mRenderCommands.pop();
		}

		// Clears the color of the screen (color buffer) and
		// any cached information about the depth of what the window just rendered (depth buffer)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  RICHARD_CHECK_GL_ERROR;
		glClearColor(76.0f / 255.0f, 0.0f / 255.0f, 155.0f / 255.0f, 1.0f);
	}

	

	void Renderer::SetClearColor(float r, float g, float b, float a) {
		glClearColor(r, g, b, a); 
		glClear(GL_COLOR_BUFFER_BIT);  RICHARD_CHECK_GL_ERROR;
	}

	void Renderer::Submit(unique_ptr<RenderCommand> renderCommand) {
		mRenderCommands.push(move(renderCommand));
	}

	void Renderer::Execute() {
		while (!mRenderCommands.empty()) {
			auto renderCommand = move(mRenderCommands.front());
			mRenderCommands.pop();

			renderCommand->Execute();
		}
	}
}