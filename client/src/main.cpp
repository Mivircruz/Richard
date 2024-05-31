#include "client/main.h"

#include <memory>
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

        mLeftPaddle = make_shared<Paddle>(make_pair(-1.f, 0.f), paddleSize, KEY_W, KEY_S);
        mRightPaddle = make_shared<Paddle>(make_pair(1.f, 0.f), paddleSize, KEY_UP, KEY_DOWN);

        // Ball creation
        mBall = make_shared<Ball>(make_pair(0.f, 0.f), make_pair(0.075f, 0.1f));


        Engine::GetInstance()->GetGameObjectManager()->Submit("leftPaddle", mLeftPaddle);
        Engine::GetInstance()->GetGameObjectManager()->Submit("rightPaddle", mRightPaddle);
        Engine::GetInstance()->GetGameObjectManager()->Submit("ball", mBall);
    }

    void Shutdown() override {
    }

    void Update() override {
        if (mLeftPaddle->IsCollidingHorizontallyWith(mBall) || mRightPaddle->IsCollidingHorizontallyWith(mBall)) {
            mBall->ChangeDirectionX();
        }
    }

    void Render() override {
    }

private:
    shared_ptr<Ball> mBall;
    shared_ptr<Paddle> mLeftPaddle, mRightPaddle;
};

Richard::Application* CreateApplication() {
    return new Pong();
}