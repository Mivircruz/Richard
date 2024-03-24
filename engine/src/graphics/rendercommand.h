#pragma once

/*
* Abstract class that represents a render command.
*/
namespace Richard::Graphics {
	class RenderCommand {

	public:
		/*
		* Executes the render command defined in the class
		* that implements this abstract class.
		*/
		virtual void Execute() = 0;
	};
}