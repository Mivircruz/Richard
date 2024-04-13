#include "rendertexture.h"
#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"

namespace Richard::Graphics {
	/*Public methods*/

	RenderTexture::RenderTexture(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader, weak_ptr<Texture> texture) {
		pMesh = mesh;
		pShader = shader;
		pTexture = texture;
	}

	void RenderTexture::Execute() {
        // Get Mesh, Texture and Shader pointers
        shared_ptr<Mesh> mesh = pMesh.lock();
        shared_ptr<Texture> texture = pTexture.lock();
        shared_ptr<Shader> shader = pShader.lock();
        if (!mesh || !texture || !shader) {
            Tools::Logger::Error("Shader or Mesh or Texture not available for rendering process");
            return;
        }

        // Bind
        mesh->Bind();
        texture->Bind();
        shader->Bind();

        // Draw
        uint32_t elementsAmount = mesh->GetElementsAmount();
        if (elementsAmount) {
            glDrawElements(GL_TRIANGLES, elementsAmount, GL_UNSIGNED_INT, 0);
        }
        else {
            glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh->GetVertexAmount()); RICHARD_CHECK_GL_ERROR;
        }

        // Unbind
        mesh->Unbind();
        texture->Unbind();
        shader->Unbind();
	}
}

