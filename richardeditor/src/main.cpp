#include <iostream>
#include "richard.h"

using namespace std;

int main(void)
{
    Richard::Engine* engine = Richard::Engine::GetInstance();
    engine->Run();
    cout << "Press ENTER to continue" << endl;
    cin.ignore();
    return 0;
}