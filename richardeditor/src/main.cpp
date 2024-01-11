#include <iostream>
#include "richard/engine.h"

using namespace std;

int main(void)
{
    cout << "Hello World! I'm Richard :)" << endl;
    bool a = Richard::Initialize();
    cout << "Richard initialize result: " << a << endl;
    Richard::Shutdown();
    system("pause");
    return 0;
}