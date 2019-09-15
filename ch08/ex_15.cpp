#include <iostream>

using namespace std;

void f(const int i)
{
    cout << "arg = " << i;
    //cout << "++arg = " << ++i;
}

int main(int argc, char const *argv[])
{
    f(10);
    return 0;
}
