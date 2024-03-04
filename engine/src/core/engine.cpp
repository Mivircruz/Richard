#include "engine.h"
#include "constants.h"
#include "events/mouse.h"
#include "events/keyboard.h"
#include "renderer/mesh.h"
#include "renderer/rendermesh.h"
#include "renderer/shader.h"
#include "SDL.h"
#include <iostream>
#include <string>

using namespace std;

namespace Richard {
    /*Public methods*/

    Engine* Engine::GetInstance() {
        if (!Instance) {
            Instance = new Engine();
        }

        return Instance;
    }

    Subsystems::Renderer* Engine::GetRenderer() {
        return &mRenderer;
    }

    void Engine::Run() {
        // Initialize all the managers.
        if (Initialize() < 0) {
            Tools::Logger::Error("Error running game loop");
            return;
        }

        // Scope the code so the mesh pointer and the shader pointer destruct themselves
        // when they reach the end of the scope
        {
            //////////////////////
            // Code added to test the rendering pipeline
            // It's going to draw a triangle

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

            shared_ptr<Subsystems::Render::Mesh> mesh = make_shared<Subsystems::Render::Mesh>();
            mesh->Initialize(&vertices[0], 4, 3, &elements[0], 6);

            int eventType = EVENT_DEFAULT;

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

            shared_ptr<Subsystems::Render::Shader> shader = make_shared<Subsystems::Render::Shader>();
            shader->Initialize(vertexShader, fragmentShader);

            //////////////////////

            // Start game loop.
            while (!eventType) {
                eventType = mWindow.HandleEvents();

                mWindow.BeginRender();

                //////////////////////
                // Code added to test the rendering pipeline

                auto renderCommand = make_unique<Subsystems::Render::RenderMesh>(mesh, shader);
                mRenderer.Submit(move(renderCommand));
                mRenderer.Execute();

                //////////////////////

                mWindow.EndRender();
            }
        }

        // Shutdown all the managers and quit SDL2
        Shutdown();
    }



    /*Private methods and member variables*/

    // Initialize the pointer that will point to the instance class
    Engine* Engine::Instance = nullptr;

    int Engine::Initialize() {
        // Logger initialization
        Tools::Logger::Initialize();

        // SDL initialization
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            Tools::Logger::Error("Error initializing SDL2: " + string(SDL_GetError()));
            return E_INTIALIZE_SDL_FAIL;
        }
        SDL_version version;
        SDL_VERSION(&version);
        Tools::Logger::Info("SDL " + to_string(version.major) + "." + to_string(version.minor));

        // Window Initialization
        if (mWindow.Initialize() < 0) {
            Tools::Logger::Error("Error initializing Window Manager. Shutting down engine.");
            Shutdown(); // In case of an error, we need to clean up the SDL initialization
            return E_INTIALIZE_WINDOW_FAIL;
        }

        // Periphericals Initialization
        Events::Periphericals::Mouse::Initialize();
        Events::Periphericals::Keyboard::Initialize();

        // Renderer initialization
        mRenderer.Initialize();

        return E_INTIALIZE_OK;
    }

    void Engine::Shutdown() {
        //Shutdown systems in reverse order
        mRenderer.Shutdown();
        mWindow.Shutdown();
        SDL_Quit();
        Tools::Logger::Shutdown();
    }
}