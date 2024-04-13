#include "client/main.h"

#include <iostream>

#include "client/application.h"
#include "core/engine.h"
#include "graphics/mesh.h"
#include "graphics/rendertexture.h"
#include "graphics/shader.h"
#include "graphics/texture.h"

using namespace std;

class ClientApp : public Richard::Application {
    public:
    
    void Initialize() override {
        std::cout << "ClientApp Initialize" << std::endl;

        // Define the square
        // We will define two triangles that togehter make the square
        float vertices[] = {
            0.5f,   0.5f,  0.f,
            0.5f,  -0.5f,  0.f,
            -0.5f, -0.5f,  0.f,
            -0.5f,  0.5f,  0.f
            };

        uint32_t elements[]{
            0, 3, 1, // first triangle
            1, 3, 2  // second triangle
        };

        // Define the quad that will contain the image to load
        float textureCoodinates[] = {
            1.f, 1.f,
            1.f, 0.f,
            0.f, 0.f,
            0.f, 1.f
        };

        mMesh = make_shared<Richard::Graphics::Mesh>(&vertices[0], 4, 3, &textureCoodinates[0], &elements[0], 6);

        //Define the shaders
        const char* vertexShader = R"(
            #version 410 core
            layout (location = 0) in vec3 position;
            layout (location = 1) in vec2 textureCoordinates;
            out vec3 vpos;
            out vec2 uvs;

            void main() {
                uvs = textureCoordinates;
                gl_Position = vec4(position, 1.0);
        }
        )";

        const char* fragmentShader = R"(
            #version 410 core
            out vec4 outColor;
            in vec2 uvs;
            uniform sampler2D tex;

            void main() {
                // outColor = vec4(1.0);
                outColor = texture(tex, uvs);
        }
        )";

        mShader = make_shared<Richard::Graphics::Shader>(vertexShader, fragmentShader);

        // Define the texture
        mTexture = make_shared<Richard::Graphics::Texture>("resources/container.jpg", T_FILTER_LINEAR, T_WRAPPING_REPEAT);
    }

    void Shutdown() override {
    }

    void Update() override {
    }

    void Render() override {
        auto renderCommand = make_unique<Richard::Graphics::RenderTexture>(mMesh, mShader, mTexture);
        Engine::GetInstance()->GetRenderer()->Submit(move(renderCommand));
        Engine::GetInstance()->GetRenderer()->Execute();
    }

    private:
    shared_ptr<Richard::Graphics::Mesh> mMesh;
    shared_ptr<Richard::Graphics::Shader> mShader;
    shared_ptr < Richard::Graphics::Texture> mTexture;
};

Richard::Application* CreateApplication() {
    return new ClientApp();
}