#include "rational.h"
#include <iostream>

int main() {
    Rational r1(1, 2);
    Rational r2(3, 3);
    auto r3 = r1 + r2;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << r3.normalized() << std::endl;
    
    return 0;
}
