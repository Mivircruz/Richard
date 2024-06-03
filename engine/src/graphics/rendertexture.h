#pragma once

#ifndef RENDERTEXTURE_H
#define RENDERTEXTURE_H

#include <memory>
#include <vector>

#include "rendercommand.h"
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
		RenderTexture(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader);

		void AddTexture(weak_ptr<Texture> texture);

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
		* Array of pointers where each one points to a texture. 
		* They are a weak pointers because the command cannot handle the lifetime of the textures.
		*/
		vector<weak_ptr<Texture>> pTextures;
    };
}

#endif