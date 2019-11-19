#include "rational.h"
#include <iostream>
#include <string>

using namespace std;

#define print(var) _print(#var, (var))
void _print(string r_name, const Rational& r)
{
    cout << r_name << " = " << r 
         << "(num = " << r.numerator()
         << ", den = " << r.denominator()
         << ')' << endl;
}

int main() {
    Rational r1(1, 2);
    Rational r2(3, -5);
    Rational r3(6, -10);
    
    print(r1);
    print(r2);
    print(r3);
    print(r2 + r1);
    print(r2 - r1);
    print(r1 * r2);
    print(r1 / r2);
    cout << "r1 == r2 -> " << ((r1 == r2) ? "true" : "false") << endl;
    cout << "r2 == r3 -> " << ((r3 == r2) ? "true" : "false") << endl;
    Rational r4;
    cout << endl << "newly created r4: ";
    print(r4);
    print(((r4 = r1) = r2));
    print(r1);
    
    return 0;
}
