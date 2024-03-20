#pragma once

#include "core/engine.h"
#include "application.h"

using namespace Richard;

// This method needs to be implemented in the client side.
// The idea is that the client defines the application that Richard is going to run.
// Richard is going to manage the pointer.
Application* CreateApplication();

int main(void)
{
    Application* app = CreateApplication();
    Engine::GetInstance()->Run(app);
    delete app;
    return 0;
}