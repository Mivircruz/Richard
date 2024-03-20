#include <iostream>
#include "richard.h"

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

        mMesh = make_shared<Richard::Subsystems::Render::Mesh>();
        mMesh->Initialize(&vertices[0], 4, 3, &elements[0], 6);

        //Define the shaders
        const char* vertexShader = R"(
            #version 410 core
            layout (location = 0) in vec3 position;
            void main() {
                gl_Position = vec4(position, 1.0);
        }
        )";

        const char* fragmentShader = R"(
            #version 410 core
            out vec4 outColor;
            void main() {
                outColor = vec4(1.0);
        }
        )";

        mShader = make_shared<Richard::Subsystems::Render::Shader>();
        mShader->Initialize(vertexShader, fragmentShader);
    }

    void Shutdown() override {
        std::cout << "ClientApp Shutdown" << std::endl;
    }

    void Update() override {
        std::cout << "ClientApp Update" << std::endl;
    }

    void Render() override {
        std::cout << "ClientApp Render" << std::endl;
        auto renderCommand = make_unique<Subsystems::Render::RenderMesh>(mMesh, mShader);
        Engine::GetInstance()->GetRenderer()->Submit(move(renderCommand));
        Engine::GetInstance()->GetRenderer()->Execute();
    }

    private:
    shared_ptr<Richard::Subsystems::Render::Mesh> mMesh;
    shared_ptr<Richard::Subsystems::Render::Shader> mShader;
};

Richard::Application* CreateApplication() {
    return new ClientApp();
}