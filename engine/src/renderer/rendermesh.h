#pragma once

#include "rendercommand.h"
#include <memory>
#include "mesh.h"
#include "shader.h"

using namespace std;

namespace Richard::Subsystems::Render {

	class RenderMesh : public RenderCommand {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object RenderMesh.
		*/
		RenderMesh(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader);

		/*
		* Execute() executes the commmand RenderMesh.
		*/
		virtual void Execute();



	private:
		/*Member variables*/

		/*
		* Pointer that points to a mesh. 
		* It's a weak pointer because the command cannot handle the lifetime of the mesh.
		*/
		weak_ptr<Mesh> pMesh;

		/*
		* Pointer that points to a shader. 
		* It's a weak pointer because the command cannot handle the lifetime of the shader.
		*/
		weak_ptr<Shader> pShader;
	};
}


