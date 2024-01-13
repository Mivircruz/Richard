#include <iostream>
#include "richard/engine.h"

using namespace std;

int main(void)
{
    Richard::Engine* engine = Richard::Engine::GetInstance();
    cout << "Press ENTER to continue" << endl;
    cin.ignore();
    return 0;
}