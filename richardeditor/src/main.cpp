#include <iostream>
#include "richard/engine.h"

using namespace std;

int main(void)
{
    cout << "Hello World! I'm Richard :)" << endl;
    int a = Richard::Add(1,7);
    cout << "Add(1,7) result: " << a << endl;
    return 0;
}