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

        //Define the shaders
        const char *vertexShader = "#version 410 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec3 aColor;\n"
            "layout(location = 2) in vec2 aTexCoord;\n"
            "out vec3 ourColor;\n"
            "out vec2 TexCoord;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "   ourColor = aColor;\n"
            "   TexCoord = aTexCoord;\n"
            "}\0";

        const char* fragmentShader = "#version 410 core\n"
            "out vec4 FragColor;\n"
            "in vec3 ourColor;\n"
            "in vec2 TexCoord;\n"
            "uniform sampler2D ourTexture;\n"
            "void main()\n"
            "{\n"
            "  FragColor = texture(ourTexture, TexCoord);\n"
            "}\n\0";

        mShader = make_shared<Richard::Graphics::Shader>(vertexShader, fragmentShader);

        // Define the square
        float vertices[] = {
            // positions          // colors           // texture coords
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
        };

        uint32_t indices[]{
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        // Define the quad that will contain the image to load
        float textureCoodinates[] = {
            1.f, 1.f,
            1.f, 0.f,
            0.f, 0.f,
            0.f, 1.f
        };

        mMesh = make_shared<Richard::Graphics::Mesh>(&vertices[0], 4, 8, &textureCoodinates[0], &indices[0], 6);


        // Define the texture
        mTexture = make_shared<Richard::Graphics::Texture>("resources/poro.jpg", T_FILTER_LINEAR, T_WRAPPING_REPEAT);
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