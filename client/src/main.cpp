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
#include "tools/logger.h"

#include "ball.h"
#include "paddle.h"

using namespace std;

class Pong : public Richard::Application {
public:

    Pong() {
        Engine::GetInstance()->GetWindow()->SetSize(1000, 800);
        mLeftPlayerPoints = 0;
        mRightPlayerPoints = 0;
        mPaddleTouches = 0;
    }

    void Initialize() override {
        Tools::Logger::Info("Pong has started!");

        // Background color setup
        Engine::GetInstance()->GetRenderer()->SetClearColor(2.0f / 255.0f, 97.0f / 255.0f, 53.0f / 255.0f, 1.0f);

        // Paddle creation
        pair <double, double> paddleSize(0.1, 0.3);
        mLeftInitialPos = make_pair(-1.f, 0.f);
        mRightInitialPos = make_pair(1.f, 0.f);

        mLeftPaddle = make_shared<Paddle>(mLeftInitialPos, paddleSize, KEY_W, KEY_S);
        mRightPaddle = make_shared<Paddle>(mRightInitialPos, paddleSize, KEY_UP, KEY_DOWN);

        // Ball creation
        mBall = make_shared<Ball>(make_pair(0.f, 0.f), make_pair(0.075f, 0.1f));

        Engine::GetInstance()->GetGameObjectManager()->Submit("leftPaddle", mLeftPaddle);
        Engine::GetInstance()->GetGameObjectManager()->Submit("rightPaddle", mRightPaddle);
        Engine::GetInstance()->GetGameObjectManager()->Submit("ball", mBall);
    }

    void Shutdown() override {
        if (mLeftPlayerPoints == mRightPlayerPoints) {
            Tools::Logger::Info("It was a tie!");
        }
        else {
            std::string winner = (mLeftPlayerPoints < mRightPlayerPoints) ? "Right player" : "Left player";
            Tools::Logger::Info("Game has finished! The winner is: " + winner);
        }
    }

    void Update() override {
        if (Input::Keyboard::IsKeyPressed(KEY_Q)) {
            Engine::GetInstance()->Quit();
            return;
        }

        HandlePaddleCollision();

        HandleWallCollision();

        // Every three ball touches, the ball accelerates a little bit
        if(mPaddleTouches % 3 == 0 && mPaddleTouches != 0) {
            mBall->IncreaseVelocity(1.00001);
        }
    }

    void Render() override {
    }

    void HandlePaddleCollision() {
        bool isCollidingLeftPaddle = mLeftPaddle->IsCollidingWith(mBall);
        bool isCollidingRightPaddle = mRightPaddle->IsCollidingWith(mBall);

        if (!isCollidingLeftPaddle && !isCollidingRightPaddle) {
            return;
        }

        pair<double, double> position;

        if (isCollidingLeftPaddle) {
            position = mLeftPaddle->GetPosition();
        }
        else if (isCollidingRightPaddle) {
            position = mRightPaddle->GetPosition();
        }

        mBall->HandleCollision(position, mLeftPaddle->GetSize().second);
        mPaddleTouches++;
        return;
    }

    void HandleWallCollision() {
        if (mBall->GetLeftEdge() <= -1.f || mBall->GetRightEdge() >= 1.f) {
            AddPlayerPoints();
            mPaddleTouches = 0;
            mBall->Reset();
            mLeftPaddle->SetPosition(mLeftInitialPos);
            mRightPaddle->SetPosition(mRightInitialPos);
        }
    }

    void AddPlayerPoints() {
        if (mBall->GetLeftEdge() > 0) {
            mLeftPlayerPoints++;
        }
        else {
            mRightPlayerPoints++;
        }
        Tools::Logger::Info("Left player points: " + to_string(mLeftPlayerPoints));
        Tools::Logger::Info("Right player points: " + to_string(mRightPlayerPoints));
    }



private:
    shared_ptr<Ball> mBall;
    shared_ptr<Paddle> mLeftPaddle, mRightPaddle;
    pair <double, double> mLeftInitialPos, mRightInitialPos;
    int mLeftPlayerPoints, mRightPlayerPoints;
    int mPaddleTouches;
};

Richard::Application* CreateApplication() {
    return new Pong();
}