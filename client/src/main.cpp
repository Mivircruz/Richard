#include "client/main.h"

#include <iostream>
#include <vector>

#include "client/application.h"
#include "core/engine.h"
#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "input/keyboard.h"
#include "physics/gameobject.h"

#include "ball.h"
#include "paddle.h"

using namespace std;

class Pong : public Richard::Application {
public:

    Pong() {
        Engine::GetInstance()->GetWindow()->SetSize(1000, 800);
    }

    void Initialize() override {
        // Background color setup
        Engine::GetInstance()->GetRenderer()->SetClearColor(2.0f / 255.0f, 97.0f / 255.0f, 53.0f / 255.0f, 1.0f);

        // Paddle creation
        pair <double, double> paddleSize(0.1, 0.3);
        pair <double, double> leftPaddlePosition(-1.f, 0.f);
        pair <double, double> rightPaddlePosition(1.f, 0.f);

        mLeftPaddle = make_shared<Paddle>(leftPaddlePosition, paddleSize, KEY_W, KEY_S);
        mRightPaddle = make_shared<Paddle>(rightPaddlePosition, paddleSize, KEY_UP, KEY_DOWN);

        // Ball creation
        mBall = make_shared<Ball>(make_pair(0.f, 0.f), make_pair(0.075f, 0.1f));
    }

    void Shutdown() override {
    }

    void Update() override {
        mBall->Update();
        mLeftPaddle->Update();
        mRightPaddle->Update();
    }

    void Render() override {
        mBall->Render();
        mLeftPaddle->Render();
        mRightPaddle->Render();

        Engine::GetInstance()->GetRenderer()->Execute();
    }

private:
    shared_ptr<Ball> mBall;
    shared_ptr<Paddle> mLeftPaddle, mRightPaddle;

    shared_ptr<Richard::Graphics::Mesh> mMesh;
    shared_ptr<Richard::Graphics::Shader> mShader;
};

Richard::Application* CreateApplication() {
    return new Pong();
}