#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

int randint(int x0 = 0, int a = 16807, int m = 2147483647, int c = 0) {
    static long x = (x0 == 0) ? time(0) : x0;
    x = (abs(a * x) + c) % m;
    return x;
}

int main(int argc, const char** argv) {
    for (int i = 0; i < 10; i++)
    {
        cout << randint() << endl;
    }
    

    return 0;
}