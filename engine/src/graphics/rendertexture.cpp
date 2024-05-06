#include "rendertexture.h"
#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"

namespace Richard::Graphics {
	/*Public methods*/

	RenderTexture::RenderTexture(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader) {
		pMesh = mesh;
		pShader = shader;
	}

    void RenderTexture::AddTexture(weak_ptr<Texture> texture) {
        pTextures.push_back(texture);
    }

    void RenderTexture::Execute() {
        // Get Mesh, Texture and Shader pointers
        shared_ptr<Mesh> mesh = pMesh.lock();

        shared_ptr<Texture> texture;
        vector<shared_ptr<Texture>> textures;
        for (int i = 0; i < pTextures.size(); i++) {
            texture = pTextures.at(i).lock();
            if (!texture) {
                Tools::Logger::Error("Texture not available for rendering process");
                return;
            }
            textures.push_back(texture);
        }

        shared_ptr<Shader> shader = pShader.lock();
        if (!mesh || !shader) {
            Tools::Logger::Error("Shader or Mesh not available for rendering process");
            return;
        }

        // Bind
        int i = 0;
        for (auto iterator = textures.begin(); iterator != textures.end(); ++iterator) {
            glActiveTexture(GL_TEXTURE0 + i);
            iterator->get()->Bind();
            i++;
        }

        shader->Bind();
        mesh->Bind();

        // Draw
        glDrawElements(GL_TRIANGLES, mesh->GetIndexAmount(), GL_UNSIGNED_INT, 0);
	}
}

