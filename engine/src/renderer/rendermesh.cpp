#include "rendermesh.h"
#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"

namespace Richard::Subsystems::Render {
    /*Public methods*/

    RenderMesh::RenderMesh(weak_ptr<Mesh> mesh, weak_ptr<Shader> shader) {
        pMesh = mesh;
        pShader = shader;
    }

    void RenderMesh::Execute() {
        // Get Mesh and Shader pointers
        shared_ptr<Mesh> mesh = pMesh.lock();
        shared_ptr<Shader> shader = pShader.lock();
        if(!mesh || !shader) {
            Tools::Logger::Error("Shader or Mesh not available for rendering process");
            return;
        }

        // Bind
        mesh->Bind();
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
        shader->Unbind();
    }
}