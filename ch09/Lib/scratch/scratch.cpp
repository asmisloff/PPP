#include <iostream>
#include <string>

using namespace std;

class A {
public:
    A(string s) {
        this->s = s;
    }
    virtual string what() {
        return "from A, n = " + s;
    }
protected:
    string s;
};

class B : public A {
public:
    B(string s) : A(s) {}
    string what() {
        return "from B, n = " + s;
    }
};

int main() {
    try {
        throw B("13");
    }
    catch (A& a) {
        cout << a.what();
    }
    return 0;
}