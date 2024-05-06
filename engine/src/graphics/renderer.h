#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "rendercommand.h"
#include <memory>
#include <queue>

using namespace std;

namespace Richard::Graphics {
	class Renderer {
	public:

		/*
		* Constructor. It creates the object Renderer.
		*/
		Renderer();

		/*
		* Destructor. It destroys the object.
		*/
		~Renderer();

		/*
		* Initialize() sets up the environment for the renderer to begin to receive and execute render commands.
		* It also sets the window background color to the default color: violet.
		* It returns 0 in case of success or a non-zero value otherwise.
		*/
		int Initialize();

		/*
		* Shutdown() removes from the queue all the commands that have not been executed yet.
		*/
		void Shutdown();

		/*
		* It clears the frames.
		* It also clears the command queue.
		*/
		void Clear();

		/*
		* SetClearColor() sets the color of the window backgroud.
		* Values specified by SetClearColor are clamped to the range [0,1].
		*/
		void SetClearColor(float r, float g, float b, float a);

		/*
		* Submit() adds the render command to the command queue.
		*/
		void Submit(unique_ptr<Graphics::RenderCommand> renderCommand);
		
		/*
		* Execute() executes every command in the queue.
		* It follows a FIFO order execution.
		*/
		void Execute();



	private:
		/*Member variables*/

		/*
		* Queue with all the commands that will be executed in the rendering pipeline.
		*/
		queue<unique_ptr<Graphics::RenderCommand>> mRenderCommands;
	};
}

#endif