#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

class Randomizer {
public:
    Randomizer(int x0);
    void seed(int x0);
    int randint();
private:
    int state = 0;
    int a = 16807;
    int m = 2147483647;
    int c = 0;
};

Randomizer::Randomizer(int x0 = 0) {
    seed(x0);
}

void Randomizer::seed(int x0 = 0) {
    state = x0 ? x0 : time(0);
}

int Randomizer::randint() {
    if (state == 0) seed();
    state = (abs(a * state) + c) % m;
    return (unsigned int)(state/65536) % (INT_MAX + 1);
}

int rand_in_range(int a, int b, Randomizer& r) {
    if (b <= 0) {
        cerr << "b <= 0" << endl;
        return -1;
    }
    if (b <= a) {
        cerr << "b <= a" << endl;
        return -1;
    }
    int divider = b - a;
    if (divider == 1) {
        ++divider;
    }
    return r.randint() % divider;
}

int main(int argc, const char** argv) {
    Randomizer r;
    for (int i = 0; i < 100; i++)
    {
        cout << rand_in_range(0, 12, r) << ' ';
    }
    cout << endl;

    return 0;
}
