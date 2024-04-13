#pragma once

#include "rendercommand.h"
#include <memory>
#include "mesh.h"
#include "shader.h"
#include "texture.h"

using namespace std;

namespace Richard::Graphics {
    class RenderTexture : public RenderCommand {
        public:
		/*Methods*/

		/*
		* Constructor. It creates the object RenderTexture.
		*/
		RenderTexture(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader, weak_ptr<Texture> texture);

		/*
		* Execute() executes the commmand RenderTexture.
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

        /*
		* Pointer that points to a texture. 
		* It's a weak pointer because the command cannot handle the lifetime of the texture.
		*/
		weak_ptr<Texture> pTexture;
    };
}