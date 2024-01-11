#include "engine.h"
#include <iostream>
#include "SDL.h"

using namespace std;

namespace Richard {
    int Initialize() {
        int initSDLResult = SDL_Init(SDL_INIT_EVERYTHING);

        if(initSDLResult < 0) {
            cout << "Error initializing SDL2: " << SDL_GetError() << endl;
        } else {
            SDL_version version;
            SDL_VERSION(&version);
            cout << "SDL " << version.major << "." << version.minor << endl;
        }

        return initSDLResult;

        return 0;
    }

    void Shutdown() {
        SDL_Quit();
    }
}